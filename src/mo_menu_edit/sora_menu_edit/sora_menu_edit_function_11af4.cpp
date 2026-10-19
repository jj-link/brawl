#pragma force_active on
typedef unsigned char u8;

extern "C" {
void readRequest__14gfFileIOHandleFPCcQ25Heaps8HeapTypeii(void* self, const char* name, int heap, int a, int b);
extern char lbl_5_data_600[];

u8* fn_5_11AF4(u8* self, int val, int cond) {
    *(int*)(self + 0x5d0) = val;
    self[0x600] = 0;
    *(int*)(self + 0x604) = 0;
    self[0x608] = 1;
    *(int*)(self + 0x60c) = 0;
    if (cond != 0) {
        if (self[0x600] == 0) {
            self[0x600] = 0;
            self[0x608] = 0;
            readRequest__14gfFileIOHandleFPCcQ25Heaps8HeapTypeii(self + 0x604, lbl_5_data_600, 0x2b, 0, 0);
        }
    }
    return self;
}
}
