#pragma force_active on
extern "C" {
extern char lbl_113_data_1B10[];
void fn_27_57EC4(int* p);
void fn_27_561E0(void*, void*, void*, void*, int, bool, void*);
}

extern "C" void* fn_113_8C78(void* self, void* p4, void* p5, void* p6)
{
    *(void**)self = (void*)lbl_113_data_1B10;
    for (int i = 0; i < 2; i++) {
        fn_27_57EC4((int*)((char*)self + i * 8 + 4));
    }
    fn_27_561E0((char*)self + 0x14, p4, self, p5, 1, true, p6);
    return self;
}
