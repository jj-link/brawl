#pragma force_active on
extern "C" {
extern char lbl_91_data_2578[];
void fn_27_57EC4(int* p);
void fn_27_561E0(void*, void*, void*, void*, int, bool, void*);
}

extern "C" void* fn_91_3B2C(void* self, void* a, void* b, void* c)
{
    *(void**)self = lbl_91_data_2578;
    for (int i = 0; i < 2; i++) {
        fn_27_57EC4((int*)((char*)self + i * 8 + 4));
    }
    fn_27_561E0((char*)self + 0x14, a, self, b, 1, true, c);
    return self;
}
