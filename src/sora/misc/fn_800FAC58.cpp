#pragma force_active on
extern "C" {
bool isReady__14gfFileIOHandleCFv(const void*);
void* getBuffer__14gfFileIOHandleCFv(const void*);
void free__13gfHeapManagerFPv(void*);
void cancelRequest__14gfFileIOHandleFv(void*);
void release__14gfFileIOHandleFv(void*);
void readRequest__14gfFileIOHandleFPCcQ25Heaps8HeapTypeii(void* self, const char* name, int heap, int a, int b);
}

extern "C" void fn_800FAC58(unsigned char* self, const char* name, int heap, int a) {
    if (self[0x14]) {
        if (isReady__14gfFileIOHandleCFv(self + 0x10)) {
            free__13gfHeapManagerFPv(getBuffer__14gfFileIOHandleCFv(self + 0x10));
        } else {
            cancelRequest__14gfFileIOHandleFv(self + 0x10);
        }
        release__14gfFileIOHandleFv(self + 0x10);
        self[0x14] = 0;
    }
    self[0x14] = 1;
    readRequest__14gfFileIOHandleFPCcQ25Heaps8HeapTypeii(self + 0x10, name, heap, a, 0);
}
