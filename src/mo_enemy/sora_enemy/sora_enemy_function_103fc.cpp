#include <so/so_value_accesser.h>
#include <so/so_module_accesser.h>
#include <types.h>
#pragma force_active on

struct Outer {
    char pad[0x3C];
    soModuleAccesser* acc;
};

struct S32Pair {
    s32 a;
    s32 b;
};

class EnemyVCallTarget {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
};

extern "C" {
extern const float lbl_41_rodata_BE0[];
void* fn_41_159AC(s32 p1, s32 p2);
f32 fn_41_15A00(s32* vec);
void fn_41_102DC(Outer* self, s32 arg1, f32 farg0, f32 farg1, s32 arg2, s32 arg3);

f32 fn_41_103FC(Outer* self, s32 arg1, EnemyVCallTarget* arg2, f32 farg0, S32Pair* arg3, unsigned arg4, s32 arg5, f32 farg1, bool arg6) {
    const float* tbl = lbl_41_rodata_BE0;
    f32* p;
    if (arg4 == 1) {
        p = (f32*)fn_41_159AC(arg1, 5);
    } else {
        p = (f32*)fn_41_159AC(arg1, 2);
    }
    p[1] = farg0;
    p[7] = farg0;
    arg2->slot9();
    S32Pair tmp = *arg3;
    f32 ret = fn_41_15A00((s32*)&tmp);
    p[9] = ret;

    if (arg4 == 1) {
        f32* q = (f32*)fn_41_159AC(arg1, 6);
        f32 v = farg0 * soValueAccesser::getValueFloat(self->acc, 0xBC2, 0);
        if (v < soValueAccesser::getValueFloat(self->acc, 0xBC3, 0)) {
            v = soValueAccesser::getValueFloat(self->acc, 0xBC3, 0);
        }
        if (v > soValueAccesser::getValueFloat(self->acc, 0xBC4, 0)) {
            v = soValueAccesser::getValueFloat(self->acc, 0xBC4, 0);
        }
        v = v * soValueAccesser::getValueFloat(self->acc, 0xBED, 0);
        q[1] = v;
    }

    if (arg6 == 1) {
        fn_41_159AC(arg1, 0xA);
        fn_41_159AC(arg1, 0xC);
        fn_41_159AC(arg1, 0xB);
        fn_41_159AC(arg1, 0xD);
        f32 t = p[1] * soValueAccesser::getValueFloat(self->acc, 0xBC8, 0);
        f32 v29 = farg1;
        fn_41_102DC(self, arg1, farg1, t, 0xC, 0xD);
        if (p[9] <= tbl[4] && arg5 != 0x169) {
            v29 = farg1 * tbl[3];
        }
        fn_41_102DC(self, arg1, v29, t, 0xA, 0xB);
    }

    if (arg4 == 1) {
        unsigned z = 0;
        fn_41_103FC(self, arg1, arg2, farg0, arg3, z, arg5, farg1, z);
    }
    return ret;
}
}