#include <types.h>
#pragma force_active on
extern "C" int __cntlzw(unsigned int);
extern "C" void fn_80281E88(void);
extern "C" void fn_8027B75C(void);
extern "C" void fn_8027BC94(void);
extern "C" void fn_8027E27C(int);
extern s8 lbl_805A0EA0;
extern s8 lbl_805A0EE4;
extern void (*lbl_805A0EE0)(void);
class Object_vptr_0 {
public:
    virtual void slot0(int);
    u16 m4;
    s16 m6;
};
extern Object_vptr_0* lbl_805A0EB0;
extern Object_vptr_0* lbl_805A0EE8;
extern "C" int fn_8027BCE0(void) {
    if ((s8)((unsigned int)__cntlzw(lbl_805A0EA0 - 1) >> 5) != 0) {
        fn_80281E88();
        fn_8027B75C();
        if (lbl_805A0EE4 != 0 && lbl_805A0EE0 != 0) {
            lbl_805A0EE0();
            lbl_805A0EE4 = 0;
        }
        Object_vptr_0* p = lbl_805A0EB0;
        if (p != 0 && p->m4 != 0) {
            p->m6 = p->m6 - 1;
            if (p->m6 == 0 && p != 0) {
                p->slot0(1);
            }
        }
        lbl_805A0EB0 = 0;
        Object_vptr_0* q = lbl_805A0EE8;
        if (q != 0 && q->m4 != 0) {
            q->m6 = q->m6 - 1;
            if (q->m6 == 0 && q != 0) {
                q->slot0(1);
            }
        }
        lbl_805A0EE8 = 0;
        fn_8027BC94();
        fn_8027E27C(0);
        lbl_805A0EA0 = 0;
    }
    return 0;
}