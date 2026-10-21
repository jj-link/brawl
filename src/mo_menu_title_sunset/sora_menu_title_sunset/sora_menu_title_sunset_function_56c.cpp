#include <types.h>
#pragma force_active on

namespace Heaps {
	enum HeapType {
		HOME_DATA = 0x2b
	};
};

extern "C" {
struct gfFileIOHandle {
    u8 unk0[0x44];
};

void readRequest__14gfFileIOHandleFPCcQ25Heaps8HeapTypeii(gfFileIOHandle* self, const char* name, Heaps::HeapType heap, int a, int b);
void* getGlobalRecordMenuDatap__10GameGlobalFv(void* global);
extern void* g_GameGlobal;
extern char lbl_25_data_0[];

void fn_25_56C(u8* self) {
    char* base = lbl_25_data_0;
    u8* rec = (u8*)getGlobalRecordMenuDatap__10GameGlobalFv(g_GameGlobal);
    if (!((rec[0x28] >> 7) & 1)) {
        readRequest__14gfFileIOHandleFPCcQ25Heaps8HeapTypeii((gfFileIOHandle*)(self + 0x44), base + 0x10, Heaps::HOME_DATA, 0, 0);
    } else {
        readRequest__14gfFileIOHandleFPCcQ25Heaps8HeapTypeii((gfFileIOHandle*)(self + 0x44), base + 0x38, Heaps::HOME_DATA, 0, 0);
    }
    readRequest__14gfFileIOHandleFPCcQ25Heaps8HeapTypeii((gfFileIOHandle*)(self + 0x48), base + 0x64, Heaps::HOME_DATA, 0, 0);
    readRequest__14gfFileIOHandleFPCcQ25Heaps8HeapTypeii((gfFileIOHandle*)(self + 0x4c), base + 0x80, Heaps::HOME_DATA, 0, 0);
    readRequest__14gfFileIOHandleFPCcQ25Heaps8HeapTypeii((gfFileIOHandle*)(self + 0x50), base + 0xa4, Heaps::HOME_DATA, 0, 0);
}
}
