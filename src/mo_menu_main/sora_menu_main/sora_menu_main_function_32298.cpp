#pragma force_active on
typedef unsigned char u8;

extern "C" {
void readRequest__14gfFileIOHandleFPCcQ25Heaps8HeapTypeii(void* self, const char* name, int heap, int a, int b);
void* getGlobalRecordMenuDatap__10GameGlobalFv(void* global);
void loadMenuSound__6muMenuFv(void);
extern void* g_GameGlobal;
extern char lbl_2_data_3CC8[];

void fn_2_32298(u8* self) {
    char* base = lbl_2_data_3CC8;
    readRequest__14gfFileIOHandleFPCcQ25Heaps8HeapTypeii(self + 0x44, base + 0x430, 0x2a, 0, 0);
    u8* rec = (u8*)getGlobalRecordMenuDatap__10GameGlobalFv(g_GameGlobal);
    u8* handle = self + 0x48;
    char* name = base + 0x478;
    if ((rec[0x28] >> 7) & 1) {
        name = base + 0x44c;
    }
    readRequest__14gfFileIOHandleFPCcQ25Heaps8HeapTypeii(handle, name, 0x2a, 0, 0);
    readRequest__14gfFileIOHandleFPCcQ25Heaps8HeapTypeii(self + 0x4c, base + 0x4a0, 0x2a, 0, 0);
    loadMenuSound__6muMenuFv();
}
}
