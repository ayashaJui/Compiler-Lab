#include<bits/stdc++.h>

using namespace std;

char keyword[50][15] = {"void", "main", "extern", "enum", "switch", "case", "continue", "break", "goto",
                        "if", "else if", "else", "struct", "register", "return", "union", "typedef", "signed",
                        "unsigned", "static", "volatile", "default", "const", "sizeof"
                       };
char datatype[50][15] = {"auto", "int", "long", "float", "double", "char", "string"};
char preprocessor[] = {"#"};

int keywordValidation(char c[])
{
    int x = 0;
    for (int i = 0; i < 25; i++)
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


int main()
{
    cout<< "Lexical Analyzer"<<endl<<endl;

    ifstream fin;
    char file_name[100], a[50], b[50], c[20], temp[15];
    char x;

    cout << "Please Enter File Name: ";
    cin.getline(file_name, 100);

    fin.open(file_name);

    set<string> identifiers;
    set < pair <string , string > > id_dt;

    if(!fin.is_open()){
        cout << "Error" << endl;
        return 0;
    }

    cout << endl << endl;
    cout << "Tokenization:" << endl<<endl;
    cout << "--------------------------------------------------------" << endl;
    cout << "      Token      ->               Token Type            " << endl;
    cout << "--------------------------------------------------------" << endl;

    int op = 0, ao = 0, j = 0, n = 0, flag = 0;

    while(!fin.eof())
    {
        x = fin.get();

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

            if(strcmp(a,"/") == 0)
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
                        break;
                }
                continue;
            }
            else if(strcmp(a, "///")==0)
            {
                while(1)
                {
                    x = fin.get();
                    if(x == '\n')
                        break;
                }
                continue;
            }
            else if(strcmp(a , "/*")==0)
            {
                while(1)
                {
                    x = fin.get();
                    if(x == '*')
                    {
                        x = fin.get();
                        if(x == '/')
                            break;
                    }
                }
                continue;
            }
        }

        else if(x == preprocessor[0])
        {
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

        if(((x >= 97 && x <= 122) || (x >= 65 && x <= 90)) && n != 0)
        {
            cout << setw(10) << b[0] << x << setw(35) << " -> Invalid Identifier" << endl;
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
        else if ((x == ' ' || x == '\n' || x == ',' || x == ';' || x == '(' || x == ')' ||
                  x == '{' || x == '}' || x == '[' || x == ']' ||x == '<' || x == '>' || x == '+' ||
                  x == '-' || x == '*' || x == '/' || x == '=' || x == '0' || x == '1' || x == '2' ||
                  x == '2' || x == '3' || x == '4' || x == '5' || x == '6' || x == '7' || x == '8' ||
                  x == '9') && (j != 0))
        {
            c[j]='\0';
            j=0;

            if(datatypeValidation(c) == 1)
            {
                if(flag == 1)
                {
                    cout << setw(10) << c << setw(35) << " -> Error! It is a Data type!" << endl;
                }
                else
                {
                    flag = 1 ;
                    strcpy(temp,c);
                    cout << setw(10) << c << setw(35) << " -> Data type" << endl;
                }
            }

            else if(keywordValidation(c) == 1)
            {
                if(flag == 1)
                {
                    cout << setw(10) << c << setw(35) << " -> Error!!It is a Keyword!" << endl;
                }
                else
                {
                    cout << setw(10) << c << setw(35) << " -> Keyword" << endl;
                }
            }
            else
            {
                if(((c[0]>=97 && c[0]<=122) || (c[0]>=65 && c[0]<=90) || c[0]==95) && flag == 1)
                {
                    cout << setw(10) << c << setw(35) << " -> Identifier (" << temp << ")" << endl;
                    identifiers.insert(c);
                    id_dt.insert(make_pair(c,temp));
                }
                else if(((c[0]>=97 && c[0]<=122) || (c[0]>=65 && c[0]<=90) || c[0]==95) && flag == 0)
                {
                    set <string> :: iterator i = identifiers.find(c);
                    if(i == identifiers.end())
                    {
                        cout << setw(10) << c << setw(35)<< " -> Identifier(Error!!Data type missing!)" << endl;
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
            cout << setw(10) << x << setw(35) << " -> Semicolon" << endl;
            if(flag == 1)
                flag = 0;
        }
        else if(x == '(')
        {
            cout << setw(10) << x << setw(35) << " -> Opening Parenthesis" << endl;
        }
        else if(x == ')')
        {
            cout << setw(10) << x << setw(35) << " -> Closing Parenthesis" << endl;
        }
        else if(x == '{')
        {
            cout << setw(10) << x << setw(35) << " -> Opening Curly Bracket" << endl;
        }
        else if(x == '}')
        {
            cout << setw(10) << x << setw(35) << " -> Closing Curly Bracket" << endl;
        }
        else if(x == '[')
        {
            cout << setw(10) << x << setw(35) << " -> Opening Square Bracket" << endl;
        }
        else if(x == ']')
        {
            cout << setw(10) << x << setw(35) << " -> Closing Square Bracket" << endl;
        }
        else if(x == '"')
        {
            cout << setw(10) << x << setw(35)<< " -> Double Quotation" << endl;
        }
        else if(x == '\'')
        {
            cout << setw(10) << x << setw(35)<< " -> Single Quotation" << endl;
        }
        else if(x == ':')
        {
            cout << setw(10) << x << setw(35)<< " -> Colon" << endl;
        }
    }

    fin.close();

    cout << endl << endl << endl << endl;
    cout << "Symbol Table : " << endl << endl;
    cout << "-------------------------------------------------------------------------------" << endl;
    cout << "    Identifier Name              ->               Type             " << endl;
    cout << "-------------------------------------------------------------------------------" << endl;

    int k = 0;
    for (set < pair <string , string > >::iterator i = id_dt.begin(); i != id_dt.end(); i++)
    {
        cout << setw(10) << (*i).first << setw(25) << "->" << setw(20) << (*i).second << setw(20) << endl;
        k++;
    }

    return 0;

}
