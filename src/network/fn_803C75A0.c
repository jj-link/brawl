#include <types.h>
#pragma force_active on

extern void fn_803A976C(s32 a0, s32 a1, s32 a2);

struct X {
    s32 a;
    s32 b;
};
extern void fn_803AB0F0(struct X *ptr, s32 a1);

void fn_803C75A0(s32 arg0, s32 arg1) {
    struct X v;

    fn_803A976C(arg0, 0, arg1);
    v.a = -1;
    v.b = -1;
    fn_803AB0F0(&v, arg0);
}
