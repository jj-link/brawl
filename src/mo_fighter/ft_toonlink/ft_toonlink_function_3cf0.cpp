#pragma force_active on
extern "C" {
void fn_27_57EC4(int* p);
void fn_27_561E0(void*, void*, void*, void*, int, bool, void*);
extern int lbl_121_data_2E2C[];
}

extern "C" char* fn_121_3CF0(char* self, void* a, void* b, void* c) {
    *(int**)self = (int*)lbl_121_data_2E2C;
    for (int i = 0; i < 2; i++) {
        fn_27_57EC4((int*)(self + i * 8 + 4));
    }
    fn_27_561E0(self + 0x14, a, self, b, 1, true, c);
    return self;
}
