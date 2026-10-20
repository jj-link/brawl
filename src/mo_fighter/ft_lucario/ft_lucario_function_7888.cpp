#pragma force_active on
extern "C" {
extern char lbl_118_data_142C[];
void fn_27_57EC4(int* p);
void fn_27_561E0(void*, void*, void*, void*, int, bool, void*);
}

extern "C" void* fn_118_7888(void* self, void* a, void* b, void* c) {
    *(void**)self = lbl_118_data_142C;
    for (int i = 0; i < 2; i++) {
        fn_27_57EC4((int*)((char*)self + i * 8 + 4));
    }
    int one = 1;
    fn_27_561E0((char*)self + 0x14, a, self, b, one, true, c);
    return self;
}
