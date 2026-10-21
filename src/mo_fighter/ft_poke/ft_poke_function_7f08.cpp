#pragma force_active on
extern "C" {
extern char lbl_116_data_1D68[];
void fn_27_57EC4(int* p);
void fn_27_561E0(void*, void*, void*, void*, int, bool, void*);
}

extern "C" void* fn_116_7F08(char* self, void* a, void* b, void* c)
{
    int i;
    *(void**)self = (void*)lbl_116_data_1D68;
    for (i = 0; i < 2; i++) {
        fn_27_57EC4((int*)(self + i * 8 + 4));
    }
    fn_27_561E0(self + 0x14, a, self, b, 1, true, c);
    return self;
}
