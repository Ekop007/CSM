#include "calculator.h"

Calculator::Calculator()
{

}

void Calculator::run()
{
    double fn = calculation_params_ptr->frequency[0];
    double fk = calculation_params_ptr->frequency[1];
    double df = calculation_params_ptr->frequency[2];
    size_t step = 0;
    auto condition = [&fn, &fk, &step](size_t response) -> bool
    {
        switch (response)
        {
            case 0:
            {
                return (step < 1);
                break;
            }
            case 1:
            {
                return (fn <= fk);
                break;
            }
            default:
            {
                return (fn <= fk);
                break;
            }
        }
    };
    auto size_function = [&fn, &fk, &df](size_t response) -> size_t
    {
        size_t size = 0;
        switch (response)
        {
            case 2:
            {
                size = static_cast<size_t>(log(fk / fn) / log(df)) + 2;
                break;
            }
            case 1:
            {
                size = static_cast<size_t>((fk - fn) / df) + 2;
                break;
            }
            default:
            {
                size = 2;
                break;
            }
        }
        return size;
    };
    kum.resize(size_function(calculation_params_ptr->flag_frequency_response));
    kua.resize(size_function(calculation_params_ptr->flag_frequency_response));
    rim.resize(size_function(calculation_params_ptr->flag_frequency_response));
    ria.resize(size_function(calculation_params_ptr->flag_frequency_response));
    while (condition(calculation_params_ptr->flag_frequency_response))
    {
        complex s(0, 2.0 * M_PI * fn);
        form_D(s);
        form_S();
        if (calculation_params_ptr->in_nodes[0] == 0 && calculation_params_ptr->in_nodes[1] == 1
                && calculation_params_ptr->out_nodes[0] == 0 && calculation_params_ptr->out_nodes[1] == 2)
        {
            st();
            sf1(step);
        }
        else
        {
            gauss_C();
            sf2(step);
        }
        switch (calculation_params_ptr->flag_frequency_response)
        {
            case 2:
            {
                fn *= df;
                break;
            }
            case 1:
            {
                fn += df;
                break;
            }
            default:
            {
                break;
            }
        }
        ++step;
    }

}

void Calculator::form_D(const complex &s)
{
    using lamda_func = complex (*)(double val1, double val2, const complex &val3);
    auto R_func = [](double val1, double val2, const complex &) -> complex
    {
        return complex(val1 / val2);
    };

    auto L_func = [](double val1, double val2, const complex &val3) -> complex
    {
        return (val1 * val2 * val3);
    };

    auto C_func = [](double val1, double val2, const complex &val3) -> complex
    {
        return (val1 / (val3 * val2));
    };

    auto main_func = [](MatrixT<complex> &W, const MatrixT<double> &value, const MatrixT<int> &node, const size_t &count, const complex &s, lamda_func lmd)
    {
        size_t i, j;
        double g;
        for (size_t k = 1; k <= count; ++k)
        {
            for (size_t t = 0; t < 2; ++t)
            {
                i = node[k][t];
                if (i == 0)
                {
                    continue;
                }
                for (size_t m = 0; m < 2; ++m)
                {
                    j = node[k][m];
                    if (j == 0)
                    {
                        continue;
                    }
                    g = 1.0 * (1 - 2 * t) * (1 - 2 * m);
                    W[i][j] += lmd(g, value[k][0], s);
                }
            }
        }
    };
    main_func(W, elements_params_ptr->valueR, elements_params_ptr->nodeR, scheme_params_ptr->resistors, s, R_func);
    main_func(W, elements_params_ptr->valueL, elements_params_ptr->nodeL, scheme_params_ptr->inductances, s, L_func);
    main_func(W, elements_params_ptr->valueC, elements_params_ptr->nodeC, scheme_params_ptr->capasitors, s, C_func);

}

void Calculator::form_IU()
{
    size_t i, j;
    double g;
    for (size_t k = 1; k <= scheme_params_ptr->resistors; ++k)
    {
        for (size_t t = 0; t < 2; ++t)
        {
            i = elements_params_ptr->nodeR[k][t];
            if (i == 0)
            {
                continue;
            }
            for (size_t m = 0; m < 2; ++m)
            {
                j = elements_params_ptr->nodeR[k][m];
                if (j == 0)
                {
                    continue;
                }
                g = 1.0 * (5 - 2 * t) * (1 - 2 * m);
                W[i][j] += g * elements_params_ptr->valueR[k][0];
            }
        }
    }

}

void Calculator::setSizeW()
{
    size_t size = 0;
    size += scheme_params_ptr->node_count + 1;
    W.resize(size);
}

void Calculator::setSchemeParams(std::shared_ptr<SchemeParams> &ptr)
{
    scheme_params_ptr = ptr;
}

void Calculator::setElemetsParams(std::shared_ptr<ElementsParams> &ptr)
{
    elements_params_ptr = ptr;
}

void Calculator::setCalculationParams(std::shared_ptr<CalculationParams> &ptr)
{
    calculation_params_ptr = ptr;
}

void Calculator::gauss_C()
{
    size_t i, j, k, l;
    complex c;
    complex d;
    complex t;
    complex cn;
    for (k = 1; k < scheme_params_ptr->node_count; ++k)
    {
        l = k;
        for (i = k + 1; i <= scheme_params_ptr->node_count; ++i)
        {
            if (abs(W[i][k]) > abs(W[l][k]))
            {
                l = i;
            }
        }
        if (l != k)
        {
            for (j = 0; j <= scheme_params_ptr->node_count; ++j)
            {
                if (j == 0 || j >= k)
                {
                    swap(W[k][j], W[l][j]);
                }
            }
         }
        d = 1.0 / W[k][k];
        for (i = k + 1; i <= scheme_params_ptr->node_count; ++i)
        {
            if (W[i][k] == cn)
            {
                continue;
            }
            c = W[i][k] * d;
            for (j = k + 1; j <= scheme_params_ptr->node_count; ++j)
            {
                if (W[k][j] != cn)
                {
                    W[i][j] = W[i][j] - c * W[k][j];
                }
            }
            if (W[k][0] != cn)
            {
                W[i][0] = W[i][0] - c * W[k][0];
            }

        }
        W[0][scheme_params_ptr->node_count] = (-W[scheme_params_ptr->node_count][0]) / W[scheme_params_ptr->node_count][scheme_params_ptr->node_count];
        for (i = scheme_params_ptr->node_count - 1; i > 0; --i)
        {
            t = W[i][0];
            for (j = i + 1; j <= scheme_params_ptr->node_count; ++j)
            {
                t = t + W[i][j] * W[0][j];
            }
            W[0][i] = -t / W[i][i];
        }
    }
}

void Calculator::st()
{
    size_t i, j, k, l;
    complex c;
    complex t;
    complex cn;
    double g;
    for (k = scheme_params_ptr->node_count; k > 2; --k)
    {
        l = k;
        g = 0.001;
        while (abs(W[l][k]) <= g)
        {
            l -= 1;
            if (l == 2)
            {
                l = k;
                g *= 0.1;
            }
        }
        if (l != k)
        {
            for (j = k; j <= scheme_params_ptr->node_count; ++j)
            {
                swap(W[k][j], W[l][j]);
            }
        }
        for (i = k - 1; i > 0; --i)
        {
            if (W[i][k] == cn)
            {
                continue;
            }
            c = W[i][k] / W[k][k];
            for (j = 1; j < k; ++j)
            {
                if (W[k][j] != cn)
                {
                    W[i][j] = W[i][j] - c * W[k][j];
                }
            }
        }
    }
}

void Calculator::sf1(size_t step)
{
    complex ku = -W[2][1] / W[2][2];
    complex d = W[1][1] * W[2][2] - W[2][1] * W[1][2];
    complex ri = W[2][2] / d;
    complex ro = W[1][1] / d;
    kum[step] = abs(ku);
    kua[step] = arg(ku) * 180 / M_PI;
    rim[step] = abs(ri);
    ria[step] = arg(ri) * 180 / M_PI;
    rom[step] = abs(ro);
    roa[step] = abs(ro) * 180 / M_PI;
}

void Calculator::sf2(size_t step)
{
    complex ri = W[0][calculation_params_ptr->in_nodes[1]] - W[0][calculation_params_ptr->in_nodes[0]];
    complex ku = (W[0][calculation_params_ptr->out_nodes[1]] - W[0][calculation_params_ptr->out_nodes[0]]) / ri;
    kum[step] = abs(ku);
    kua[step] = arg(ku) * 180 / M_PI;
    rim[step] = abs(ri);
    ria[step] = arg(ri) * 180 / M_PI;
}
