#include <iostream>
#include <fstream>
char p[5000];
int stack[10000],val[10000]={0};
int ptr=0,sptr=-1;
int main(int argc, char** argv) {
    std::ifstream inFile;
    inFile.open(argv[1]);
    if(!inFile.is_open())  return -1;
    int n=0;
    while(!inFile.eof())   inFile.read(p+n,1),n++;
    for(int i=0;i<n;i++) {
        if(p[i]==',')      val[ptr]=getchar();
        else if(p[i]=='.') printf("%c",val[ptr]);
        else if(p[i]=='+') val[ptr]++;
        else if(p[i]=='-') val[ptr]--;
        else if(p[i]=='<') ptr--;
        else if(p[i]=='>') ptr++;
        else if(p[i]==']') i=stack[sptr--];
        else if(p[i]=='[') {
            if(val[ptr]==0) for(int j=1;j!=0;i++,j+=(p[i]>93||p[i]<91)?0:(92-p[i]));
            else stack[++sptr]=i-1;
        }
    }
}// End of code by @ rituraj
