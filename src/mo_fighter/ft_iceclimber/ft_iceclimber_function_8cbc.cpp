#pragma force_active on
extern "C" {
extern char lbl_105_data_28E0[];
void fn_27_57EC4(int* p);
void* fn_27_561E0(void*, void*, void*, unsigned int, bool, bool, void*);
}

extern "C" void* fn_105_8CBC(void* self, void* a, unsigned int b, void* c)
{
    *(void**)self = lbl_105_data_28E0;
    for (int i = 0; i < 2; i++) {
        fn_27_57EC4((int*)((char*)self + 4 + i * 8));
    }
    fn_27_561E0((char*)self + 0x14, a, self, b, true, true, c);
    return self;
}
