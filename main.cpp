#include<iostream>
#include<fstream>
#include<string.h>
#include<map>
using namespace std;

string filename="/Users/mac/Desktop/test.txt";

int k=0;
map<string,int>Map;
map<string,int>::iterator iter;

string Key[100]={"include","define","int","char","string","float","double","bool","true","false","if","else","while","for","default","do","public","static","return","switch","case","const"};
string opr[100]={"+","-","*","/","++","--","+=","-=","*=","/=","&","&&","|","||","!","==","!=","=",">",">=","<","<>","<=",">>","<<","?",":",":="};
char ilegal[100]={'`' , '~' , '@' , '$' , '^' , '\\'};
char Sep[100]={',' , ';' , '{' , '}' , '(' , ')' , '[' , ']' , ' ' , '\n' , '\t'};


bool isKey(string s){
    for(int i=0;i<sizeof(Key);i++){
        if(Key[i]==s){
            return true;
        }
    }
    return false;
}



bool isAlpha(char ch){//judge character
    if(ch >= 'a' && ch <= 'z'){
        return true;
    }
    if(ch >= 'A' && ch <= 'Z'){
        return true;
    }
    return false;
}

bool isDigit(int ch){
    if(ch >= '0' && ch <= '9')
        return true;
    return false;
}

bool isOprStart(char ch){
    for(int i=0;i<100;i++){
        if(ch==opr[i][0])
            return true;
    }
    return false;
}

bool isOpr(string s){
    for(int i=0;i<sizeof(opr);i++){
        if(s==opr[i])
            return true;
    }
    return false;
}

bool isSep(char ch){
    for(int i=0;i<sizeof(Sep);i++){
        if(ch==Sep[i])
            return true;
    }
    return false;
}

bool ilegalchar(char ch){
    for(int i=0;i<100;i++){
        if(ch==ilegal[i]){
            return true;
        }
    }
    return false;
}

void printKEY(string s){
//    int flag=1;
//    for(int i=0;i<100;i++){
//        if(Key[i]==s){
//            flag+=i;
//            break;
//        }
//    }
//    cout<<"<"<<flag<<" "<<s<<">"<<endl;
    
    cout<<"<"<< s << " -" <<">"<<endl;
//    outFile<<"<"<< s << " -" <<">"<<endl;
}

void printOPR(string s){
//    int flag=23;
//    for(int i=0;i<26;i++){
//        if(opr[i]==s){
//            flag+=i;
//            break;
//        }
//    }
//    cout<<"<"<<flag<<" "<<s<<">"<<endl;
    string t;
    if(s=="<"){
        t="LT";
    }
    else if(s=="<="){
        t="LE";
    }
    else if(s=="="){
        t="EQ";
    }
    else if(s=="<>"){
        t="NE";
    }
    else if(s==">"){
        t="GT";
    }
    else if(s==">="){
        t="GE";
    }
    else if(s==":="){
        t="assign-op";
    }
    else{
        t="-";
    }
    cout<<"<"<< s << " " << t <<">"<<endl;
//    outFile<<"<"<< s << " " << t <<">"<<endl;
}

void printSEP(char s){
//    int flag=48;
//    for(int i=0;i<26;i++){
//        if(Sep[i]==s){
//            flag+=i;
//            break;
//        }
//    }
//    if(s!=' ')
//        cout<<"<"<<flag<<" "<<s<<">"<<endl;
    if(s!=' '){
        cout<<"<"<<s<<" -"<<">"<<endl;
//        outFile<<"<"<<s<<" -"<<">"<<endl;
    }
}

void printVAR(string s){
//    cout<<"<"<<0<<" "<<s<<">"<<endl;
    iter=Map.find(s);
    if(iter==Map.end()){
        Map.insert(pair<string,int>(s,k++));
        iter=Map.find(s);
    }
    
    cout<<"<"<< s <<" "<< iter->second <<">"<<endl;
//    outFile<<"<"<< "id" <<" "<< iter->second <<">"<<endl;
}
void printfNUM(string s){
//    cout<<"<"<<-1<<" "<<s<<">"<<endl;
    cout<<"<"<< "num" <<" "<< s <<">"<<endl;
//    outFile<<"<"<< "num" <<" "<< s <<">"<<endl;
}

int main(){
    char ch;
    int ch_cnt=0;
    string word;
    int key_cnt=0;
    int var_cnt=0;
    int digit_cnt=0;
    int opr_cnt=0;
    int line_cnt=1;

    ifstream inFile(filename,ios::in);
    if(!inFile.is_open()){
        cout<<"open err"<<endl;
        exit(0);
    }
    inFile.get(ch);
    if(ch=='\n')
       line_cnt++;
    if(ch!=' '&&ch!='\n'){
        ch_cnt++;
        
    }
    
    while(!inFile.eof()){
        while(ilegalchar(ch)){
//            outFile<<line_cnt<<"行词法错误，有非法字符，已修复"<<endl;
            cout<<line_cnt<<"行词法错误，有非法字符，已修复"<<endl;
            inFile.get(ch);
            if(ch=='\n')
               line_cnt++;
            if(ch!=' '&&ch!='\n'){
                ch_cnt++;
                
            }
        }
        word="";
        if(ch=='#'){
            inFile.get(ch);
            if(ch=='\n')
               line_cnt++;
            if(ch!=' '&&ch!='\n'){
                ch_cnt++;
                
            }
            while(ilegalchar(ch)){
                cout<<line_cnt<<"行词法错误，有非法字符，已修复"<<endl;
//                outFile<<line_cnt<<"行词法错误，有非法字符，已修复"<<endl;
                inFile.get(ch);
                if(ch=='\n')
                   line_cnt++;
                if(ch!=' '&&ch!='\n'){
                    ch_cnt++;
                    
                }
            }
            while(isAlpha(ch)&&word!="include"&&word!="define"){
                word.append(1,ch);
                inFile.get(ch);
                if(ch=='\n')
                    line_cnt++;
                 if(ch!=' '&&ch!='\n'){
                     ch_cnt++;
                     
                 }
                while(ilegalchar(ch)){
                    cout<<line_cnt<<"行词法错误，有非法字符，已修复"<<endl;
//                    outFile<<line_cnt<<"行词法错误，有非法字符，已修复"<<endl;
                    inFile.get(ch);
                    if(ch=='\n')
                       line_cnt++;
                    if(ch!=' '&&ch!='\n'){
                        ch_cnt++;
                        
                    }
                }
            }

            if(word == "include"){
                key_cnt++;
                word="";
                inFile.get(ch);
                if(ch=='\n')
                   line_cnt++;
                if(ch!=' '&&ch!='\n'){
                    ch_cnt++;
                    
                }
                while(ch==' '||ilegalchar(ch)){
                    cout<<line_cnt<<"行词法错误，有空格或非法字符，已修复"<<endl;
//                    outFile<<line_cnt<<"行词法错误，有空格或非法字符，已修复"<<endl;
                    inFile.get(ch);
                    if(ch=='\n')
                       line_cnt++;
                    if(ch!=' '&&ch!='\n'){
                        ch_cnt++;
                        
                    }
                }
                while(ch != '"' && ch != '>'){
                    word.append(1,ch);
                    inFile.get(ch);
                    if(ch=='\n')
                       line_cnt++;
                    if(ch!=' '&&ch!='\n'){
                        ch_cnt++;
                        
                    }
                    while(ch==' '||ilegalchar(ch)){
                        cout<<line_cnt<<"行词法错误，有空格或非法字符，已修复"<<endl;
//                        outFile<<line_cnt<<"行词法错误，有空格或非法字符，已修复"<<endl;
                        inFile.get(ch);
                        if(ch=='\n')
                           line_cnt++;
                        if(ch!=' '&&ch!='\n'){
                            ch_cnt++;
                            
                        }
                    }
                }
                cout<<"头文件:"<<word<<endl;
//                outFile<<"头文件:"<<word<<endl;
                inFile.get(ch);
                if(ch=='\n')
                   line_cnt++;
                if(ch!=' '&&ch!='\n'){
                    ch_cnt++;
                    
                }
                while(ch==' '||ilegalchar(ch)){
                    cout<<line_cnt<<"行词法错误，有空格或非法字符，已修复"<<endl;
//                    outFile<<line_cnt<<"行词法错误，有空格或非法字符，已修复"<<endl;
                    inFile.get(ch);
                    if(ch=='\n')
                       line_cnt++;
                    if(ch!=' '&&ch!='\n'){
                        ch_cnt++;
                        
                    }
                }
                continue;
            }
            else if(word== "define"){
                key_cnt++;
                word="";
                while(ch==' '){
                    inFile.get(ch);
                    if(ch=='\n')
                       line_cnt++;
                    if(ch!=' '&&ch!='\n'){
                        ch_cnt++;
                        
                    }
                }
                while(isAlpha(ch)){
                    word.append(1,ch);
                    inFile.get(ch);
                    while(ilegalchar(ch)){
                        cout<<line_cnt<<"行词法错误，有非法字符，已修复"<<endl;
//                        outFile<<line_cnt<<"行词法错误，有非法字符，已修复"<<endl;
                        inFile.get(ch);
                        if(ch=='\n')
                           line_cnt++;
                        if(ch!=' '&&ch!='\n'){
                            ch_cnt++;
                            
                        }
                    }
                    
                    if(ch=='\n')
                       line_cnt++;
                    if(ch!=' '&&ch!='\n'){
                        ch_cnt++;
                        
                    }
                }

                //cout<<"变量名:"<<word<<endl;
                printVAR(word);
                var_cnt++;
                cout<<"宏定义："<<word<<"=";
//                outFile<<"宏定义："<<word<<"=";
                word="";
                while(ch==' '){
                    inFile.get(ch);
                    if(ch=='\n')
                       line_cnt++;
                    if(ch!=' '&&ch!='\n'){
                        ch_cnt++;
                        
                    }
                }
                while(isDigit(ch)){
                    word.append(1,ch);
                    inFile.get(ch);
                    if(ch=='\n')
                       line_cnt++;
                    if(ch!=' '&&ch!='\n'){
                        ch_cnt++;
                        
                    }
                }
                cout<<word<<endl;
                //cout<<"数字："<<word<<endl;
                printfNUM(word);
                digit_cnt++;
                continue;
            }
            else{
                word="";
                if(ch=='\n')
                    cout<<line_cnt-1<<"行词法错误，#后不是define也不是include"<<endl;
                else
                    cout<<line_cnt<<"行词法错误，#后不是define也不是include"<<endl;
                continue;
            }
        }//if(ch == "#")
        else if(isAlpha(ch)||ch=='_'){
            while(!isSep(ch)&&!isOprStart(ch)){
                word.append(1,ch);
                inFile.get(ch);
                if(ch=='\n')
                   line_cnt++;
                if(ch!=' '&&ch!='\n'){
                    ch_cnt++;
                    
                }
                while(ilegalchar(ch)){
                    cout<<line_cnt<<"行词法错误，有非法字符，已修复（越过非法字符）"<<endl;
                    inFile.get(ch);
                    if(ch=='\n')
                       line_cnt++;
                    if(ch!=' '&&ch!='\n'){
                        ch_cnt++;
                        
                    }
                }
            }
            
            if(isKey(word)){
                //cout<<"关键字："<<word<<endl;
                printKEY(word);
                key_cnt++;
                inFile.get(ch);
                if(ch=='\n')
                   line_cnt++;
                if(ch!=' '&&ch!='\n'){
                    ch_cnt++;
                    
                }
            }
            else{
                //cout<<"变量名："<<word<<endl;
                printVAR(word);
                var_cnt++;
            }
            continue;
        }
        else if(isDigit(ch)){
            while(!isSep(ch)&&!isOprStart(ch)){
                word.append(1,ch);
                inFile.get(ch);
                if(ch=='\n')
                   line_cnt++;
                if(ch!=' '&&ch!='\n'){
                    ch_cnt++;
                    
                }
                while(ilegalchar(ch)){
                    cout<<line_cnt<<"行词法错误，有非法字符，已修复（越过非法字符）"<<endl;
//                    outFile<<line_cnt<<"行词法错误，有非法字符，已修复（越过非法字符）"<<endl;
                    inFile.get(ch);
                    if(ch=='\n')
                       line_cnt++;
                    if(ch!=' '&&ch!='\n'){
                        ch_cnt++;
                        
                    }
                }
            }
            
            int errflag=0;
            int point_num=0;
            for(int i=0;i<word.length();i++){
                //if((word[i]>'9'||word[i]<'0')&&word[i]!='.'){
//                if(isAlpha(word[i])){
//                    errflag=1;
//                    cout<<line_cnt<<"行词法错误，变量名"<<word<<"以数字开头"<<endl;
//                    break;
//                }
                if(word[i]=='.'){
                    if(i==word.length()-1){
                        if(ch=='\n'){
                            cout<<line_cnt-1<<"行词法错误，小数点后没数"<<endl;
//                            outFile<<line_cnt-1<<"行词法错误，小数点后没数"<<endl;
                        }
                        else{
                            cout<<line_cnt<<"行词法错误，小数点后没数"<<endl;
//                            outFile<<line_cnt<<"行词法错误，小数点后没数"<<endl;
                        }
                        errflag=1;
                        break;
                    }
                    point_num++;
                    if(point_num>1){
                        if(ch=='\n'){
                            cout<<line_cnt-1<<"行词法错误，有多个小数点"<<endl;
//                            outFile<<line_cnt-1<<"行词法错误，有多个小数点"<<endl;
                        }
                        else{
                            cout<<line_cnt<<"行词法错误，有多个小数点"<<endl;
//                            outFile<<line_cnt<<"行词法错误，有多个小数点"<<endl;
                        }
                        errflag=1;
                        break;
                    }
                }
                if(isAlpha(word[i])){
                    if(word[i]=='e'){
                        if(i==word.length()-1){
                            errflag=1;
                            if(ch=='\n'){
                                cout<<line_cnt-1<<"行科学记数法e后没有数"<<endl;
//                                outFile<<line_cnt-1<<"行科学记数法e后没有数"<<endl;
                            }
                            else
                                cout<<line_cnt<<"行科学记数法e后没有数"<<endl;
                        }
                        for(int j=i+1;j<word.length();j++){
                            if(word[j]=='.'||isAlpha(word[j])){
                                if(ch=='\n'){
                                    cout<<line_cnt-1<<"行科学记数法e后表示错误"<<endl;
                                }
                                else                                cout<<line_cnt<<"行科学记数法e后表示错误"<<endl;
                                errflag=1;
                            }
                        }
                        break;
                    }
                    errflag=1;
                    cout<<line_cnt<<"行词法错误，变量名"<<word<<"以数字开头"<<endl;
                    break;
                }
            }
            if(errflag==0){
                //cout<<"数字："<<word<<endl;
                printfNUM(word);
                digit_cnt++;
            }
            continue;
        }
        else if(isOprStart(ch)){
            while(isOprStart(ch)&&word!="/*"&&word!="//"){
                word.append(1,ch);
                inFile.get(ch);
                if(ch=='\n')
                   line_cnt++;
                if(ch!=' '&&ch!='\n'){
                    ch_cnt++;
                    
                }
                while(ilegalchar(ch)){
                    cout<<line_cnt<<"行词法错误，有非法字符，已修复（越过非法字符）"<<endl;
                    inFile.get(ch);
                    if(ch=='\n')
                       line_cnt++;
                    if(ch!=' '&&ch!='\n'){
                        ch_cnt++;
                        
                    }
                }
            }
            if(isOpr(word)){
                //cout<<"运算符："<<word<<endl;
                printOPR(word);
                opr_cnt++;
                continue;
            }
            if(word == "//"){
                string buf="";
                buf.append(1,ch);
                inFile.get(ch);
                while(ch!='\n'){
                    if(ch=='\n')
                       line_cnt++;
                    if(ch!=' '&&ch!='\n'){
                        ch_cnt++;
                        
                    }
                    buf.append(1,ch);
                    inFile.get(ch);
                }
                line_cnt++;
                inFile.get(ch);
                if(ch=='\n')
                   line_cnt++;
                if(ch!=' '&&ch!='\n'){
                    ch_cnt++;
                    
                }
                cout<<"注释已跳过"<<endl;
                cout<<"注释内容："<<buf<<endl;
                continue;
            }
            else if(word == "/*"){
                string buf="";
                char end[3]="";
                
                //while(1){
                end[0]=ch;
                inFile.get(ch);
                if(ch=='\n')
                   line_cnt++;
                if(ch!=' '&&ch!='\n'){
                    ch_cnt++;
                    
                }
                end[1]=ch;
                
                while(strcmp(end,"*/")!=0){
                    buf.append(1,end[0]);
                    inFile.get(ch);
                    if(ch=='\n')
                       line_cnt++;
                    if(ch!=' '&&ch!='\n'){
                        ch_cnt++;
                        
                    }
//                    if(ch=='"'){
//                        buf.append(1,end[1]);
//                        inFile.get(ch);
//                        if(ch=='\n')
//                           line_cnt++;
//                        if(ch!=' '&&ch!='\n'){
//                            ch_cnt++;
//
//                        }
//                        buf.append(1,ch);
//                        while(ch!='"'){
//                            inFile.get(ch);
//                            if(ch=='\n')
//                               line_cnt++;
//                            if(ch!=' '&&ch!='\n'){
//                                ch_cnt++;
//
//                            }
//                            buf.append(1,ch);
//                        }
//                        inFile.get(ch);
//                        if(ch=='\n')
//                           line_cnt++;
//                        if(ch!=' '&&ch!='\n'){
//                            ch_cnt++;
//
//                        }
//                        //buf.pop_back();
//                    }
                    end[0]=end[1];
                    end[1]=ch;
                }
                cout<<"注释已跳过"<<endl;
                cout<<"注释内容："<<buf<<endl;
                
                inFile.get(ch);
                if(ch=='\n')
                   line_cnt++;
                if(ch!=' '&&ch!='\n'){
                    ch_cnt++;
                    
                }
                continue;
            }
        }
        else if(isSep(ch)&&ch!='\n'){
            printSEP(ch);
        }

        inFile.get(ch);
        if(ch=='\n')
           line_cnt++;
        if(ch!=' '&&ch!='\n'){
            ch_cnt++;
            
        }
    }
    inFile.close();
    cout<<"************"<<endl;
    cout<<"行数："<<line_cnt<<endl;
    cout<<"关键字数量："<<key_cnt<<endl;
    cout<<"变量名数量："<<var_cnt<<endl;
    cout<<"数字数量："<<digit_cnt<<endl;
    cout<<"运算符数量："<<opr_cnt<<endl;
    cout<<"总字符数量："<<ch_cnt<<endl;
    cout<<"id入口地址对应表如下："<<endl;
    iter=Map.begin();
    while(iter != Map.end()){
        cout << iter->first << " " << iter->second << endl;
        iter++;
    }
}
