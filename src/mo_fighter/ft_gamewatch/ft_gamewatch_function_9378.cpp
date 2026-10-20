#pragma force_active on
extern "C" {
extern char lbl_107_data_3794[];
void fn_27_57EC4(int* p);
void fn_27_561E0(void*, void*, void*, unsigned int, int, unsigned char, void*);
}

extern "C" void* fn_107_9378(void* self, void* a2, unsigned int a3, void* a4)
{
    unsigned char one = 1;
    *(void**)self = (void*)lbl_107_data_3794;
    for (int i = 0; i < 2; i++) {
        fn_27_57EC4((int*)((char*)self + i * 8 + 4));
    }
    fn_27_561E0((char*)self + 0x14, a2, self, a3, 1, one, a4);
    return self;
}
