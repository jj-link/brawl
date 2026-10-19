#pragma force_active on
extern "C" {
extern const char lbl_25_data_1A0[];
void readRequest__14gfFileIOHandleFPCcQ25Heaps8HeapTypeii(void* self, const char* name, int heap, int a, int b);
}

extern "C" void fn_25_123C(void* self) {
    *(int*)((char*)self + 0xb4) = 1;
    readRequest__14gfFileIOHandleFPCcQ25Heaps8HeapTypeii((char*)self + 0x40, lbl_25_data_1A0, 0x2b, 0, 0);
}
