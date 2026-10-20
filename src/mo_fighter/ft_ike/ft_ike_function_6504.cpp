#pragma force_active on
extern "C" {
void fn_27_57EC4(int* p);
void fn_27_561E0(void*, void*, void*, unsigned int, bool, bool, void*);
extern int lbl_119_data_F94[];
}

extern "C" void* fn_119_6504(void* self, void* a, unsigned int b, void* c)
{
    int i;

    *(int**)self = (int*)lbl_119_data_F94;
    for (i = 0; i < 2; i++) {
        fn_27_57EC4((int*)((char*)self + (i << 3) + 4));
    }
    fn_27_561E0((char*)self + 0x14, a, self, b, true, true, c);
    return self;
}
