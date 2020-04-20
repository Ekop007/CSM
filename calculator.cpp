#include "calculator.h"

Calculator::Calculator() : n_(0)
{

}

void Calculator::calculateMatrix()
{
    setSizeW();
    W.setAllValue(complex(0, 0));
    n_ = scheme_params_ptr->node_count;
    complex s(0, 2.0 * M_PI * 0);
    form_D(s);
    form_II(s);
    form_UU(s);
    form_IU(s);
    form_UI(s);
    form_OU(s);
    form_PerfTr();
    form_S();
}

void Calculator::run()
{
    double fn = calculation_params_ptr->frequency[0];
    double fk = calculation_params_ptr->frequency[1];
    double df = calculation_params_ptr->frequency[2];
    size_t step = 0;
    auto condition = [&fn, &fk, &step](size_t response) -> bool
    {
        if (!response)
        {
           return (step < 1);
        }
        else
        {
            return (fn <= fk);
        }
    };
    auto size_function = [&fn, &fk, &df](size_t response) -> size_t
    {
        size_t size = 0;
        switch (response)
        {
            case 2:
            {
                size = static_cast<size_t>(log(fk / fn) / log(df)) + 1;
                break;
            }
            case 1:
            {
                size = static_cast<size_t>((fk - fn) / df) + 1;
                break;
            }
            default:
            {
                size = 1;
                break;
            }
        }
        return size;
    };
    setSizeW();
    kum.resize(size_function(calculation_params_ptr->flag_frequency_response));
    kua.resize(size_function(calculation_params_ptr->flag_frequency_response));
    rim.resize(size_function(calculation_params_ptr->flag_frequency_response));
    ria.resize(size_function(calculation_params_ptr->flag_frequency_response));
    rom.resize(size_function(calculation_params_ptr->flag_frequency_response));
    roa.resize(size_function(calculation_params_ptr->flag_frequency_response));
    f_.resize(size_function(calculation_params_ptr->flag_frequency_response));
    while (condition(calculation_params_ptr->flag_frequency_response))
    {
        W.setAllValue(complex(0, 0));
        n_ = scheme_params_ptr->node_count;
        f_[step] = fn;
        complex s(0, 2.0 * M_PI * fn);
        form_D(s);
        form_II(s);
        form_UU(s);
        form_IU(s);
        form_UI(s);
        form_OU(s);
        form_PerfTr();
        form_S();
        if (calculation_params_ptr->in_nodes[0] == 1 && calculation_params_ptr->in_nodes[1] == 0
                && calculation_params_ptr->out_nodes[0] == 2 && calculation_params_ptr->out_nodes[1] == 0)
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

void Calculator::form_D(const complex &s)
{
    using lamda_func = complex (*)(double val1, double val2, const complex &val3);
    auto R_func = [](double val1, double val2, const complex &) -> complex
    {
        return complex(val1 / val2);
    };

    auto L_func = [](double val1, double val2, const complex &val3) -> complex
    {
        return complex(val1 * val2 * val3);
    };

    auto C_func = [](double val1, double val2, const complex &val3) -> complex
    {
        return complex(val1 / (val3 * val2));
    };

    auto main_func = [](MatrixT<complex> &W, const MatrixT<double> &value, const MatrixT<int> &node, const size_t &count, const complex &s, lamda_func lmd)
    {
        size_t i, j;
        double g(0);
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
                    long t1(t), t2(m);
                    g = (1 - 2 * t1) * (1 - 2 * t2);
                    auto testval = lmd(g, value[k][0], s);
                    W[i][j] += testval;
                }
            }
        }
    };
    main_func(W, elements_params_ptr->valueR, elements_params_ptr->nodeR, scheme_params_ptr->resistors, s, R_func);
    main_func(W, elements_params_ptr->valueL, elements_params_ptr->nodeL, scheme_params_ptr->inductances, s, L_func);
    main_func(W, elements_params_ptr->valueC, elements_params_ptr->nodeC, scheme_params_ptr->capasitors, s, C_func);
}

void Calculator::form_OU(const complex &s)
{
    complex cn(0, 0);
    MatrixT<complex> y(5, 5);
    complex ys(0, 0);

    MatrixT<size_t> in_d(2, 2);
    in_d[0] = {1, 2};
    in_d[1] = {3, 4};
    size_t in_ju[4] = {1, 2, 4, 3};
    long long i, j, g, ii, jj, l, m;
    for (size_t kou = 1; kou <= scheme_params_ptr->oper_amplifiers; kou++)
    {
        for (i = 1; i <= 4; i++)
        {
            for (j = 1; j <= 4; j++)
            {
                y[i][j] = cn;
            }
        }

        for (int k = 0; k <= 1; k++)
        {
            for (l = 0; l <= 1; l++)
            {
                i = in_d[k][l];
                for (m = 0; m <= 1; m++)
                {
                    j = in_d[k][m];
                    g = (1 - 2 * l) * (1 - 2 * m);
                    y[i][j] += g / elements_params_ptr->valueOperAmp[kou][k];
                }
            }
        }

        ys = elements_params_ptr->valueOperAmp[kou][2] /
                (1 + s * 0.16 * elements_params_ptr->valueOperAmp[kou][2] / elements_params_ptr->valueOperAmp[kou][3]) /
                elements_params_ptr->valueOperAmp[kou][1];
        for (l = 2; l <= 3; l++)
        {
            i = in_ju[l];
            for (m = 0; m <= 1; m++)
            {
                j = in_ju[m];
                g = (1 - 2 * m) * (5 - 2 * l);
                y[i][j] += g * ys;
            }
        }

        for (i = 1; i <= 4; i++)
        {
            ii = elements_params_ptr->nodeOperAmp[kou][i];
            if (ii == 0) continue;
            for (j = 1; j <= 4; j++)
            {
                jj = elements_params_ptr->nodeOperAmp[kou][j];
                if (jj == 0) continue;
                W[ii][jj] += y[i][j];
            }
        }
     }

}

void Calculator::form_PerfTr()
{
    size_t i, j;
    long long g;
    for(size_t ktri=1;ktri<=scheme_params_ptr->perfect_transformer;ktri++)
    {
        i = n_ + ktri;
        for(int m=0;m<=3;m++)
        {
            j = elements_params_ptr->nodePerfectTransformer[ktri][m];
            if(j==0) continue;
            if(m<2)
            {
                g=1-2*m;
                W[i][j] += g*elements_params_ptr->valuePerfectTransformer[ktri][0];
                W[j][i] -= g*elements_params_ptr->valuePerfectTransformer[ktri][0];
            }
            else
            {
                g = 5-2*m;
                W[i][j]-=g;
                W[j][i]+=g;
            }
         }
    }
    n_ += scheme_params_ptr->perfect_transformer;
}

void Calculator::form_IU(const complex &s)
{
    complex ys;
    size_t i, j;
    long long g;
    for(size_t kju=1; kju <= scheme_params_ptr->itun; kju++)
    {
        ys = elements_params_ptr->valueITUN[kju][0]*(1+s*elements_params_ptr->valueITUN[kju][1])/(1+s*elements_params_ptr->valueITUN[kju][2]);
        for(size_t l = 2; l <= 3; l++)
        {
            i = elements_params_ptr->nodeITUN[kju][l];
            if(i==0) continue;
            for (int m = 0; m <= 1; m++)
            {
                 j = elements_params_ptr->nodeITUN[kju][m];
                 if(j==0) continue;
                 g = (5-2*l) * (1-2*m);
                 W[i][j] += g*ys;
             }
        }

    }

}

void Calculator::form_UU(const complex &s)
{
    complex ms;
    size_t i,j;
    long long g;
    for(size_t keu=1; keu<=scheme_params_ptr->inun; keu++)
    {
        ms = elements_params_ptr->valueINUN[keu][0]*(1.+s*elements_params_ptr->valueINUN[keu][1])/(1.+s*elements_params_ptr->valueINUN[keu][2]);
        i = n_+keu;
        for(int m=0;m<=3;m++)
        {
            j=elements_params_ptr->nodeINUN[keu][m];
            if(j==0) continue;
            if(m<2)
            {
                g=1-2*m;
                W[i][j]+=g*ms;
            }
            else
            {
                g=5-2*m;
                W[i][j]-=g;
                W[j][i]+=g;
            }
        }
    }
    n_ += scheme_params_ptr->inun;
}

void Calculator::form_II(const complex &s)
{
    complex ms;
    size_t i,j;
    long long g;
    for(size_t keu=1; keu<=scheme_params_ptr->inun; keu++)
    {
        ms = elements_params_ptr->valueINUN[keu][0]*(1.+s*elements_params_ptr->valueINUN[keu][1])/(1.+s*elements_params_ptr->valueINUN[keu][2]);
        i = n_+keu;
        for(int m=0;m<=3;m++)
        {
            j=elements_params_ptr->nodeINUN[keu][m];
            if(j==0) continue;
            if(m>1)
            {
                g=5-2*m;
                W[j][i]+=g*ms;
            }
            else
            {
                g=1-2*m;
                W[i][j]-=g;
                W[j][i]+=g;
            }
        }
    }
    n_ += scheme_params_ptr->inun;
}

void Calculator::form_UI(const complex &s)
{
    complex ms;
    size_t i,j, k;
    long long g;
    for(size_t keu=1; keu<=scheme_params_ptr->inun; keu++)
    {
        ms = elements_params_ptr->valueINUN[keu][0]*(1.+s*elements_params_ptr->valueINUN[keu][1])/(1.+s*elements_params_ptr->valueINUN[keu][2]);
        i = n_+keu;
        k = i + keu<=scheme_params_ptr->inun;
        for(int m=0;m<=3;m++)
        {
            j=elements_params_ptr->nodeINUN[keu][m];
            if(j==0) continue;
            if(m<2)
            {
                g=1-2*m;
                W[i][j]+=g;
                W[j][i]+=g;
            }
            else
            {
                g=5-2*m;
                W[k][j]+=g;
                W[j][k]+=g;
            }
        }
        W[k][i] += ms;
    }
    n_ += 2 * scheme_params_ptr->inun;

}

void Calculator::setSizeW()
{
    size_t size = 0;
    size += scheme_params_ptr->node_count + 1;
    size += scheme_params_ptr->inun;
    size += scheme_params_ptr->itut;
    size += 2 * scheme_params_ptr->inut;
    size += 2 * scheme_params_ptr->transformers;
    size += scheme_params_ptr->perf_transistors;
    W.resize(size);
}


void Calculator::run1()
{

}

void Calculator::form1_D()
{
    auto main_func = [this](const MatrixT<double> &value, const MatrixT<int> &node, const size_t &count, char c)
    {
        size_t i, j;
        double g;
        if (c == 'L')
        {
            for (size_t k = 1; k <= count; ++k)
            {
                i = scheme_params_ptr->node_count + k;
                B[i][i] = value[k][0];
                for (size_t m = 0; m < 2; ++m)
                {
                    j = node[k][m];
                    if (j == 0)
                    {
                        continue;
                    }
                    g = 1 - 2 * m;
                    A[i][j] -= g;
                    A[j][i] += g;
                }
            }

            n_ += count;
        }
        else
        {
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
                        if (c == 'R')
                        {
                            A[i][j] += g / value[k][0];
                        }
                        else if (c == 'C')
                        {
                            B[i][j] += g * value[k][0];
                        }
                    }
                }
            }
        }
    };
    main_func(elements_params_ptr->valueR, elements_params_ptr->nodeR, scheme_params_ptr->resistors, 'R');
    main_func(elements_params_ptr->valueL, elements_params_ptr->nodeL, scheme_params_ptr->inductances, 'L');
    main_func(elements_params_ptr->valueC, elements_params_ptr->nodeC, scheme_params_ptr->capasitors, 'C');
}

void Calculator::form1_IU()
{
    long long i, j, g;
    for(size_t kju=1; kju <= scheme_params_ptr->itun; kju++)
    {
        i = n_ + kju;
        A[i][i] = 1;
        B[i][i] = elements_params_ptr->valueITUN[kju][2];
        for(int m=0;m<=3;m++)
        {
            j = elements_params_ptr->nodeITUN[kju][m];
            if(j == 0) continue;
            if( m < 2)
            {
                g=1-2*m;
                A[i][j]-= g*elements_params_ptr->valueITUN[kju][0];
                B[i][j]-= g*elements_params_ptr->valueITUN[kju][0]*elements_params_ptr->valueITUN[kju][1];
            }
            else
            {
                g=5-2*m;
                A[j][i]+=g;
            }
        }
   }
    n_ += scheme_params_ptr->itun;
}

void Calculator::form1_UU()
{
    size_t i,j;
    long long g;
    for(size_t keu = 1; keu <= scheme_params_ptr->inun; keu++)
    {
        i = n_ + keu;
        for(size_t m=0; m<=3; m++)
        {
            j = elements_params_ptr->valueINUN[keu][m];
            if(j==0) continue;
            if(m < 2)
            {
                g=1-2*m;
                A[i][j] += g * elements_params_ptr->valueINUN[keu][0];
                B[i][j] += g * elements_params_ptr->valueINUN[keu][0] * elements_params_ptr->valueINUN[keu][1];
            }
           else
            {
                g=5-2*m;
                A[i][j]-=g;
                A[j][i]+=g;
                B[i][j]-=g * elements_params_ptr->valueINUN[keu][2];
            }
        }
    }
    n_ += scheme_params_ptr->inun;
}

void Calculator::form1_II()
{

}

void Calculator::form1_UI()
{

}

void Calculator::form_S()
{
    if (calculation_params_ptr->in_nodes[0] != 0) // +
    {
       W[calculation_params_ptr->in_nodes[0]][0] = complex(-1, 0);
    }
    if (calculation_params_ptr->in_nodes[1] != 0) // -
    {
       W[calculation_params_ptr->in_nodes[0]][0] = complex(1, 0);
    }
}

void Calculator::setSizeW1()
{
    size_t size = 0;
    size += scheme_params_ptr->node_count + 1;
    size += scheme_params_ptr->inductances;
    size += scheme_params_ptr->itun;
    size += scheme_params_ptr->inun;
    size += scheme_params_ptr->itun;
    size += scheme_params_ptr->itun;
    size += scheme_params_ptr->itun;
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
