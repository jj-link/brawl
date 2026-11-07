#pragma force_active on
extern "C" {
extern char lbl_41_data_644[];
extern char lbl_41_data_6A8[];
unsigned int fn_41_1AE7C(void*);
unsigned int fn_41_1C9C4(void*);
void* __dynamic_cast(void*, long, const void*, const void*, short);
int fn_41_1602C(void*, void*);
void* fn_41_15FD4(void*, int);
void fn_41_1BF64(void*, void*);
}
extern "C" void fn_41_1BF64(void* self, void* acc) {
    if (fn_41_1AE7C(self) != 1 && fn_41_1C9C4(self) != 1) {
        *(unsigned char*)((char*)self + 0x48) = 1;
        char* p0 = (char*)*(void**)((char*)acc + 0xD8);
        void* area = __dynamic_cast(*(void**)(p0 + 0x7C), 0, lbl_41_data_644, lbl_41_data_6A8, 1);
        int idx = fn_41_1602C(area, self);
        for (int i = 0; i < 8; i++) {
            void* p = fn_41_15FD4(area, i);
            if (fn_41_1AE7C(p) != 1 && *(int*)((char*)p + 0x74) == idx) {
                fn_41_1BF64(p, acc);
            }
        }
    }
}
