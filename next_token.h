#pragma once
#include <cstdio>
#include <cassert>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
FILE *input = stdin;
string s="";
int len=0;
int cnt = 0;
char *next_token() {
    char *res = NULL;
	string ans;
    int cur=0;
    int ch;
    while (!cur)
    {
        if(len > 0 && (s[0] == '(' || s[0] == ')'))// for cases:'(' ')'
        {
            ans=s;
            cur=len;
            s="";
            len=0;
            break;
        }
        if ((ch = fgetc(input)) == EOF)
            break;

        switch (ch)
        {
            case '(':
            case ')':
				if (s=="#\\"){}
				else{
					if (len>0)
						ans = s; cur = len;
					s = "";
					s = s + (char)ch;
					len = 1;
					break;
				}
            default:
                if (isspace(ch))
                {
					if (s[0] == '\"' && s[s.size() - 1] != '\"'){ //string can receive space
						s = s + (char)ch;
						len++;
					}
					else if (s == "#\\"){
						s = s + (char)ch;
						len++;
					}
					else{
						if (len > 0)
							ans = s; cur = len;
						s = "";
						len = 0;
					}
                }
				else
				{
					if (s[0] == '\"'){
						if (ch == '\\'){
							++cnt;
							if (cnt == 2){ s = s + '\\'; len++; cnt = 0; }
						}
						else{
							if (cnt == 1){
								if (ch == 't'){ s = s + '\t'; len++; }
								if (ch == 'n'){ s = s + '\n'; len++; }
								if (ch == 'r'){ s = s + '\r'; len++; }
								if (ch == '\"'){ s = s + '\"'; len++; }
								if (ch == '\''){ s = s + '\''; len++; }
								cnt = 0;
							}
							else{
								s = s + (char)ch; len++;
							}
						}
					}
					else{
						s = s + (char)ch; len++;
					}
					
                }
        }
    }
    if(cur>0)
    {
        res=new char[cur+2];
        for(int i=0;i<=cur-1;i++)
            res[i]=ans[i];
		res[cur]='\0';
    }
    return res;
}
