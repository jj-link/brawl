#include <internal/mem.h>
#pragma force_active on
extern unsigned char lbl_80529CF8[];
extern const char lbl_80481A60[];
extern void *fn_8023A0F0(void *);
extern void fn_802319E4(int, const char *);
extern void *fn_8022EFF8(int);
extern void fn_80244CD8(void *, void *, signed char);
extern void fn_8024C3AC(void *);
typedef unsigned char (*Callback)(void *, void *);

void fn_802404EC(void *arg0, void *arg1)
{
    unsigned char *obj;
    void *p;

    if (lbl_80529CF8[0x197A] != 0 &&
        ((obj = fn_8023A0F0(arg0)) == 0 || !(obj[0x76] & 0x10))) {
        if (lbl_80529CF8[0x27C0] >= 4U) {
            fn_802319E4(0xD0003, lbl_80481A60);
        }
        p = fn_8022EFF8(2);
        if (p != 0) {
            fn_80244CD8(p, arg0, 0xF);
        }
    } else if (*(Callback *)(lbl_80529CF8 + 0x1934) != 0 &&
               (*(Callback *)(lbl_80529CF8 + 0x1934))(arg0, arg1) == 0) {
        p = fn_8022EFF8(2);
        if (p != 0) {
            fn_80244CD8(p, arg0, 0xF);
        }
    } else {
        memcpy(lbl_80529CF8 + 0x27B4, arg0, 6);
        memcpy(lbl_80529CF8 + 0x27BA, arg1, 3);
        fn_8024C3AC(arg0);
    }
}
