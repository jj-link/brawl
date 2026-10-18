#pragma force_active on
namespace Heaps {
enum HeapType { HeapType_Dummy = 0 };
}

class gfFileIOHandle {
public:
    void readRequest(const char* name, Heaps::HeapType heap, int a, int b);
};

extern char lbl_37_data_0[];

extern "C" {
void fn_37_FF8(char* self) {
    gfFileIOHandle* h0 = (gfFileIOHandle*)(self + 0x40);
    gfFileIOHandle* h1 = (gfFileIOHandle*)(self + 0x44);
    gfFileIOHandle* h2 = (gfFileIOHandle*)(self + 0x48);
    h0->readRequest(lbl_37_data_0 + 0x78, (Heaps::HeapType)0x2b, 0, 0);
    h1->readRequest(lbl_37_data_0 + 0x98, (Heaps::HeapType)0x2b, 0, 0);
    h2->readRequest(lbl_37_data_0 + 0xB8, (Heaps::HeapType)0x2b, 0, 0);
}
}
