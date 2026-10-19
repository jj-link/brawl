#pragma force_active on
extern "C" {
void printIndex__5MuMsgFUlUlPv(void*, unsigned long, unsigned long, void*);
void printf__5MuMsgFUlPCce(void*, unsigned long, const char*, ...);
extern const char lbl_14_data_410[];
}

extern "C" void fn_14_2498(void* self, int value) {
    if (value != 0) {
        printIndex__5MuMsgFUlUlPv(
            *(void**)((char*)self + 0x24CC), 0x2A, 0x12, 0);
    } else {
        printf__5MuMsgFUlPCce(
            *(void**)((char*)self + 0x24CC), 0x2A, lbl_14_data_410);
    }
}
