#include <string.h>
#pragma force_active on

typedef struct {
    unsigned int words[0x174 / 4];
} SvlData;

extern int fn_80352AB8(void);
extern int fn_80352AF4(void);
extern int fn_80352B0C(void);
extern char *fn_80352BE0(void);
extern void fn_8033524C(int, int);
extern void fn_80335638(int, const char *, ...);
extern void fn_80352418(void);
extern SvlData *lbl_805A1030;
extern char lbl_8048E660[];

int fn_80358764(void)
{
    SvlData *data;
    int error;

    if (fn_80352AB8() != 0) {
        if (fn_80352AF4() != 0) {
            data = lbl_805A1030;
            if (data != 0) {
                *data = *(SvlData *)fn_80352BE0();
            }
            if (strlen((char *)data + 0x45) == 0) {
                fn_8033524C(0x10, -0x5e25);
                return 4;
            }
            return 3;
        }
        error = fn_80352B0C();
        switch (error) {
        case -20110:
        case -20109:
        case -20108:
        case -20107:
        case -20106:
        case -20105:
        case -20104:
        case -20103:
        case -20102:
        case -20101:
        case -20100:
            error = error - 4000;
            break;
        default:
            if (error <= -20111 && error >= -20999) {
                error = error - 4000;
            } else if (error <= -23000 && error >= -23999) {
                error = error - 2000;
            } else {
                fn_80335638(0x01000000, lbl_8048E660, error);
            }
            break;
        }
        fn_8033524C(0x10, error);
        return 4;
    }
    fn_80352418();
    return 2;
}
