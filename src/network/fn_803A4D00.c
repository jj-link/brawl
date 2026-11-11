#pragma force_active on
extern int fn_8039832C(void *, int, int);
extern int fn_80398680(void *);
extern int fn_80398818(void *, int, int);
extern int fn_80398A08(void *, int, void *);
extern int fn_80398BD8(void *, int, void *);
extern int fn_80398DB0(void *, int *);
extern int lbl_8059FDE8;
extern int lbl_805A1170;
static inline int read_header(void *context, int *op)
{
    int result = fn_80398818(context, 0, 0);
    if (result < 0)
        return result;
    result = fn_80398A08((void *)(lbl_805A1170 + 0x3600), 0x800, context);
    if (result < 0)
        *op = result;
    return *op;
}
int fn_803A4D00(void)
{
    unsigned char context[0xA0];
    unsigned char context2[0x9C];
    int sp8;
    int result;
    int op_result;
    unsigned char *header;
    op_result = 0;
    sp8 = 0;
    result = fn_8039832C(context, lbl_8059FDE8, 2);
    if (result < 0)
        return result;
    result = read_header(context, &op_result);
    if (result < 0)
        return result;
    result = fn_80398DB0(context, &sp8);
    op_result = result;
    if (result >= 0) {
        header = (unsigned char *)lbl_805A1170;
        header = header ? header + 0x3600 : 0;
        if (*(unsigned short *)(header + 0x14) == 0) {
            unsigned short count = *(unsigned short *)(header + 0x10);
            if (count != 0) {
                *(unsigned short *)(header + 0x14) = count;
                if (*(unsigned short *)(header + 0x10) > 0x20)
                    *(unsigned short *)(header + 0x10) = 0x20;
                if (fn_8039832C(context2, lbl_8059FDE8, 4) >= 0) {
                    if (fn_80398818(context2, 0, 0) >= 0) {
                        unsigned char *base = (unsigned char *)lbl_805A1170;
                        base = base ? base + 0x3600 : 0;
                        fn_80398BD8(base, 0x800, context2);
                    }
                    fn_80398680(context2);
                }
            }
        }
        if (*(unsigned short *)(header + 0x14) < 1 ||
            *(unsigned short *)(header + 0x12) < 1 ||
            *(unsigned short *)(header + 0x14) < *(unsigned short *)(header + 0x12))
            op_result = -0xE;
        else
            op_result = 0;
    }
    result = fn_80398680(context);
    if (op_result != 0)
        result = op_result;
    return result;
}