#pragma force_active on
typedef unsigned char u8;
typedef int s32;
typedef signed char s8;

extern void *fn_8022EFF8(int);
extern void fn_8022F0E0(void *);
extern void fn_802319E4(int, const char *);
extern void fn_80231FB0(void *, int, int);
extern void fn_80244C78(void *, void *, u8);
extern void fn_80244CD8(void *, void *, s8);
extern void *fn_8024E568(void *);
extern void *fn_8024E73C(void *);
extern u8 fn_8024E854(void);
extern u8 lbl_8052CDC0[];
extern char lbl_80483840[];
extern char lbl_80483860[];

void fn_8024C3AC(void *arg0) {
    void *p = fn_8022EFF8(2);
    if (p != 0) {
        void *entry = fn_8024E73C(arg0);
        if (entry == 0) {
            entry = fn_8024E568(arg0);
            if (entry == 0) {
                fn_80244CD8(p, arg0, 0x14);
                if (lbl_8052CDC0[0] >= 1)
                    fn_802319E4(0x80000, lbl_80483840);
            } else {
                u8 val = fn_8024E854();
                *(u8 *)((u8 *)entry + 0x30) = val;
                fn_80244C78(p, arg0, val);
                *(s32 *)((u8 *)entry + 4) = 3;
                fn_80231FB0((u8 *)entry + 0x10, 2, 0x3C);
            }
        } else {
            s32 state = *(s32 *)((u8 *)entry + 4);
            if (state == 3 || state == 1) {
                fn_80244C78(p, arg0, *(u8 *)((u8 *)entry + 0x30));
                *(s32 *)((u8 *)entry + 4) = 3;
            } else if (state == 5) {
                fn_80244CD8(p, arg0, 0x15);
            } else {
                if (lbl_8052CDC0[0] >= 1)
                    fn_802319E4(0x80000, lbl_80483860);
                fn_8022F0E0(p);
            }
        }
    }
}