#pragma force_active on
extern "C" {
extern char lbl_126_data_B04[];
void fn_27_57EC4(int* p);
void fn_27_561E0(void*, void*, void*, void*, int, bool, void*);
void* fn_126_5D4C(void* self, void* a, void* b, void* c);
}

void* fn_126_5D4C(void* self, void* a, void* b, void* c) {
    *(void**)self = lbl_126_data_B04;
    for (int i = 0; i < 2; i++) {
        fn_27_57EC4((int*)((char*)self + i * 8 + 4));
    }
    fn_27_561E0((char*)self + 0x14, a, self, b, 1, true, c);
    return self;
}
