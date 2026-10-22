#pragma force_active on

extern int fn_8039832C(void *, int, int);
extern int fn_80398680(void *);
extern int fn_80398A08(int, int, void *);
extern int fn_80399BCC(void);

extern int lbl_8059FCD4;
extern int lbl_8059FCD8;
extern int lbl_805A1168;
extern int lbl_805A116C;
extern int lbl_805A1170;

int fn_803997D8(void)
{
    unsigned char context[0xA0];
    int result;
    int operation_result;

    if (lbl_805A1170 == 0)
        return -9;

    result = fn_8039832C(context, lbl_8059FCD4, 2);
    if (result == 0) {
        operation_result = fn_80398A08(lbl_805A1168, 0x400, context);
        result = fn_80398680(context);
        if (operation_result != 0)
            result = operation_result;
    }

    if (result == 0) {
        result = fn_80399BCC();
        if (result == 0) {
            lbl_805A116C = 0;
            return result;
        }
    }

    result = fn_8039832C(context, lbl_8059FCD8, 2);
    if (result == 0) {
        operation_result = fn_80398A08(lbl_805A1168, 0x400, context);
        result = fn_80398680(context);
        if (operation_result != 0)
            result = operation_result;
    }

    if (result == 0) {
        result = fn_80399BCC();
        if (result == 0)
            lbl_805A116C = 1;
    }

    return result;
}
