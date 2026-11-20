#include <types.h>
#include <so/so_module_accesser.h>
#include <nw4r/math/math_types.h>
#include <revolution/MTX/vec.h>

namespace {
#define PSVECScale LocalScale
#define PSVECNormalize LocalNormalize
#define PSVECAdd LocalAdd
#define PSVECDotProduct LocalDot
#include <../src/revolution/MTX/vec.c>
#pragma force_active on
#undef PSVECDotProduct
#undef PSVECAdd
#undef PSVECNormalize
#undef PSVECScale

inline void ScaleVector(Vec3f* out, const Vec3f* v, float scale) {
    LocalScale(reinterpret_cast<const Vec*>(v), reinterpret_cast<Vec*>(out),
               scale);
}
}

extern "C" {
extern const float lbl_96_rodata_48;

Vec3f* fn_96_BC54(Vec3f*, float, float, float);
void fn_96_14960(Vec3f*, const Vec3f*);
void fn_96_1497C(Vec3f*, const Vec3f*);
}

extern "C" void fn_96_146F0(void*, soModuleAccesser* accesser) {
    const float* constants = &lbl_96_rodata_48;
    soWorkManageModule* work = accesser->m_enumerationStart->m_workManageModule;
    soEffectModule* effect = accesser->m_enumerationStart->m_effectModule;
    bool flag = work->isFlag(0x22000013);
    bool old = work->isFlag(0x22000014);
    work->setFlag(flag, 0x22000014);

    Vec3f result;
    int handle;
    if (flag != old) {
        if (flag) {
            Vec3f pos, rot;
            work->setInt(
                effect->req(
                    (EfID)0x60008,
                    fn_96_BC54(&pos, constants[1], constants[1], constants[1]),
                    fn_96_BC54(&rot, constants[1], constants[1], constants[1]),
                    constants[0], 0, -1),
                0x20000004);
        } else {
            handle = work->getInt(0x20000004);
            if (handle) {
                effect->kill(handle, true, true);
                work->setInt(0, 0x20000004);
            }
        }
    }

    if (flag) {
        handle = work->getInt(0x20000004);
        if (handle) {
            Vec3f pos = accesser->m_enumerationStart->m_modelModule
                            ->getNodeGlobalPosition(0x190, false);
            fn_96_14960(&result, &pos);
            const float scale = accesser->m_enumerationStart->m_postureModule->getScale();
            Vec3f scaled;
            Vec3f temp;
            Vec3f* input =
                fn_96_BC54(&temp, constants[1], constants[2], constants[1]);
            ScaleVector(&scaled, input, scale);
            fn_96_1497C(&result, &scaled);
            effect->setPos(handle, &result);
        }
    }
}
