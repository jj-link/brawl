#pragma force_active on
extern "C" {
extern char lbl_101_data_350C[];
void fn_27_57EC4(void* p);
void fn_27_561E0(void*, void*, void*, void*, bool, bool, void*);
}

extern "C" void* fn_101_9F40(char* self, void* a2, void* a3, void* a4) {
    *(void**)self = lbl_101_data_350C;
    for (int i = 0; i < 2; i++) {
        fn_27_57EC4(self + i * 8 + 4);
    }
    bool flag = true;
    fn_27_561E0(self + 0x14, a2, self, a3, flag, flag, a4);
    return self;
}
