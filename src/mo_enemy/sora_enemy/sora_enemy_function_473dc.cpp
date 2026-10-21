#include <types.h>
#pragma force_active on

class soModuleAccesser;

class soValueAccesser {
public:
    static void* getConstantIndefinite(soModuleAccesser* acc, u32 id, u32 index);
};

extern u8 lbl_41_bss_504[];

extern "C" void* fn_41_473DC(soModuleAccesser* self, u32 a) {
    void* p = soValueAccesser::getConstantIndefinite(self, a, 0);
    *(void**)(lbl_41_bss_504 + 0x0) = p;
    if (*(s32*)((u8*)p + 0x74) > 0x10000 - 0x5421) {
        void* q = soValueAccesser::getConstantIndefinite(self, *(u32*)((u8*)p + 0x74), 0);
        *(void**)(lbl_41_bss_504 + 0x28) = q;
    }
    if (*(u32*)(lbl_41_bss_504 + 0x8) == 0xFFFFFFFF) {
        *(u32*)(lbl_41_bss_504 + 0x8) = *(u32*)((u8*)(*(void**)lbl_41_bss_504) + 0x1C);
    }
    return *(void**)lbl_41_bss_504;
}
