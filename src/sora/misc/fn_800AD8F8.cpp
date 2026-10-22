#pragma force_active on
extern "C" {
void readRequest__14gfFileIOHandleFPCcQ25Heaps8HeapTypeii(void* self, const char* name, int heap, int a, int b);
extern char lbl_80455180[];

int fn_800AD8F8(unsigned char* arg0) {
    if (arg0[0x3EA8] != 0) {
        return 0;
    }
    arg0[0x3EA8] = 0;
    arg0[0x3EB0] = 0;
    readRequest__14gfFileIOHandleFPCcQ25Heaps8HeapTypeii(arg0 + 0x3EAC, lbl_80455180, 0x2b, 0, 0);
    return 1;
}
}
