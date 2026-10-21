#pragma force_active on
typedef unsigned int u32;

extern "C" {
void fn_27_57EC4(u32*);
void fn_27_561E0(void*, void*, void*, void*, int, bool, void*);
extern char lbl_94_data_40F8[];
}

extern "C" void* fn_94_787C(void* self, void* a, void* b, void* c)
{
    u32* p = (u32*)self;
    p[0] = (u32)lbl_94_data_40F8;

    for (int i = 0; i < 2; ++i)
        fn_27_57EC4((u32*)((char*)self + i * 8 + 4));

    fn_27_561E0((char*)self + 0x14, a, self, b, 1, true, c);
    return self;
}
