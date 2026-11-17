#pragma optimizewithasm on

#include <ec/ec_mgr.h>
#include <ec/ec_trace_mgr.h>
#include <so/so_module_accesser.h>
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

inline nw4r::math::VEC3 ScaleVector(const nw4r::math::VEC3& value, float scale) {
    nw4r::math::VEC3 result;
    LocalScale(reinterpret_cast<const Vec*>(&value),
               reinterpret_cast<Vec*>(&result), scale);
    return result;
}
}
#pragma force_active on

struct EffectObjectAccess {
    u8 pad[0x44];
    soModuleAccesser* access;
    u32 flags;
    u8 pad4c[0xdc];
    void (EffectObjectAccess::*callback)(u32);
};

extern "C" {
extern const float lbl_27_rodata_C58[];
u32 fn_80061160(
    ecMgr*, u16, s32, nw4r::g3d::ScnMdl*, u16, u16, u8, u8, float);
}

extern "C" u32 fn_27_99F08(
    EffectObjectAccess* self,
    s32 arg1,
    s32 arg2,
    s32 arg3,
    u32 arg4,
    Vec3f* arg5,
    Vec3f* arg6,
    u32 arg7,
    float scale,
    float time,
    u32 effect,
    u32 node,
    Vec3f* position,
    Vec3f* rotation,
    u8 arg18,
    u8 arg1C)
{
    const float* const& rd = lbl_27_rodata_C58;
    nw4r::g3d::ScnMdl* model =
        self->access->getModelModule().getScnMdl();

    float divisor = rd[8];
    nw4r::math::VEC3 scaled;
    nw4r::math::VEC3 intermediate = ScaleVector(
        *reinterpret_cast<const nw4r::math::VEC3*>(rotation), rd[7]);
    LocalScale(
        reinterpret_cast<const Vec*>(&intermediate),
        reinterpret_cast<Vec*>(&scaled),
        rd[0] / divisor);

    (self->*self->callback)(self->flags | (arg7 | 4));

    u32 firstNode =
        self->access->getModelModule().getRealNodeId(arg1);
    u32 secondNode =
        self->access->getModelModule().getRealNodeId(arg2);

    u32 trace = fn_80061160(
        g_ecMgr,
        arg4,
        arg3,
        model,
        static_cast<u16>(firstNode),
        static_cast<u16>(secondNode),
        arg18,
        arg1C,
        time);

    reinterpret_cast<ecTraceMgr*>(
        reinterpret_cast<u8*>(g_ecMgr) + 0x98)
        ->setOffset(trace, *arg5, *arg6);

    Vec3f attachScale(scale, scale, scale);
    reinterpret_cast<ecTraceMgr*>(
        reinterpret_cast<u8*>(g_ecMgr) + 0x98)
        ->setAttachEffect(
            trace,
            static_cast<EfID>(effect),
            model,
            static_cast<u16>(node),
            position,
            reinterpret_cast<const Vec3f*>(&scaled),
            &attachScale);

    g_ecMgr->popCurrentGroup();
    return trace;
}
