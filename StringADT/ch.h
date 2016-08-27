#ifndef CH_H_
#define CH_H_

struct str
{
    char *ch;
};
typedef struct str str;
str * Substring(str *,int,int);
char Character(str *,int);
str * Concatenate(str *,str *);
int PatternMatch(str *,str *);
str * ChangeChar(str *,int,char);

#endif
