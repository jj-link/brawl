#include <types.h>
#include <ec/ec_mgr.h>
#pragma force_active on

extern "C" void fn_27_26399C(void*);
extern "C" float randf__Fv();
extern "C" const float lbl_72_rodata_80[];

extern "C" void fn_72_BB5C(void* self, s32 unused, const float* vec) {
    u8* s = reinterpret_cast<u8*>(self);
    float dec = vec[1];
    const float* k = reinterpret_cast<const float*>(reinterpret_cast<u32>(lbl_72_rodata_80));
    fn_27_26399C(*reinterpret_cast<void**>(s + 0x14c));

    float v = *reinterpret_cast<float*>(s + 0x170) - dec;
    *reinterpret_cast<float*>(s + 0x170) = v;
    if (v < k[0]) {
        *reinterpret_cast<float*>(s + 0x170) = k[0];
    }

    if (k[0] == *reinterpret_cast<float*>(s + 0x170)) {
        u8* p = *reinterpret_cast<u8**>(s + 0x164);
        if (*p != 2) {
            *p = 2;
        }
    }

    if (k[0] == *reinterpret_cast<float*>(s + 0x160)) {
        u32 handle = g_ecMgr->setEffect(static_cast<EfID>(0x540001));
        g_ecMgr->setParent(handle,
                           *reinterpret_cast<nw4r::g3d::ScnMdl**>(*reinterpret_cast<void**>(s + 0x44)),
                           static_cast<u32>(static_cast<u16>(*reinterpret_cast<u32*>(s + 0x184))),
                           false);
        *reinterpret_cast<float*>(s + 0x160) = k[12] + k[11] * randf__Fv();
    }
}
