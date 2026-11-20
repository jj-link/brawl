#include <types.h>
#include <string.h>
#pragma force_active on

extern char lbl_8059F5B0[5];
extern int fn_80363BDC(char *, int *);

typedef struct {
    char *data;
    int length;
} Result;

static inline int skip_space(char *s, int len, int *pos)
{
    while (*pos < len) {
        if (strchr(lbl_8059F5B0, s[*pos]) == 0)
            return 1;
        (*pos)++;
    }
    return 0;
}

int fn_80363A6C(int unused, char *s, int len, int *pos, Result *out)
{
    char c;
    char *p;

    if (!skip_space(s, len, pos))
        return 0;
    c = s[*pos];
    if (c != '"' && c != '\'')
        return 0;
    (*pos)++;
    p = s + *pos;
    out->length = 0;
    if (*pos >= len)
        return 0;
    if (c == s[*pos]) {
        out->data = p;
        (*pos)++;
        return 1;
    }
    while (c != s[*pos]) {
        if (*pos >= len)
            return 0;
        (*pos)++;
        out->length++;
    }
    (*pos)++;
    if (!fn_80363BDC(p, &out->length))
        return 0;
    out->data = p;
    return 1;
}