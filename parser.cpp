#include<bits/stdc++.h>

using namespace std;

char keyword[50][15] = {"void", "main", "extern", "enum", "switch", "case", "continue", "break",
                        "goto", "if", "else", "struct", "register", "return", "union", "typedef","printf",
                        "signed", "unsigned", "static", "volatile", "default", "const", "sizeof", "swap"};

char datatype[50][15] = {"auto", "int", "long", "float", "double", "char", "string"};
char loop[50][15] = {"for", "while", "do"};
char comparisonOperator[10][3] = {"==", ">=", "<=", "!=", ">", "<"};
char preprocessor[] = {"#"};

int keywordValidation(char c[])
{
    int x = 0;
    for(int i = 0; i < 30; i++)
    {
        if (strcmp(keyword[i], c) == 0)
        {
            x = 1;
            break;
        }
    }
    return x;
}

int datatypeValidation(char c[])
{
    int x = 0;
    for(int i = 0; i < 8 ; i++)
    {
        if(strcmp(datatype[i],c) == 0)
        {
            x = 1;
            break;
        }
    }
    return x;
}

int loopValidation(char c[])
{
    int x = 0;
    for(int i = 0; i < 3 ; i++)
    {
        if(strcmp(loop[i],c) == 0)
        {
            x = 1;
            break;
        }
    }
    return x;
}

int ConValidation(char c[])
{
    int x = 0;
    for(int i = 0; i < 3 ; i++)
    {
        if(strcmp(comparisonOperator[i],c) == 0)
        {
            x = 1;
            break;
        }
    }
    return x;
}

int main()
{
    cout << endl;

    ifstream fin;
    char file_name[100], a[50], b[50], c[20], temp[15], ifarr[50], ifarr2[50], elsearr[50],
    forarr[50], whilearr[50];
    char x, y, z;

    cout << "Please Enter File Name: ";
    cin.getline(file_name, 100);

    fin.open(file_name);

    set<string> identifiers;
    set < pair <string , string > > id_dt;

    if(!fin.is_open()){
        cout << "Invalid" << endl;
        return 0;
    }

    cout << endl << endl;
    cout << "Tokenization:" << endl<<endl;
    cout << "--------------------------------------------------------" << endl;
    cout << "      Token      ->               Token Type            " << endl;
    cout << "--------------------------------------------------------" << endl;

    int op = 0, ao = 0, j = 0, n = 0, flag = 0, line = 0, iff1 = 0, iff2 = 0, forf = 0, ea = 0,
    dq = 0, sq = 0, whilef = 0, ia = 0, ia2 = 0, wa= 0, fa = 0, sc = 0, pn = 0, cb = 0, sb = 0,
    icompf = 0, wcompf = 0, idf = 0;

    while(!fin.eof())
    {
        x = fin.get();

        if(x == '\n')
        {
            line++;

            cout << endl;
            if(y == '\n' && x == '\n')
            {
                y = ';';
            }

            if(y != ';')
            {
                cout << setw(25) << "Semicolon missing(At Line: " << line << ")" << endl << endl;
            }
        }

        y = x;

        if(iff2 == 1 || whilef == 1)
        {
            ifarr2[ia2++] = x;

            if(x == ')')
            {
                char *t = strtok(ifarr2, " ");
                while (t != NULL)
                {
                    if(*t == '>' || *t == '<')
                    {
                        icompf++;
                    }
                    if(ConValidation(t) == 1)
                    {
                        icompf++;
                    }
                    t = strtok(NULL, " ");
                }
                if(icompf == 0)
                {
                    cout << endl;
                    cout << setw(20) << "-> Condition Error(At Line:" << line+1 << ")" << endl;
                    cout << endl;
                }
                ia2 = 0;
                iff2 = 0;
                whilef = 0;
                icompf = 0;
            }
            y = ';';
        }

        ///Checking Semicolon in for
        if(forf == 1)
        {
            if(x == ';')
            {
                sc++;
            }
            if(x == ')' && sc == 2)
            {
                fa = 0;
                sc = 0;
                forf = 0;
                y = ';';
            }

            else if(x == ')' && sc != 2)
            {
                cout << endl;
                cout << setw(30) << "Error!! semicolon missing in for(At Line: " << line+1 << ") " << endl;
                cout << endl;
                fa = 0;
                sc = 0;
                forf = 0;
                y = ';';
            }
        }

        if(x == '=' || x == '>' || x == '<' || x == '!' || x == '&' || x == '|')
        {
            b[op++] = x;
        }
        if(((x >= 97 && x <= 122) || (x >= 65 && x <= 90) || (x >= 48 && x <= 57) || x == ' ' ) && (op != 0))
        {
            b[op] = '\0';
            op = 0;
            strcpy(a, b);

            if(strcmp(a,"=") == 0)
            {
                cout << setw(10) << a << setw(35) << " -> Assignment Operator" << endl;
            }

            else if(strcmp(a,"!") == 0)
            {
                cout << setw(10) << a << setw(35) << " -> Logical Not Operator" << endl;
            }

            else if(strcmp(a,"!=") == 0)
            {
                cout << setw(10) << a << setw(35) << " -> Comparison Operator(Not Equal)" << endl;
            }

            else if(strcmp(a,"==") == 0)
            {
                cout << setw(10) << a << setw(35) << " -> Comparison Operator(Equal)" << endl;
            }

            else if(strcmp(a,">=") == 0)
            {
                cout << setw(10) << a << setw(35) << " -> Comparison Operator(Greater than or Equal)" << endl;
            }

            else if(strcmp(a,"<=") == 0)
            {
                cout << setw(10) << a << setw(35) << " -> Comparison Operator (Less than or Equal)" << endl;
            }

            else if(strcmp(a,">") == 0)
            {
                cout << setw(10) << a << setw(35) << " -> Comparison Operator (Greater than)" << endl;
            }

            else if(strcmp(a,"<") == 0)
            {
                cout << setw(10) << a << setw(35) << " -> Comparison Operator (Less than)" << endl;
            }

            else if(strcmp(a,"&") == 0)
            {
                cout << setw(10) << a << setw(35) << " -> Bitwise AND Operator" << endl;
            }

            else if(strcmp(a,"|") == 0)
            {
                cout << setw(10) << a << setw(35) << " -> Bitwise OR Operator" << endl;
            }

            else if(strcmp(a,"||") == 0)
            {
                cout << setw(10) << a << setw(35) << " -> Logical OR Operator" << endl;
            }

            else if(strcmp(a,"&&")  ==  0)
            {
                cout << setw(10) << a << setw(35) << " -> Logical AND Operator" << endl;
            }
        }

        if(x == '/' || x == '*' || x == '+' || x == '-' || x == '%')
        {
            b[ao++] = x;
        }

        else if(x != '/' && ao != 0)
        {
            b[ao] = '\0';
            ao = 0;
            strcpy(a,b);

            if(strcmp(a,"++") == 0)
            {
                cout << setw(10) << a << setw(35) << " -> Increment Operator" << endl;
            }
            else if(strcmp(a,"--") == 0)
            {
                cout << setw(10) << a << setw(35) << " -> Decrement Operator" << endl;
            }
            else if(strcmp(a,"/") == 0)
            {
                cout << setw(10) << a << setw(35) << " -> Arithmetic Division Operator" << endl;
            }
            else if(strcmp(a,"*") == 0)
            {
                cout << setw(10) << a << setw(35) << " -> Arithmetic Multiplication Operator" << endl;
            }
            else if(strcmp(a,"+") == 0)
            {
                cout << setw(10) << a << setw(35) << " -> Arithmetic Addition Operator" << endl;
            }
            else if(strcmp(a,"-") == 0)
            {
                cout << setw(10) << a << setw(35) << " -> Arithmetic Subtraction Operator" << endl;
            }
            else if(strcmp(a,"%") == 0)
            {
                cout << setw(10) << a << setw(35) << " -> Arithmetic Modulus operator" << endl;
            }
            else if(strcmp(a, "//") == 0)
            {
                while(1)
                {
                    x = fin.get();
                    if(x == '\n')
                    {
                        line++;
                        y = ';';
                        break;
                    }
                }
                continue;
            }
            else if(strcmp(a, "///") == 0)
            {
                while(1)
                {
                    x = fin.get();
                    if(x == '\n')
                    {
                        line++;
                        y = ';';
                        break;
                    }
                }
                continue;
            }
            else if(strcmp(a , "/*") == 0)
            {
                while(1)
                {
                    x = fin.get();
                    if(x == '*')
                    {
                        x = fin.get();
                        if(x == '/')
                        {
                            y = ';';
                            break;
                        }
                    }
                }
                continue;
            }
        }

        else if(x == preprocessor[0])
        {
            y = ';';
            cout << setw(10) << x << setw(35) << " -> Preprocessor" << endl;
        }

        if ((x == '0' || x == '1' || x == '2' || x == '3' || x == '4' || x == '5' || x == '6' ||
                x == '7' || x == '8' || x == '9' || x == '.'))
        {
            if(j==0)
            {
                b[n++] = x;
            }
        }

        ///Identifier Error
        if(((x >= 97 && x <= 122) || (x >= 65 && x <= 90)) && n != 0)
        {
            cout << endl;
            cout << setw(10) << b[0] << x << setw(35) << " -> Invalid Identifier(At Line: " << line+1 << ")" << endl;
            cout << endl;
            n = 0;
            continue;
        }

        if ((x == ' ' || x == '\n' || x == ';' || x == ',' || x == '+' || x == '-' || x == '*' ||
                x == '/' || x == '=' || x == '(' || x == ')' || x == '{' || x == '}' || x == '[' ||
                x == ']' || x == ':' || x == '>' || x == '<') &&
                (n != 0))
        {
            b[n] = '\0';
            n = 0;
            strcpy(a, b);
            cout << setw(10) << a << setw(35) << " -> Number" << endl;

        }

        if((isalnum(x) && n == 0) || x == 95)
        {
            c[j++] = x;
        }
        else if (( x == '\n' || x == ',' || x == ';' || x == '(' || x == ')' || x == ' ' ||
                  x == '{' || x == '}' || x == '[' || x == ']' ||x == '<' || x == '>' || x == '+' ||
                  x == '-' || x == '*' || x == '/' || x == '=' || x == '0' || x == '1' || x == '2' ||
                  x == '2' || x == '3' || x == '4' || x == '5' || x == '6' || x == '7' || x == '8' ||
                  x == '9') && (j != 0))
        {
            c[j]='\0';
            j=0;

            ///Checking Data type
            if(datatypeValidation(c) == 1)
            {
                if(flag == 1)
                {
                    cout << endl;
                    cout << setw(10) << c << setw(35) << " -> Error! It is a Data type!(At Line: " << line+1 << ")" << endl;
                    cout << endl;
                }
                else
                {
                    flag = 1 ;
                    strcpy(temp,c);
                    cout << setw(10) << c << setw(35) << " -> Data type" << endl;

                }
            }

            ///Checking keyword error
            else if(keywordValidation(c) == 1)
            {
                if(flag == 1)
                {
                    cout << endl;
                    cout << setw(10) << c << setw(35) << " -> Error!!It is a Keyword!(At Line: " << line+1 << ")" << endl;
                    cout << endl;
                }
                else
                {
                    if(strcmp(c,"if") == 0)
                    {
                        iff1 = 1;
                        iff2 = 1;
                        cout << setw(10) << c << setw(35) << "-> Keyword" << endl;
                        ifarr[ia++] = x;
                        y = ';';

                        ///Error in if
                        if(ifarr[ia-1] != '(')
                        {
                            cout << endl;
                            cout << setw(35) << "Error in if(At Line: " << line+1 << endl;
                            cout << endl;
                            ia = 0;
                            iff2 = 0;
                            y = ';';
                        }
                    }

                    else if((strcmp(c,"else") == 0) && iff1 == 1)
                    {
                        elsearr[ea++] = x;
                        cout << setw(10) << c << setw(35) << "-> Keyword" << endl;
                        iff1 = 0;
                        y = ';';
                    }

                    ///else without if error
                    else if((strcmp(c,"else") == 0) && iff1 == 0)
                    {
                        y = ';';
                        cout << endl;
                        cout << setw(10) << c << setw(35) << "-> Error!! else without if!(At Line: " << line+1 << ")" << endl;
                        cout << endl;
                    }
                    else if(strcmp(c, "main") == 0)
                    {
                        cout << setw(10) << c << setw(35) << "-> Keyword" << endl;
                        x = fin.get();
                        while(1)
                        {
                           if(x == ')')
                           {
                               y = ';';
                               break;
                           }
                        }
                        continue;
                    }
                    else
                    {
                        cout << setw(10) << c << setw(35) << "-> Keyword" << endl;
                    }
                }
            }

            ///checking Loop
            else if(loopValidation(c) == 1)
            {
                if(flag == 1)
                {
                    cout << endl;
                    cout << setw(10) << c << setw(35) << " -> Error!!It is a Loop!(At Line: " << line+1 << ")" << endl;
                    cout << endl;
                }
                else
                {
                    cout << setw(10) << c << setw(35) << " -> Loop" << endl;
                    if(strcmp(c,"for") == 0)
                    {
                        forf = 1;
                        forarr[fa++] = x;

                        ///Checking Error in for
                        if(forarr[fa-1] != '(')
                        {
                            cout << endl;
                            cout << setw(35) << "Error in for(At Line: " << line+1 << endl;
                            cout << endl;
                            fa=0;
                            y = ';';
                        }

                    }
                    else if(strcmp(c,"while") == 0)
                    {
                        whilef = 1;
                        whilearr[wa++] = x;

                        ///Checking Error in while
                        if(whilearr[wa-1] != '(')
                        {
                            y = ';';
                            cout << endl;
                            cout << setw(35) << "Error in while(At Line: " << line+1 << endl;
                            cout << endl;
                            wa=0;
                            whilef = 0;
                        }
                    }
                }
            }

            ///checking Identifier
            else
            {
                if(((c[0]>=97 && c[0]<=122) || (c[0]>=65 && c[0]<=90) || c[0]==95) && flag == 1)
                {
                    cout << setw(10) << c << setw(35) << " -> Identifier" << endl;
                    identifiers.insert(c);
                    id_dt.insert(make_pair(c,temp));
                }
                else if(((c[0]>=97 && c[0]<=122) || (c[0]>=65 && c[0]<=90) || c[0]==95) && flag == 0)
                {
                    set <string> :: iterator i = identifiers.find(c);
                    if(i == identifiers.end())
                    {
                        if((dq != 1 && dq == 0) && (sq != 1 && sq == 0))
                        {
                            cout << endl;
                            cout << setw(10) << c << setw(35)<< " -> Identifier(Error!!Data type missing!)(At Line: " << line+1 << ")" << endl;
                            cout << endl;
                        }
                    }
                }
            }
        }

        if(x == ',')
        {
            cout << setw(10) << x << setw(35) << " -> Comma" << endl;
        }
        else if(x == ';')
        {
            if(dq == 1)
            {
                cout << setw(10) << "Error!! \" Missing(At Line: " << line+1 << ")" << endl;
                dq = 0;
            }
            if(sq == 1)
            {
                cout << setw(10) << "Error!! ' Missing(At Line: " << line+1 << ")" << endl;
                sq = 0;
            }

            cout << setw(10) << x << setw(35) << " -> Semicolon" << endl;

            if(flag == 1)
            {
                flag = 0;
            }
        }
        else if(x == '(')
        {
            pn++;

            cout << setw(10) << x << setw(35) << " -> Opening Parenthesis" << endl;
        }
        else if(x == ')')
        {
            pn--;
            y = ';';
            cout << setw(10) << x << setw(35) << " -> Closing Parenthesis" << endl;
        }
        else if(x == '{')
        {
            cb++;
            y = ';';
            cout << setw(10) << x << setw(35) << " -> Opening Curly Bracket" << endl;
        }
        else if(x == '}')
        {
            cb--;
            y = ';';
            cout << setw(10) << x << setw(35) << " -> Closing Curly Bracket" << endl;
        }
        else if(x == '[')
        {
            sb++;
            cout << setw(10) << x << setw(35) << " -> Opening Square Bracket" << endl;
        }
        else if(x == ']')
        {
            sb--;
            cout << setw(10) << x << setw(35) << " -> Closing Square Bracket" << endl;
        }
        else if(x == '"')
        {
            dq++;
            cout << setw(10) << x << setw(35) << " -> Double Quotation" << endl;
        }
        else if(x == '\'')
        {
            sq++;
            cout << setw(10) << x << setw(35) << " -> Single Quotation" << endl;
        }
        else if(x == ':')
        {
            cout << setw(10) << x << setw(35) << " -> Colon" << endl;
        }

    }

    /// bracket error
    cout << endl << endl;
    if(pn > 0)
    {
        cout << "Error!! " << pn << " Closing Parenthesis Missing" << endl;
    }
    else if(pn < 0)
    {
        cout << "Error!! " << pn*(-1) << " Opening Parenthesis Missing" << endl;
    }

    if(cb > 0)
    {
        cout << "Error!! " << cb << " Closing Curly Bracket Missing" << endl;
    }
    else if(cb < 0)
    {
        cout << "Error!! " << cb*(-1) << " Opening Curly Bracket Missing" << endl;
    }

    if(sb > 0)
    {
        cout << "Error!! " << sb << " Closing Square Bracket Missing" << endl;
    }
    else if(sb < 0)
    {
        cout << "Error!! " << sb*(-1) << " Opening Curly Bracket Missing" << endl;
    }

    fin.close();

    /*cout << endl << endl << endl << endl;
    cout << "Symbol Table : " << endl << endl;
    cout << "-------------------------------------------------------------------------------" << endl;
    cout << "    Identifier Name              ->               Type             " << endl;
    cout << "-------------------------------------------------------------------------------" << endl;

    int k = 0;
    for (set < pair <string , string > >::iterator i = id_dt.begin(); i != id_dt.end(); i++)
    {
        cout << setw(10) << (*i).first << setw(25) << "->" << setw(20) << (*i).second << setw(20) << endl;
        k++;
    }*/

    return 0;

}
