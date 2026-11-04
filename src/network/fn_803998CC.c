#pragma force_active on
extern int fn_8039832C(void *, int, int);
extern int fn_80398680(void *);
extern int fn_80398BD8(void *, int, void *);
extern int lbl_8059FCD4, lbl_8059FCD8;
extern unsigned int *lbl_805A1168;
extern int lbl_805A116C, lbl_805A1170;

static inline unsigned int checksum(unsigned int *p)
{
    unsigned int sum = 0;
    int i;
    for (i = 0; i < 255; i++)
        sum += *p++;
    return sum;
}

int fn_803998CC(void)
{
    unsigned char context[0xA0];
    int result, operation_result;
    if (lbl_805A1170 == 0) return -9;
    if (lbl_805A116C == 0) return 0;
    lbl_805A1168[255] = checksum(lbl_805A1168);
    result = fn_8039832C(context, lbl_8059FCD4, 1);
    if (result == 0) {
        operation_result = fn_80398BD8(lbl_805A1168, 0x400, context);
        result = fn_80398680(context);
        if (operation_result != 0) result = operation_result;
        lbl_805A116C = 0;
    }
    if (result != 0) return result;
    result = fn_8039832C(context, lbl_8059FCD8, 1);
    if (result == 0) {
        operation_result = fn_80398BD8(lbl_805A1168, 0x400, context);
        result = fn_80398680(context);
        if (operation_result != 0) result = operation_result;
        lbl_805A116C = 0;
    }
    return result;
}