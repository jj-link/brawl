#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern "C" {
void* getData__9gfArchiveF11ARCNodeTypeiUs(void*, int, int, u16);
void relocation__21grFixedPathCollectionFv();
void* getInstance__16CameraControllerFv();
}

extern "C" void fn_40_4D88(u8* self, u8* p) {
    int v = *p;
    *(void**)(self + 0x1b4) = 0;
    u16 k = (u16)(0x10000 - 2);
    void* data = getData__9gfArchiveF11ARCNodeTypeiUs(*(void**)(self + 0x1a0), 1, v, k);
    if (data != 0) {
        relocation__21grFixedPathCollectionFv();
        *(void**)(self + 0x1b4) = data;
        void* cam = getInstance__16CameraControllerFv();
        *(void**)(*(u8**)((u8*)cam + 0x60) + 0xa0) = *(void**)(self + 0x1b4);
    }
}
