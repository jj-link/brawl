#include <types.h>
#include <revolution/DVD/dvdfs.h>
#pragma force_active on

extern "C" void fn_801C7288(void* obj, void* ptr, u32 size);

extern "C" s32 fn_801BEF40(void* obj, void* dst, u32 size) {
    u32 field_124 = *(u32*)((u8*)obj + 0x124);
    s32 field_120 = *(s32*)((u8*)obj + 0x120);
    if (size < field_124) {
        return 0;
    }
    u32 result = (u32)DVDReadPrio((DVDFileInfo*)((u8*)obj + 0x14c), dst, (s32)field_124, field_120, 2);
    if (result != field_124) {
        return 0;
    }
    fn_801C7288((void*)((u8*)obj + 0x108), dst, field_124);
    return 1;
}
