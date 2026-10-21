#pragma force_active on
extern "C" {
void fn_27_57EC4(int* p);
void fn_27_561E0(void*, void*, void*, void*, int, bool, void*);
extern char lbl_125_data_2104[];
}

extern "C" void* fn_125_8BE4(void* self, void* a, void* b, void* c) {
    *(void**)self = lbl_125_data_2104;
    for (int i = 0; i < 2; i++) {
        fn_27_57EC4((int*)((char*)self + i * 8 + 4));
    }
    fn_27_561E0((char*)self + 0x14, a, self, b, 1, true, c);
    return self;
}
