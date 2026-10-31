#include <types.h>
#pragma force_active on
#pragma global_optimizer off

extern s32 lbl_805A0178;
extern s32 lbl_805A01B8;
extern s32 lbl_805A01B0;
extern s32 lbl_805A01B4;
extern char lbl_804541B4[];
extern s32 lbl_805A0198;

extern "C" {
u32 getMaxFreeSize__13gfHeapManagerFQ25Heaps8HeapType(int type);
void* alloc__13gfHeapManagerFQ25Heaps8HeapTypeUl(int type, u32 size);
s32 getFileSize__8gfFileIOFPCc(const char* name);
void readRequestCached__14gfFileIOHandleFPCcPvii(
    void* self, const char* name, void* buffer, s32 a, s32 b);
}

extern "C" s32 fn_8006C950(s32 type)
{
    if (lbl_805A0178 != 0) {
        return 1;
    }

    char* name = lbl_804541B4;
    s32 size =
        (s32)getMaxFreeSize__13gfHeapManagerFQ25Heaps8HeapType(type) - 0x80;
    lbl_805A01B8 = size;

    void* p = alloc__13gfHeapManagerFQ25Heaps8HeapTypeUl(type, size);
    lbl_805A01B0 = (s32)p;
    lbl_805A0178 = (s32)p;

    lbl_805A01B4 = (lbl_805A01B0 + lbl_805A01B8) -
                   getFileSize__8gfFileIOFPCc(name);
    readRequestCached__14gfFileIOHandleFPCcPvii(
        (void*)&lbl_805A0198, name, (void*)lbl_805A01B4, 0, 0);
    return 1;
}
