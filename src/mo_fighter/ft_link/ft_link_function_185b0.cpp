#include <types.h>
#pragma force_active on

struct FtLinkTable {
    unsigned char prefix[0x18];
    s32 base;
};

extern "C" void* fn_93_185B0(FtLinkTable* obj, void*, s32 sel) {
    return *(void**)((unsigned char*)obj + (sel - obj->base) * 4 + 0x34);
}
