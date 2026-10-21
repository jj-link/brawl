#pragma force_active on
extern "C" {
void startup__10grYakumonoFP9gfArchiveUlQ211gfSceneRoot9LayerType(void* self, void* arch, unsigned long p, int layer);
void* __nw__FUlQ25Heaps8HeapType(unsigned long size, int heap);
void* __ct__7MessageFUlQ25Heaps8HeapType(void* self, unsigned long arg, int heap);
void allocMsgBuf__7MessageFUlUlQ25Heaps8HeapType(void* self, unsigned long a, unsigned long b, int heap);
void attachMsgBuf__7MessageFUlPQ34nw4r3g3d12ScnMdlSimplePCcUcif(void* self, unsigned long idx, void* mdl, const char* str, unsigned char c, int n, float f);
extern char lbl_27_data_5A460[];
extern float lbl_27_rodata_456C;
}

extern "C" void fn_27_27ACAC(void* self, void* arch, unsigned long p, int layer) {
    unsigned char* s = (unsigned char*)self;
    startup__10grYakumonoFP9gfArchiveUlQ211gfSceneRoot9LayerType(self, arch, p, layer);
    void* msg = __nw__FUlQ25Heaps8HeapType(0x1E0, 0xF);
    if (msg != 0) {
        msg = __ct__7MessageFUlQ25Heaps8HeapType(msg, 0xA, 0xF);
    }
    *(void**)(s + 0x170) = msg;
    allocMsgBuf__7MessageFUlUlQ25Heaps8HeapType(msg, 0x100, 5, 0xF);
    for (int i = 0; i < 5; i++) {
        unsigned char* a = *(unsigned char**)(s + 0x44);
        attachMsgBuf__7MessageFUlPQ34nw4r3g3d12ScnMdlSimplePCcUcif(*(void**)(s + 0x170), i, *(void**)a, lbl_27_data_5A460, 0, 3, lbl_27_rodata_456C);
    }
}
