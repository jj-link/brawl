#pragma force_active on
extern "C" {
void readRequest__14gfFileIOHandleFPCcQ25Heaps8HeapTypeii(void* self, const char* name, int heap, int a, int b);
extern char lbl_80455180[];

void* fn_800AD808(char* self, int arg) {
    int z = 0;
    self[0x3EA8] = z;
    *(int*)(self + 0x3EAC) = z;
    self[0x3EB0] = 1;
    if (arg != 0) {
        if (self[0x3EA8] == 0) {
            self[0x3EA8] = 0;
            self[0x3EB0] = 0;
            readRequest__14gfFileIOHandleFPCcQ25Heaps8HeapTypeii(self + 0x3EAC, lbl_80455180, 0x2b, 0, 0);
        }
    }
    return self;
}
}
