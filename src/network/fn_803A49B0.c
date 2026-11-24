#pragma force_active on
extern int fn_8039832C(void *, int, int);
extern int fn_80398680(void *);
extern int fn_80398818(void *, int, int);
extern int fn_80398A08(void *, int, void *);
extern int fn_803A58C8(unsigned short *);
extern int lbl_8059FDE8;
extern int lbl_805A1170;

static inline int valid_record(unsigned int index)
{
    unsigned char *tbl = (unsigned char *)lbl_805A1170;
    unsigned char *b1 = tbl ? tbl + 0x3600 : 0;
    unsigned char *b2;
    int result;
    if (index >= *(unsigned short *)(b1 + 0x14) || index == 0xffff)
        result = -3;
    else {
        b2 = tbl ? tbl + 0x3600 : 0;
        result = 0;
        if (*(int *)(b2 + ((index * 0x10) & 0xffff0) + 0x80) == 0)
            result = -13;
    }
    return result;
}

static inline int read_record(void *bp, unsigned int index)
{
    unsigned char context[0xA0];
    unsigned char *tbl;
    unsigned char *b0;
    unsigned char *b1;
    unsigned char *b2;
    unsigned int count;
    int result;
    int op_result;
    int close_result;
    tbl = (unsigned char *)lbl_805A1170;
    b0 = tbl ? tbl + 0x3600 : 0;
    if (b0 == 0) return -9;
    b1 = tbl ? tbl + 0x3600 : 0;
    count = *(unsigned short *)(b1 + 0x14);
    if (index >= count || index == 0xffff) result = -3;
    else {
        b2 = tbl ? tbl + 0x3600 : 0;
        result = 0;
        if (*(int *)(b2 + ((index * 0x10) & 0xffff0) + 0x80) == 0) result = -13;
    }
    if (result < 0) return result;
    result = fn_8039832C(context, lbl_8059FDE8, 10);
    if (result < 0) return result;
    tbl = (unsigned char *)lbl_805A1170;
    b1 = tbl ? tbl + 0x3600 : 0;
    count = *(unsigned short *)(b1 + 0x14);
    if (count > 0x78 || index >= count) result = -3;
    else result = fn_80398818(context, ((index << 9) & 0x1fffe00) + 0x800, 0);
    if (result < 0) op_result = result;
    else {
        result = fn_80398A08(bp, 0x200, context);
        op_result = 0;
        if (result < 0) op_result = result;
    }
    close_result = fn_80398680(context);
    if (op_result != 0) close_result = op_result;
    return close_result;
}

static inline int clear_record(unsigned short *arg0)
{
    int result;
    unsigned char *tbl;
    unsigned char *context;
    int one;
    tbl = (unsigned char *)lbl_805A1170;
    context = tbl != 0 ? tbl + 0x3600 : 0;
    if (arg0 == 0) result = -3;
    else if (context == 0) result = -9;
    else {
        if (*arg0 != 0xffff && *arg0 >= *(unsigned short *)(context + 0x14)) result = -3;
        else result = 0;
    }
    if (result != 0) return result;
    result = fn_803A58C8(arg0);
    if (result < 0) return result;
    one = 0x10000;
    *arg0 = one - 1;
    return result;
}

int fn_803A49B0(unsigned short *arg0, int arg1)
{
    unsigned char buf[0x200];
    unsigned char *bp;
    unsigned char *tbl;
    unsigned char *b0;
    unsigned short i;
    int result;
    for (i = 0; i < arg0[10]; i++) {
        if (valid_record(i) == 0 && arg1 != 0) {
            bp = buf;
            result = read_record(bp, i);
            if (result < 0) {
                bp = buf;
                clear_record((unsigned short *)bp);
            } else {
                tbl = (unsigned char *)lbl_805A1170;
                b0 = tbl ? tbl + 0x3600 : 0;
                if (i >= *(unsigned short *)(b0 + 0x12) && *(short *)(buf + 0x18) == 0) {
                    bp = buf;
                    clear_record((unsigned short *)bp);
                }
            }
        }
    }
    return 0;
}
