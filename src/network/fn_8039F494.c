#include <types.h>
#pragma force_active on

extern void *lbl_805A1170;
extern int lbl_805A1190;
extern char lbl_804921E0[];
extern char lbl_804921F0[];
extern void *fn_80397748(void *, unsigned char, unsigned long);
extern void fn_80397610(void *, const char *);
extern int fn_80397640(void *);
extern void fn_803977C8(void *, const char *);
extern void fn_80397DE0(void *, const char *, ...);
extern int fn_80398BD8(void *, int, int);
extern unsigned int fn_80399AC8(void);
extern int fn_8039A274(void);

typedef struct {
    char pad0[4];
    unsigned int flags;
    int size;
    unsigned int id;
    char pad10[0xba];
    unsigned short code;
} Data;

void fn_8039F494(Data *arg) {
    char tmp[16];
    void *buf;
    int flags = 0;
    int length;

    buf = lbl_805A1170;
    fn_80397748(buf, 0, 0x400);
    fn_80397610(buf, lbl_804921E0);
    if (fn_8039A274() == 0 && fn_80399AC8() != 0x48414541 && arg->id != 0x48414341) {
        arg->id = fn_80399AC8();
    }
    if (arg->flags & 4) {
        flags |= 1;
    }
    if (arg->flags & 8) {
        flags |= 2;
    }
    fn_80397748(tmp, 0, 0x10);
    fn_80397DE0(tmp, lbl_804921F0, flags, arg->id, arg->code);
    fn_803977C8(buf, tmp);
    length = fn_80397640(buf);
    if (fn_80398BD8(buf, length, lbl_805A1190) == 0) {
        arg->size += length;
    }
}