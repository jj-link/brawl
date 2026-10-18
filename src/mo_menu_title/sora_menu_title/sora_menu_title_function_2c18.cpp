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
void fn_8007EC08(void*, void*, int, int, int);
extern char lbl_24_data_7A8[];

void fn_24_2C18(gfFileIOHandle* self) {
    char* r31 = lbl_24_data_7A8;
    gfFileIOHandle* r30 = self;
    readRequest__14gfFileIOHandleFPCcQ25Heaps8HeapTypeii((gfFileIOHandle*)((u8*)r30 + 0x40), (char*)(r31 + 12), Heaps::HOME_DATA, 0, 0);
    readRequest__14gfFileIOHandleFPCcQ25Heaps8HeapTypeii((gfFileIOHandle*)((u8*)r30 + 0x44), (char*)(r31 + 52), Heaps::HOME_DATA, 0, 0);
    fn_8007EC08(*(void**)((u8*)r30 + 0x54), r31 + 84, 0, 0, 0);
}
}
