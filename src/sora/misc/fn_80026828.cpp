#include <gf/gf_module.h>
#include <revolution/BASE/PPCArch.h>
#include <cstring>
#pragma force_active on

extern "C" int fn_801DDC4C(int, int);

struct ModuleImport {
    u32 id;
    u32 offset;
};

extern "C" void* fn_80026828(void* output, gfModuleHeader* source) {
    if (output == 0) {
        PPCHalt();
    }
    void* bss;
    u32 importSize;
    u32 importOffset;
    gfModuleHeader* header = (gfModuleHeader*)(((u32)output + 0x2B) & ~31);
    importSize = source->impSize;
    importOffset = source->impOffset;
    bss = (void*)(((u32)header + source->commandOffset + 31) & ~31);
    memcpy(header, source, source->commandOffset);
    s32 delta = (u8*)source - (u8*)header;
    header->relOffset = delta + source->relOffset;
    header->impOffset = delta + source->impOffset;
    ModuleImport* cur = (ModuleImport*)((u8*)source + source->impOffset);
    ModuleImport* end = (ModuleImport*)((u8*)cur + importSize);
    for (; cur < end; ++cur) {
        cur->offset += delta;
    }
    header->getTextSectionAddr();
    if (output != 0) {
        *(gfModuleHeader**)output = header;
        *((s8*)output + 8) &= ~0xC0;
        *(void**)((u8*)output + 4) = bss;
        fn_801DDC4C((int)header, (int)bss);
    }
    header->impOffset = (u32)header + importOffset;
    cur = (ModuleImport*)header->impOffset;
    end = (ModuleImport*)((u8*)cur + importSize);
    for (; cur < end; ++cur) {
        cur->offset += (u32)header;
    }
    return output;
}
