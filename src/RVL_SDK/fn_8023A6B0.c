#include <types.h>
#include <string.h>
#pragma force_active on

extern char lbl_80529CF8[];

void *fn_8022EFF8(s32);
void fn_80231FB0(void *, s32, s32);
void fn_8023DC04(void);
void fn_8023F4A8(u8, void *, u8);
void fn_80245D40(void);
void fn_8024629C(void *, void *);
void fn_802465B4(void *, void *);
void fn_802467FC(void);
void fn_802468B8(void *);
void fn_802468E0(void);

void fn_8023A6B0(void *arg0) {
    u8 *base;
    u8 *p;
    void *r;
    u8 t;
    u8 counter;
    u8 newState;
    u32 state;

    state = *(u32 *)((u8 *)arg0 + 0x10);
    if (state == 1) {
        base = (u8 *)lbl_80529CF8;
        switch (base[0x64E]) {
        case 0:
            base[0x64E] = 0;
            base[0x64F] = 5;
            fn_80231FB0(base + 0x574, 1, 4);
            fn_80245D40();
            return;
        case 1:
            counter = 4;
            newState = 2;
            base[0x64E] = newState;
            base[0x64F] = counter;
            if (base[0x64F] != 4) {
                base[0x64F] = 4;
                base[0x64E] = 4;
                fn_80231FB0(base + 0x574, 1, 4);
                fn_80245D40();
            } else {
                fn_80231FB0(base + 0x574, 1, 1);
                r = fn_8022EFF8(2);
                if (r != 0) {
                    fn_802468B8(r);
                }
            }
            p = (u8 *)lbl_80529CF8;
            memcpy(p + 0x648, p + 0x648, 3);
            t = p[0x64E];
            if (t != 0 && t != 1) {
                r = fn_8022EFF8(2);
                if (r != 0) {
                    fn_802465B4(r, p + 0x648);
                }
            }
            if ((p = (u8 *)lbl_80529CF8) != 0) {
                t = p[0x64E];
                if (t != 0 && t != 1) {
                    void *q = fn_8022EFF8(2);
                    if (q != 0) {
                        if (p != (u8 *)lbl_80529CF8) {
                            memset(p, 0, 0x20);
                            strncpy((char *)p, (char *)p, 0x1F);
                        }
                        fn_8024629C(q, p);
                    }
                }
            }
            fn_8023F4A8(((u8 *)lbl_80529CF8)[0x20], ((u8 *)lbl_80529CF8) + 0x22, ((u8 *)lbl_80529CF8)[0x21]);
            return;
        case 2:
            if (--base[0x64F] == 0) {
                base[0x64E] = 0;
                base[0x64F] = 5;
                fn_80231FB0(base + 0x574, 1, 4);
                fn_80245D40();
                return;
            }
            fn_80231FB0(base + 0x574, 1, 1);
            r = fn_8022EFF8(2);
            if (r != 0) {
                fn_802468B8(r);
            }
            return;
        case 3:
            if (--base[0x64F] == 0) {
                base[0x64E] = 0;
                base[0x64F] = 5;
                fn_80231FB0(base + 0x574, 1, 4);
                fn_80245D40();
                return;
            }
            fn_80231FB0(base + 0x574, 1, 1);
            fn_802467FC();
            fn_802468E0();
            fn_8023DC04();
            return;
        }
    } else if (state == 2) {
        void (*fn)(s32) = *(void (**)(s32))(lbl_80529CF8 + 0x5A8);
        *(void **)(lbl_80529CF8 + 0x5A8) = 0;
        if (fn != 0) {
            fn(0);
        }
    }
}