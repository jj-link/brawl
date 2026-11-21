#include <types.h>
#include <ec/ec_mgr.h>
#include <nw4r/math/math_types.h>

#pragma force_active off
namespace {
#define PSVECScale LocalScale
#define PSVECNormalize LocalNormalize
#define PSVECAdd LocalAdd
#define PSVECDotProduct LocalDot
#include <../src/revolution/MTX/vec.c>
#undef PSVECDotProduct
#undef PSVECAdd
#undef PSVECNormalize
#undef PSVECScale

inline void scaleVector(Vec* vec, f32 scale) {
    LocalScale(vec, vec, scale);
}
}
#pragma force_active on

extern "C" f32 lbl_27_rodata_C58;

class Object_vptr_0 {
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
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual f32 slot22();
};

struct Fn986Inner {
    char pad00[0xC];
    Object_vptr_0* obj;
};

struct Fn986Mid {
    char pad00[0xD8];
    Fn986Inner* inner;
};

struct Fn986Self {
    char pad00[0x44];
    Fn986Mid* mid;
    u32 unk48;
    char pad4C[0x128 - 0x4C];
    union {
        void (Fn986Self::*pmf)(u32);
        struct {
            char pad0[0xC];
            u8 unk134;
            u8 unk135;
        } tail;
    };
};

extern "C" s32 fn_27_986B0(Fn986Self* self, s32 id, const Vec3f* p1,
                            const Vec3f* p2, u32 flags, s32 idx, f32 scale) {
    nw4r::math::VEC3 pos(scale, scale, scale);

    f32 f31 = self->mid->inner->obj->slot22();

    (self->*self->pmf)(self->unk48 | flags);
    if (idx >= 0) {
        g_ecMgr->preSetAnmIdx(0, 0, 0, 0, idx, 0);
    }
    if ((((u32)self->tail.unk135 >> 2) & 1U) == 1U &&
        lbl_27_rodata_C58 != f31) {
        scaleVector((Vec*)&pos, f31);
    }
    s32 handle = g_ecMgr->setEffect((EfID)id, p1, p2, (Vec3f*)&pos);
    if (handle != 0) {
        u32 rate = self->tail.unk134;
        if (rate != 1) {
            g_ecMgr->setSlowRate(handle, rate);
        }
    }
    g_ecMgr->popCurrentGroup();
    g_ecMgr->preSetAnmIdx(0, 0, 0, 0, 0, 0);
    return handle;
}
