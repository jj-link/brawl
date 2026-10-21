#pragma force_active on
typedef unsigned int u32;

extern int fn_8039832C(void *, int, int);
extern int fn_80398818(void *, int, int);
extern int fn_80398BD8(void *, int, void *);
extern int fn_80398680(void *);

int fn_803A5A8C(int arg0, int arg1, void *arg2, int arg3, u32 arg4)
{
    unsigned char context[0xA4];
    unsigned char zero;
    int result;
    int close_result;
    u32 i;

    result = fn_8039832C(context, arg0, 9);
    if (result < 0)
        return result;

    result = fn_80398818(context, arg1, 0);
    if (result < 0)
        return result;

    if (arg2 != 0 && arg3 != 0)
        result = fn_80398BD8(arg2, arg3, context);

    for (i = 0; i < arg4; i++) {
        zero = 0;
        result = fn_80398BD8(&zero, 1, context);
        if (result < 0)
            break;
    }

    close_result = fn_80398680(context);
    if (result != 0)
        close_result = result;

    return close_result;
}
