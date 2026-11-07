#pragma force_active on
extern int fn_8039A260(void);
extern int fn_8039A274(void);
extern int fn_803A1DF4(void **);
extern int fn_8039832C(void *, int, int);
extern int fn_80398818(void *, int, int);
extern int fn_80398A08(void *, int, void *);
extern int fn_80398680(void *);
extern int lbl_8059FDD8;

int fn_803A1CDC(void *arg0, unsigned int arg1)
{
    unsigned char context[0x9c];
    void *data;
    int result;
    int temp;
    unsigned int *p;

    if (fn_8039A260() == 0 && fn_8039A274() == 0)
        return -9;
    if ((unsigned int)arg0 & 0x1F)
        return -0x17;
    result = fn_803A1DF4(&data);
    if (result != 0)
        return result;
    p = data;
    if (arg1 >= p[2])
        return -3;
    p = (unsigned int *)((char *)data + arg1 * 8);
    if (*(unsigned long long *)(p + 16) == 0)
        return -5;
    result = fn_8039832C(context, lbl_8059FDD8, 10);
    if (result != 0)
        return result;
    fn_80398818(context, arg1 * 0x140 + 0x360, 0);
    temp = fn_80398A08(arg0, 0x140, context);
    result = fn_80398680(context);
    if (temp != 0)
        result = temp;
    if (result != 0)
        return result;
    return 0;
}