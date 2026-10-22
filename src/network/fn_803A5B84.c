#pragma force_active on

extern int fn_8039832C(void *, int, int);
extern int fn_80398818(void *, int, int);
extern int fn_80398A08(int, int, void *);
extern int fn_80398680(void *);

int fn_803A5B84(int arg0, int arg1, int arg2, int arg3)
{
    unsigned char context[0xA4];
    int result;
    int close_result;

    result = fn_8039832C(context, arg0, 0xA);
    if (result < 0)
        return result;

    result = fn_80398818(context, arg1, 0);
    if (result < 0)
        return result;

    if (arg2 != 0 && arg3 != 0)
        result = fn_80398A08(arg2, arg3, context);

    close_result = fn_80398680(context);
    if (result != 0)
        close_result = result;

    return close_result;
}
