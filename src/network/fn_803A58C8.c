#include <string.h>
#pragma force_active on
extern int fn_8039832C(void *, int, int);
extern int fn_80398680(void *);
extern int fn_80398818(void *, int, int);
extern int fn_80398BD8(void *, int, void *);
extern int lbl_8059FDE8;
extern int lbl_805A1170;
static inline int write_record(void *context, unsigned char *p, unsigned short index) {
    unsigned char *base = (unsigned char *)lbl_805A1170;
    unsigned char *header = base ? base + 0x3600 : 0;
    unsigned short count = *(unsigned short *)(header + 0x14);
    int result;
    int op;
    if (count > 0x78 || index >= count)
        result = -3;
    else
        result = fn_80398818(context, ((index << 9) & 0x1FFFE00) + 0x800, 0);
    if (result < 0)
        return result;
    memcpy((void *)(lbl_805A1170 + 0x3E00), p, 0x200);
    result = fn_80398BD8((void *)(lbl_805A1170 + 0x3E00), 0x200, context);
    op = 0;
    if (result < 0) op = result;
    return op;
}
static inline int write_header(void *context) {
    unsigned char *base;
    unsigned char *header;
    int result = fn_80398818(context, 0, 0);
    int op;
    if (result < 0) return result;
    base = (unsigned char *)lbl_805A1170;
    header = base ? base + 0x3600 : 0;
    result = fn_80398BD8(header, 0x800, context);
    op = 0;
    if (result < 0) op = result;
    return op;
}
int fn_803A58C8(unsigned short *arg0)
{
    unsigned char context[0xA0];
    unsigned short index;
    unsigned char *p;
    unsigned char *base;
    unsigned char *header;
    unsigned short count;
    int result;
    int op_result;
    int close_result;
    result = fn_8039832C(context, lbl_8059FDE8, 4);
    if (result < 0)
        return result;
    index = *arg0;
    p = (unsigned char *)(lbl_805A1170 + 0x3E00);
    memset(p, 0, 0x200);
    p[2] = 0xFF;
    *(unsigned short *)p = index;
    memset((unsigned char *)lbl_805A1170 + ((index * 0x10) & 0xFFFF0) + 0x3680, 0, 0x10);
    op_result = write_record(context, p, *(unsigned short *)p);
    if (op_result >= 0) {
        memset((unsigned char *)lbl_805A1170 + (*arg0 * 0x10) + 0x3680, 0, 0x10);
        op_result = write_header(context);
    }
    close_result = fn_80398680(context);
    if (op_result != 0)
        close_result = op_result;
    return close_result;
}