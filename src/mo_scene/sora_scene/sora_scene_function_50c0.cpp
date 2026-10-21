#include <types.h>
#pragma force_active on
extern "C" {
extern char lbl_1_data_6D8[];
extern void* g_GameGlobal;

void* alloc__13gfHeapManagerFQ25Heaps8HeapTypeUl(int, u32);
void* fn_800AFB94(const char*, int, const char*);
void* getGlobalRecordMenuDatap__10GameGlobalFv(void*);
void* getInstance__16CameraControllerFv();
void changeInput__16CameraControllerFQ216CameraController4Kind(void*, int);
void readRequest__14gfFileIOHandleFPCcQ25Heaps8HeapTypeii(void*, const char*, int, int, int);
void fn_1_40E0(u32);

void fn_1_50C0(u8* self) {
    const char* data = lbl_1_data_6D8;
    u8* rec;
    const char* name;
    u8* dst;

    self[0x3a8] = 0;
    *(void**)(self + 0x398) = alloc__13gfHeapManagerFQ25Heaps8HeapTypeUl(0x2a, 0xc);
    **(void***)(self + 0x398) = fn_800AFB94(data + 0x1c, 0x40, 0);
    self[0x39c] = 0;
    rec = (u8*)getGlobalRecordMenuDatap__10GameGlobalFv(g_GameGlobal);
    dst = self + 0x3a0;
    name = data + 0x58;
    if ((rec[0x28] >> 7) & 1) {
        name = data + 0x28;
    }
    readRequest__14gfFileIOHandleFPCcQ25Heaps8HeapTypeii(dst, name, 0x2b, 0, 0);
    ((u32*)(*(u8**)(self + 0x398)))[1] = 0;
    ((u32*)(*(u8**)(self + 0x398)))[2] = 0;
    changeInput__16CameraControllerFQ216CameraController4Kind(getInstance__16CameraControllerFv(), 9);
    fn_1_40E0(1);
}
}
