#pragma force_active on
extern "C" void fn_27_FE4F4(void* p, unsigned int v)
{
    struct Flags {
        unsigned int a : 4;
        unsigned int b : 2;
        unsigned int c : 26;
    };
    Flags* f = (Flags*)((char*)p + 8);
    f->b = v;
}
