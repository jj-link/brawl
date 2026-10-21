#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

namespace Heaps {
enum HeapType { HeapType_Home = 0x2b };
}

extern "C" {
extern char lbl_1_data_4540[];
extern void* g_GameGlobal;

void* fn_800AFB94(const char*, int, const char*);
void* getGlobalRecordMenuDatap__10GameGlobalFv(void* global);
void readRequest__14gfFileIOHandleFPCcQ25Heaps8HeapTypeii(void* self, const char* name, int heap, int a, int b);
void* getInstance__16CameraControllerFv(void);
void changeInput__16CameraControllerFQ216CameraController4Kind(void* ctrl, int kind);

void fn_1_DFD0(u8* self) {
    char* base = lbl_1_data_4540;
    u8* rec;
    u8* h;
    char* name;

    self[0x440] = 0;
    *(void**)(self + 0x360) = fn_800AFB94(base + 0xc, 0x100, 0);
    rec = (u8*)getGlobalRecordMenuDatap__10GameGlobalFv(g_GameGlobal);
    h = self + 0x43c;
    name = base + 0x50;
    if ((rec[0x28] >> 7) & 1) {
        name = base + 0x20;
    }
    readRequest__14gfFileIOHandleFPCcQ25Heaps8HeapTypeii(h, name, 0x2b, 0, 0);
    readRequest__14gfFileIOHandleFPCcQ25Heaps8HeapTypeii(self + 0x434, base + 0x80, 0x2b, 0, 0);
    readRequest__14gfFileIOHandleFPCcQ25Heaps8HeapTypeii(self + 0x438, base + 0xa0, 0x2b, 0, 0);
    *(u32*)(self + 0x35c) = 0;
    *(u32*)(self + 0x36c) = 0;
    changeInput__16CameraControllerFQ216CameraController4Kind(getInstance__16CameraControllerFv(), 9);
}
}
