#include<bits/stdc++.h>
#include<windows.h>

using namespace std;

char keyword[50][15] = {"void", "printf", "main", "extern", "enum", "switch", "case", "continue", "break", "goto",
                        "if", "for", "else if", "else", "struct", "register", "return", "union", "typedef", "signed",
                        "unsigned", "static", "volatile", "default", "const", "sizeof", "while", "do"};
char ConKeyword[30][10] = {"do", "if", "while"};


char datatype[50][15] = {"auto", "int", "long", "float", "double", "char", "string"};
char preprocessor[] = {"#"};

int isConKeyword(char c[])
{
    int x = 0;
    for (int i = 0; i < 25; i++)
    {
        if (strcmp(ConKeyword[i], c) == 0)
        {
            x = 1;
            break;
        }
    }
    return x;
}

void SetColor(int ForgC)
{
    WORD wColor;

    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
    return;
}

int keywordValidation(char c[])
{
    int x = 0;
    for (int i = 0; i < 30; i++)
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
    for(int i = 0; i < 7 ; i++)
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
    set < pair <string , string > > iddt;

    if(!fin.is_open()){
        cout << "Error" << endl;
        return 0;
    }

    cout << endl << endl;
    cout << "Tokenization:" << endl<<endl;
    cout << "--------------------------------------------------------" << endl;
    cout << "      Token      ->               Token Type            " << endl;
    cout << "--------------------------------------------------------" << endl;

    int op = 0, ao = 0, j = 0, p = 0, pb = 0, cb = 0, tb = 0, line = 1, y, lo = 0, sc = 0;
    int flag = 0, ConFlag = 0, for_flag = 0, print_flag = 0, if_flag = 0, test = 0;

    while(!fin.eof())
    {

        x = fin.get();

        if(x == '\n'){
            line++;
            ///Ignoring ; in new line
            if(y == '\n'){
                y = ';';
            }
            ///Checking ;
            if(y != ';'){
                cout<<endl;
                SetColor(12);
                cout<<"\t\tError!! Semicolon missing in line "<<line-1<<endl<<endl;
                SetColor(15);
            }
        }

        y = x;

        ///Checking Semicolon in for
        if(for_flag == 1)
        {
            if(x == ';')
            {
                sc++;
            }
            if(x == ')' && sc == 2)
            {
                y = ';';
                sc = 0;
                for_flag = 0;
                flag = 0;
            }

            else if(x == ')' && sc != 2)
            {
                cout << endl;
                SetColor(12);
                cout << "\tError!! semicolon missing in for at line " <<line<< endl;
                SetColor(15);
                cout << endl;
                y = ';';
                sc = 0;
                for_flag = 0;
                flag = 0;
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
                    {
                        line++;
                        break;
                    }
                }
                continue;
            }
            else if(strcmp(a, "///")==0)
            {
                while(1)
                {
                    x = fin.get();
                    if(x == '\n')
                    {
                        line++;
                        break;
                    }
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
                        if(x == '/'){
                            y = ';';
                            break;
                        }
                    }
                }
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
                b[p++] = x;
            }
        }

        if(((x >= 97 && x <= 122) || (x >= 65 && x <= 90)) && p != 0)
        {
            SetColor(12);
            cout << setw(10) << b[0] << x << setw(35) << " -> Invalid Identifier" << endl;
            SetColor(15);
            p = 0;
            continue;
        }

        if ((x == ' ' || x == '\n' || x == ';' || x == ',' || x == '+' || x == '-' || x == '*' ||
                x == '/' || x == '=' || x == '(' || x == ')' || x == '{' || x == '}' || x == '[' ||
                x == ']' || x == ':' || x == '>' || x == '<') &&
                (p != 0))
        {
            b[p] = '\0';
            p = 0;
            strcpy(a, b);
            cout << setw(10) << a << setw(35) << " -> Number" << endl;
        }

        if((isalnum(x) && p == 0) || x == 95)
        {
            c[j++] = x;
        }
        else if ((x == ' ' || x == '\n' || x == ',' || x == ';' || x == '(' || x == ')' ||
                  x == '{' || x == '}' || x == '[' || x == ']' ||x == '<' || x == '>' || x == '+' ||
                  x == '-' || x == '*' ||x == '/' || x == '=' || x == '0' || x == '1' || x == '2' ||
                  x == '2' || x == '3' || x == '4' || x == '5' || x == '6' || x == '7' || x == '8' ||
                  x == '9') && (j != 0))
        {
            c[j]='\0';
            j=0;

            if(datatypeValidation(c) == 1)
            {
                if(flag == 1)
                {
                    SetColor(12);
                    cout << setw(10) << c << setw(35) << " -> Error! It is a Data type!" << endl;
                    SetColor(15);
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
                    SetColor(12);
                    cout << setw(10) << c << setw(35) << " -> Error! It is a Keyword!" << endl;
                    SetColor(15);
                }
                else
                {
                    cout << setw(10) << c << setw(35) << " -> Keyword" << endl;

                    if(strcmp(c, "main") == 0)
                    {
                        while(1){
                            if(x == ')'){
                                y = ';';
                                break;
                            }
                            if(x == '('){
                                cout << setw(10) << x << setw(35) << " -> Opening Parenthesis" << endl;
                                pb++;
                            }
                            x = fin.get();
                        }
                    }


                    if(strcmp(c, "printf") == 0)
                    {
                        print_flag = 1;
                    }

                    if(strcmp(c, "for") == 0)
                    {
                        for_flag = 1;
                    }

                    if(strcmp(c, "if") == 0)
                    {
                        if_flag = 1;
                    }

                    if(strcmp(c, "else") == 0 && if_flag == 0)
                    {
                        SetColor(12);
                        cout<<"\t\tError! else without if in line "<<line<<endl<<endl;
                        SetColor(15);
                        if_flag = 0;
                        flag = 0;
                        while(1){
                            if(x == '\n'){
                                y = ';';
                                break;
                            }
                            x = fin.get();
                        }
                        continue;
                    }

                    else if(strcmp(c, "else") == 0 && if_flag == 1)
                    {
                        if_flag = 0;
                        flag = 0;
                        if(x == '\n'){
                            y = ';';
                        }
                    }


                    if(isConKeyword(c) == 1){
                        ConFlag = 1;
                        if(x!='('){
                            SetColor(12);
                            cout<<endl<< setw(25) <<"\tERROR!! Opening Parenthesis missing in line "<<line-1<<endl<<endl;
                            SetColor(15);
                        }
                        else{
                            pb++;
                            cout << setw(10) << x << setw(35) << " -> Opening Parenthesis" << endl;
                            x = fin.get();
                            while(1){
                                if(x==')'){
                                    cout << setw(10) << x << setw(35) << " -> Closing Parenthesis" << endl;
                                    flag = 0;
                                    pb--;
                                    y = ';';
                                    break;
                                }
                                else if(x == '>'){
                                    lo++;
                                    x = fin.get();
                                    if(x == '='){
                                        cout << setw(10) << ">=" << setw(35) << " -> Comparison Operator" << endl;
                                    }
                                    else
                                        cout << setw(10) << ">" << setw(35) << " -> Comparison Operator" << endl;
                                }
                                else if(x == '<'){
                                    lo++;
                                    x = fin.get();
                                    if(x == '='){
                                        cout << setw(10) << "<=" << setw(35) << " -> Comparison Operator" << endl;
                                    }
                                    else
                                        cout << setw(10) << "<" << setw(35) << " -> Comparison Operator" << endl;
                                }
                                else if(x == '='){
                                    x = fin.get();
                                    if(x == '='){
                                        lo++;
                                        cout << setw(10) << "==" << setw(35) << " -> Comparison Operator" << endl;
                                    }
                                }
                                x = fin.get();
                            }
                            if(lo == 0){
                                SetColor(12);
                                cout << setw(25) << " -> Condition Error! in line " << line << endl;
                                SetColor(15);
                            }
                            lo=0;
                            continue;
                        }

                    }
                }
            }
            else
            {
                if(((c[0]>=97 && c[0]<=122) || (c[0]>=65 && c[0]<=90) || c[0]==95) && flag == 1)
                {
                    cout << setw(10) << c << setw(35) << " -> identifier (" << temp << ")" << endl;
                    identifiers.insert(c);
                    iddt.insert(make_pair(c,temp));
                }
                else if(((c[0]>=97 && c[0]<=122) || (c[0]>=65 && c[0]<=90) || c[0]==95) && flag == 0)
                {
                    set <string> :: iterator it = identifiers.find(c);
                    if(it == identifiers.end())
                    {
                        SetColor(12);
                        cout << setw(10) << c << setw(35)<< " -> identifier( Error!!Data type missing in line "<<line<<")" << endl;
                        SetColor(15);
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
            pb++;
        }
        else if(x == ')')
        {
            cout << setw(10) << x << setw(35) << " -> Closing Parenthesis" << endl;
            pb--;
        }
        else if(x == '{')
        {
            y = ';';
            cout << setw(10) << x << setw(35) << " -> Opening Curly Bracket" << endl;
            cb++;
        }
        else if(x == '}')
        {
            y = ';';
            cout << setw(10) << x << setw(35) << " -> Closing Curly Bracket" << endl;
            cb--;
        }
        else if(x == '[')
        {
            cout << setw(10) << x << setw(35) << " -> Opening Square Bracket" << endl;
            tb++;
        }
        else if(x == ']')
        {
            cout << setw(10) << x << setw(35) << " -> Closing Square Bracket" << endl;
            tb--;
        }
        else if(x == '"' && print_flag == 1)
        {
            while(1){
                x = fin.get();
                if(x == '"'){
                    print_flag = 0;
                    break;
                }
            }
        }
        else if(x == '\'')
        {
            while(1){
                x = fin.get();
                if(x == '\''){
                    print_flag = 0;
                    break;
                }
            }
        }
        else if(x == ':')
        {
            cout << setw(10) << x << setw(35)<< " -> Colon" << endl;
        }

    }

    fin.close();

    if(pb>0){
        SetColor(12);
        cout<<endl<< setw(10) <<"Error!! "<<pb<<" Closing parenthesis missing"<< setw(35)<<endl<<endl;
        SetColor(15);
    }
    else if(pb<0){
        SetColor(12);
        cout<<endl<< setw(10) <<"Error!! "<<pb * (-1)<<" Opening parenthesis missing"<< setw(35)<<endl<<endl;
        SetColor(15);
    }
    if(cb>0){
        SetColor(12);
        cout<<endl<< setw(10) <<"Error!! "<<cb<<" Closing Curly Bracket missing"<< setw(35)<<endl<<endl;
        SetColor(15);
    }
    else if(cb<0){
        SetColor(12);
        cout<<endl<< setw(10) <<"Error!! "<<cb * (-1)<<" Opening Curly Bracket missing"<< setw(35)<<endl<<endl;
        SetColor(15);
    }
    if(tb>0){
        SetColor(12);
        cout<<endl<< setw(10) <<"Error!! "<<tb<<" Closing Square Bracket missing"<< setw(35)<<endl<<endl;
        SetColor(12);
    }
    else if(tb<0){
        SetColor(12);
        cout<<endl<< setw(10) <<"Error!! "<<tb * (-1)<<" Opening Square Bracket missing"<< setw(35)<<endl<<endl;
        SetColor(15);
    }




    /*cout << endl << endl << endl;
    cout << "Symbol Table : " << endl << endl;
    cout << "-------------------------------------------------------------------------------" << endl;
    cout << "    Identifier Name              ->               Type             " << endl;
    cout << "-------------------------------------------------------------------------------" << endl;

    int k = 0;
    for (set < pair <string , string > >::iterator i = iddt.begin(); i != iddt.end(); i++)
    {
        cout << setw(10) << (*i).first << setw(25) << "->" << setw(20) << (*i).second << setw(20) << endl;
        k++;
    }*/

    return 0;
}
