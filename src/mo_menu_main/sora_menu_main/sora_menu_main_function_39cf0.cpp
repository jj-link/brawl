#pragma force_active on
extern "C" {
int fn_800B5854(void* p, int a, int b, int c, int d);
void printf__5MuMsgFUlPCce(void* msg, unsigned long index, const char* fmt, ...);
void fn_2_39CF0(char* self);
}

extern char lbl_2_data_4BE8[];

void fn_2_39CF0(char* self) {
    fn_800B5854(*(void**)(self + 0x44), 3, 1, 1, 0);
    printf__5MuMsgFUlPCce(*(void**)(self + 0x74), 5, lbl_2_data_4BE8);
}
