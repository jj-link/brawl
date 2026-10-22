#pragma force_active on
typedef unsigned char u8;
extern "C" {
void readRequest__14gfFileIOHandleFPCcQ25Heaps8HeapTypeii(void* self, const char* name, int heap, int a, int b);
void readRequest__14gfFileIOHandleFPCcPvii(void* self, const char* name, void* buf, int a, int b);
void* getGlobalRecordMenuDatap__10GameGlobalFv(void* global);
int sprintf(char*, const char*, ...);
extern void* g_GameGlobal;
extern char lbl_2_data_EF0[];

void fn_2_BA2C(u8* self) {
    char* base = lbl_2_data_EF0;
    char buf[64];
    readRequest__14gfFileIOHandleFPCcQ25Heaps8HeapTypeii(self + 0x264, base + 0xc, 0x2b, 0, 0);
    readRequest__14gfFileIOHandleFPCcQ25Heaps8HeapTypeii(self + 0x268, base + 0x30, 0x2b, 0, 0);
    readRequest__14gfFileIOHandleFPCcQ25Heaps8HeapTypeii(self + 0x26c, base + 0x48, 0x2b, 0, 0);
    readRequest__14gfFileIOHandleFPCcQ25Heaps8HeapTypeii(self + 0x270, base + 0x68, 0x2b, 0, 0);
    readRequest__14gfFileIOHandleFPCcQ25Heaps8HeapTypeii(self + 0x274, base + 0x80, 0x2b, 0, 0);
    readRequest__14gfFileIOHandleFPCcQ25Heaps8HeapTypeii(self + 0x278, base + 0x9c, 0x2b, 0, 0);
    u8* rec = (u8*)getGlobalRecordMenuDatap__10GameGlobalFv(g_GameGlobal);
    u8* handle = self + 0x280;
    char* name = base + 0xf4;
    if ((rec[0x28] >> 7) & 1) {
        name = base + 0xc4;
    }
    readRequest__14gfFileIOHandleFPCcQ25Heaps8HeapTypeii(handle, name, 0x2b, 0, 0);
    readRequest__14gfFileIOHandleFPCcQ25Heaps8HeapTypeii(self + 0x284, base + 0x120, 0x2b, 0, 0);
    readRequest__14gfFileIOHandleFPCcQ25Heaps8HeapTypeii(self + 0x288, base + 0x140, 0x2b, 0, 0);
    readRequest__14gfFileIOHandleFPCcQ25Heaps8HeapTypeii(self + 0x28c, base + 0x160, 0x2b, 0, 0);
    sprintf(buf, base + 0x2c8, self[0x44]);
    readRequest__14gfFileIOHandleFPCcPvii(self + 0x290, buf, *(void**)(self + *(int*)(self + 0x2b8) * 4 + 0x2b0), 0, 0);
    int n = *(int*)(self + 0x2b8) + 1;
    *(int*)(self + 0x2b8) = n;
    if (n >= 2) {
        *(int*)(self + 0x2b8) = 0;
    }
}
}
