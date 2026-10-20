#pragma force_active on
extern "C" char lbl_96_data_5A7C[];
extern "C" void fn_27_57EC4(int* p);
extern "C" void fn_27_561E0(void*, void*, void*, unsigned int, unsigned char, unsigned char, void*);

struct FtSub {
    int a;
    int b;
};

struct FtObj {
    void* vtbl;
    FtSub subs[2];
};

extern "C" FtObj* fn_96_42B0(FtObj* self, void* a, unsigned int b, void* c)
{
    self->vtbl = (void*)lbl_96_data_5A7C;
    for (int i = 0; i < 2; i++) {
        fn_27_57EC4((int*)&self->subs[i]);
    }
    fn_27_561E0((char*)self + 0x14, a, self, b, 1, 1, c);
    return self;
}
