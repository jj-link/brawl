#include <gf/gf_module.h>
#include <gf/gf_memory_pool.h>
#include <revolution/BASE/PPCArch.h>
#include <revolution/OS/OSError.h>
#include <cstring>
#pragma force_active on

extern "C" void fn_800260B4(void*);
extern "C" int fn_801DDC4C(int, int);
extern char lbl_80422C68[];
extern char lbl_80422CAC[];

struct ModuleImport {
    u32 id;
    u32 offset;
};

gfModule* gfModule::create(void* heap, void* buffer, size_t size) {
    u32 total = ((gfModuleHeader*)buffer)->bssSize + ((gfModuleHeader*)buffer)->commandOffset;
    u32 extra = total + 0x40;
    gfModule* module = (gfModule*)gfMemoryPool::alloc(heap, extra + 0x8C, 0x20);
    if (module == NULL) {
        fn_800260B4(heap);
        OSReport(lbl_80422C68, extra + 0x8C, extra, size);
        PPCHalt();
    }
    gfModuleHeader* source = (gfModuleHeader*)buffer;
    void* bss;
    u32 importSize = source->impSize;
    u32 importOffset = source->impOffset;
    gfModuleHeader* header = (gfModuleHeader*)(((u32)module + 0x2B) & ~31);
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
    OSReport(lbl_80422CAC, header, extra + 0x8C, header->getTextSectionAddr());
    if (module != NULL) {
        *((s8*)module + 8) &= ~0xC0;
        *(gfModuleHeader**)module = header;
        *(void**)((u8*)module + 4) = bss;
        fn_801DDC4C((int)header, (int)bss);
    }
    header->impOffset = (u32)header + importOffset;
    cur = (ModuleImport*)header->impOffset;
    end = (ModuleImport*)((u8*)cur + importSize);
    for (; cur < end; ++cur) {
        cur->offset += (u32)header;
    }
    return module;
}
