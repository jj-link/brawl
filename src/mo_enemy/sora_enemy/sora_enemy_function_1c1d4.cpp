#pragma force_active on
extern "C" {
extern char lbl_41_data_644[];
extern char lbl_41_data_6A8[];
unsigned int fn_41_1AE7C(void* p);
int fn_41_1AE30(int p1);
unsigned int fn_41_1C9C4(void* p);
unsigned int fn_41_1CA10(void* p);
void* __dynamic_cast(void*, long, const void*, const void*, short);
void* fn_41_15FD4(void* p, int idx);
int fn_41_1C1D4(void* self, void* acc);
}

extern "C" int fn_41_1C1D4(void* self, void* acc) {
    if (fn_41_1AE7C(self) == 1) {
        return 0;
    }
    if (fn_41_1C9C4(self) == 1) {
        return 0;
    }
    if (fn_41_1CA10(self) == 1) {
        return 0;
    }
    if (fn_41_1AE30(*(int*)((char*)self + 0x8)) == 2) {
        char* p0 = (char*)*(void**)((char*)acc + 0xD8);
        void* area = __dynamic_cast(*(void**)(p0 + 0x7C), 0, lbl_41_data_644, lbl_41_data_6A8, 1);
        return fn_41_1C1D4(fn_41_15FD4(area, *(int*)((char*)self + 0x74)), acc);
    }
    return (int)*(float*)((char*)self + 0x60) != 0x8BCE;
}
