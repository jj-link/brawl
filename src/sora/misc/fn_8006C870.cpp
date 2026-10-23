#include <types.h>
#pragma force_active on
#pragma global_optimizer off

extern s32 lbl_805A0174;
extern s32 lbl_805A0194;
extern s32 lbl_805A01A4;
extern s32 lbl_805A01A8;
extern s32 lbl_805A01AC;
extern char lbl_80454198[];

extern "C" {
u32 getMaxFreeSize__13gfHeapManagerFQ25Heaps8HeapType(int type);
void* alloc__13gfHeapManagerFQ25Heaps8HeapTypeUl(int type, u32 size);
s32 getFileSize__8gfFileIOFPCc(const char* name);
void readRequestCached__14gfFileIOHandleFPCcPvii(
    void* self, const char* name, void* buf, s32 a, s32 b);
}

extern "C" s32 fn_8006C870(s32 type)
{
    if (lbl_805A0174 != 0) {
        return 1;
    }

    char* name = lbl_80454198;
    s32 size =
        (s32)getMaxFreeSize__13gfHeapManagerFQ25Heaps8HeapType(type) - 0x80;
    lbl_805A01AC = size;

    void* p = alloc__13gfHeapManagerFQ25Heaps8HeapTypeUl(type, size);
    lbl_805A01A4 = (s32)p;
    lbl_805A0174 = (s32)p;

    lbl_805A01A8 = (lbl_805A01A4 + lbl_805A01AC) -
                   getFileSize__8gfFileIOFPCc(name);
    readRequestCached__14gfFileIOHandleFPCcPvii(
        (void*)&lbl_805A0194, name, (void*)lbl_805A01A8, 0, 0);
    return 1;
}
