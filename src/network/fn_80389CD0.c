#pragma force_active on

typedef struct Context {
    char padding[0x6A0];
    int order;
} Context;

extern Context *lbl_805A1134;
extern int lbl_8059FBC8;

extern const char *fn_80388738(void *, void *, void *);
extern int fn_803899CC(void *, void *);
extern int strcmp(const char *, const char *);

int fn_80389CD0(const void *arg0, const void *arg1)
{
    const char *bstr;
    void *a;
    void *b;
    void *p;
    const char *astr;
    int result;

    a = *(void *const *)arg0;
    b = *(void *const *)arg1;
    p = (char *)lbl_805A1134 + 0x498;

    bstr = fn_80388738(b, p, &lbl_8059FBC8);
    astr = fn_80388738(a, p, &lbl_8059FBC8);
    result = strcmp(astr, bstr);

    if (result == 0)
        return fn_803899CC(a, b);

    if (lbl_805A1134->order == 0)
        result = -result;

    return result;
}
