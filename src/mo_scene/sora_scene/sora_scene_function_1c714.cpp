#include <types.h>
#pragma force_active on

struct Fn1Buf {
    s32 a, b, c, d;
};

extern "C" {
void* getGlobalRecordMenuDatap__10GameGlobalFv(void* global);
void readRequest__14gfFileIOHandleFPCcQ25Heaps8HeapTypeii(void* self, const char* name, int heap, int a, int b);
s32 fn_28_0(Fn1Buf* p);
extern void* g_GameGlobal;
extern char lbl_1_data_5F94[];
extern char lbl_1_data_5FC0[];

void fn_1_1C714(u8* self) {
    u8* rec = (u8*)getGlobalRecordMenuDatap__10GameGlobalFv(g_GameGlobal);
    if (!((rec[0x28] >> 7) & 1)) {
        readRequest__14gfFileIOHandleFPCcQ25Heaps8HeapTypeii(self + 0x14, lbl_1_data_5F94, 0x2b, 0, 0);
    } else {
        readRequest__14gfFileIOHandleFPCcQ25Heaps8HeapTypeii(self + 0x14, lbl_1_data_5FC0, 0x2b, 0, 0);
    }
    Fn1Buf buf = {0, 0, 1, -1};
    if (*(void**)(self + 0x10) != 0) {
        buf.b = *(s32*)(*(u8**)(self + 0x10) + 8);
        buf.c = *(s32*)(*(u8**)(self + 0x10) + 0xc);
    }
    *(s32*)(self + 0x8) = fn_28_0(&buf);
    *(s32*)(self + 0x1c) = 0;
}
}
