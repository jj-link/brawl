#pragma force_active on
struct Bits {
    unsigned int hi : 3;
    unsigned int f : 3;
    unsigned int lo : 26;
};

extern "C" void fn_27_295C50(void* p, unsigned int v)
{
    Bits* b = (Bits*)((char*)p + 8);
    b->f = v;
}
