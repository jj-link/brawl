#include <string.h>
#pragma force_active on

extern int fn_803A367C(void *, unsigned short *);
extern int fn_8039832C(void *, int, int);
extern int fn_80398680(void *);
extern int fn_80398818(void *, int, int);
extern int fn_80398A08(void *, int, void *);
extern int fn_803A58C8(void *);
extern int lbl_8059FDE8;
extern int lbl_805A1170;

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

    tbl = (unsigned char *) lbl_805A1170;
    b0 = (tbl != 0) ? (tbl + 0x3600) : ((unsigned char *) 0);
    if (b0 == 0) return -9;
    b1 = (tbl != 0) ? (tbl + 0x3600) : ((unsigned char *) 0);
    count = *((unsigned short *) (b1 + 0x14));
    if ((index >= count) || (index == 0xFFFF)) {
        result = -3;
    } else {
        b2 = (tbl != 0) ? (tbl + 0x3600) : ((unsigned char *) 0);
        result = 0;
        if (*((int *) ((b2 + ((index * 0x10) & 0xFFFF0)) + 0x80)) == 0) {
            result = -0xD;
        }
    }
    if (result < 0) return result;
    result = fn_8039832C(context, lbl_8059FDE8, 10);
    if (result < 0) return result;
    tbl = (unsigned char *) lbl_805A1170;
    b1 = (tbl != 0) ? (tbl + 0x3600) : ((unsigned char *) 0);
    count = *((unsigned short *) (b1 + 0x14));
    if ((count > 0x78) || (index >= count)) {
        result = -3;
    } else {
        result = fn_80398818(context, ((index << 9) & 0x01FFFE00) + 0x800, 0);
    }
    if (result < 0) {
        op_result = result;
    } else {
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
    unsigned short value;
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

int fn_803A4110(void)
{
    unsigned short out;
    int state[6];
    unsigned char buf[0x200];
    unsigned char *bp;
    unsigned char *tbl;
    unsigned char *b0;
    unsigned int count;
    int result;

    memset(state, 0, 0x18);
    state[1] = 0x7FFFFFFF;
    state[2] = 0x80000001;
    state[0] = 0;
    state[3] = -1;
    state[4] = 1;
    state[5] = 1;
    if (state[0] < 0) return 0;
    goto test;
body:
    tbl = (unsigned char *) lbl_805A1170;
    b0 = (tbl != 0) ? (tbl + 0x3600) : ((unsigned char *) 0);
    count = *((unsigned short *) (b0 + 0x12));
    if (out >= count) goto exit;
test:
    result = fn_803A367C(state, &out);
    if (result == 0) goto body;
exit:
    if (result >= 0) {
        bp = buf;
        result = read_record(bp, out);
        if (result < 0) return result;
        bp = buf;
        result = clear_record((unsigned short *)bp);
        if (result < 0) return result;
    } else if (result == -0xF) result = -2;
    return result;
}