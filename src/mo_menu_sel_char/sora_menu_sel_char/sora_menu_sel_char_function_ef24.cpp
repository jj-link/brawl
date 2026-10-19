#pragma force_active on
extern "C" {
void fn_8019D950(void*);
int fn_10_DA54(void*, void*);
void Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(void*, void*, char*);
extern char lbl_10_data_604[];
}

extern "C" void fn_10_EF24(char* self, void* arg1, char* arg2) {
    fn_8019D950(*(void**)(arg2 + 0x10));
    int index = fn_10_DA54(self, arg1);
    if (index >= 0) {
        Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(
            *(void**)(self + 0x42c + (index + 2) * 4),
            *(void**)(arg2 + 0x10),
            lbl_10_data_604);
    }
}
