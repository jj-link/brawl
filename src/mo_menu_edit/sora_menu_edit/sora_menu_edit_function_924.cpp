#pragma force_active on
extern "C" {
extern void* g_GameGlobal;
extern void* g_sndSystem;
extern char lbl_5_data_0[];
void* getGlobalRecordMenuDatap__10GameGlobalFv(void*);
void readRequest__14gfFileIOHandleFPCcQ25Heaps8HeapTypeii(void*, const char*, int, int, int);
void fn_800151FC(void*, const char*, int, int, int, int);
int loadSoundGroup__9sndSystemF10SndGroupIDib(void*, int, int, int);

void fn_5_924(char* self) {
    char* d = lbl_5_data_0;
    char* s = self;
    switch (*(int*)(s + 0x104)) {
    case 0:
        if ((*(unsigned char*)((char*)getGlobalRecordMenuDatap__10GameGlobalFv(g_GameGlobal) + 0x28) >> 7) & 1)
            readRequest__14gfFileIOHandleFPCcQ25Heaps8HeapTypeii(s + 0xC476C, d + 0x5c, 0x2b, 0, 0);
        else
            readRequest__14gfFileIOHandleFPCcQ25Heaps8HeapTypeii(s + 0xC476C, d + 0x90, 0x2b, 0, 0);
        break;
    case 1:
        if ((*(unsigned char*)((char*)getGlobalRecordMenuDatap__10GameGlobalFv(g_GameGlobal) + 0x28) >> 7) & 1)
            readRequest__14gfFileIOHandleFPCcQ25Heaps8HeapTypeii(s + 0xC476C, d + 0xc0, 0x2b, 0, 0);
        else
            readRequest__14gfFileIOHandleFPCcQ25Heaps8HeapTypeii(s + 0xC476C, d + 0xf4, 0x2b, 0, 0);
        break;
    case 2:
        if ((*(unsigned char*)((char*)getGlobalRecordMenuDatap__10GameGlobalFv(g_GameGlobal) + 0x28) >> 7) & 1)
            readRequest__14gfFileIOHandleFPCcQ25Heaps8HeapTypeii(s + 0xC476C, d + 0x124, 0x2b, 0, 0);
        else
            readRequest__14gfFileIOHandleFPCcQ25Heaps8HeapTypeii(s + 0xC476C, d + 0x158, 0x2b, 0, 0);
        break;
    }
    readRequest__14gfFileIOHandleFPCcQ25Heaps8HeapTypeii(s + 0xC4770, d + 0x188, 0x2b, 0, 0);
    readRequest__14gfFileIOHandleFPCcQ25Heaps8HeapTypeii(s + 0xC477C, d + 0x1b0, 0x2b, 0, 0);
    readRequest__14gfFileIOHandleFPCcQ25Heaps8HeapTypeii(s + 0xC4774, d + 0x1d0, 0x2b, 0, 0);
    readRequest__14gfFileIOHandleFPCcQ25Heaps8HeapTypeii(s + 0xC4778, d + 0x1e8, 0x2b, 0, 0);
    readRequest__14gfFileIOHandleFPCcQ25Heaps8HeapTypeii(s + 0xC4780, d + 0x204, 0x2b, 0, 0);
    readRequest__14gfFileIOHandleFPCcQ25Heaps8HeapTypeii(s + 0xC4784, d + 0x21c, 0x2b, 0, 0);
    fn_800151FC(*(void**)(s + 0xC4788), d + 0x238, 0x2b, 0, 0, 0xff);
    *(int*)(s + 0x10c) = loadSoundGroup__9sndSystemF10SndGroupIDib(g_sndSystem, 0x69, 1, 1);
}
}