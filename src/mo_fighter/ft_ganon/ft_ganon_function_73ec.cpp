#pragma force_active on
extern "C" {
extern int lbl_109_data_12EC[];
void fn_27_57EC4(int* p);
void fn_27_561E0(void* a, void* b, void* c, void* d, int e, bool f, void* g);
}

extern "C" void* fn_109_73EC(void* self, void* a, void* b, void* c)
{
    int i;
    *(void**)self = (void*)lbl_109_data_12EC;
    for (i = 0; i < 2; i++) {
        fn_27_57EC4((int*)((char*)self + i * 8 + 4));
    }
    fn_27_561E0((char*)self + 0x14, a, self, b, 1, true, c);
    return self;
}
