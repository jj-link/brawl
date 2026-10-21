#pragma force_active on
extern "C" void fn_27_57EC4(int* p);
extern "C" void fn_27_561E0(void* a, void* b, void* c, void* d, int e, bool f, void* g);
extern "C" char lbl_110_data_1308[];

extern "C" void* fn_110_7A24(void* self, void* a, void* b, void* c)
{
    *(void**)self = lbl_110_data_1308;
    for (int i = 0; i < 2; i++) {
        fn_27_57EC4((int*)((char*)self + i * 8 + 4));
    }
    fn_27_561E0((char*)self + 0x14, a, self, b, 1, true, c);
    return self;
}
