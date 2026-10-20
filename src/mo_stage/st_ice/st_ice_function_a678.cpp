#pragma force_active on
struct Flags {
    unsigned int hi : 4;
    unsigned int rest : 28;
};

extern "C" void fn_62_A678(void *p, unsigned int v)
{
    struct Flags *f = (struct Flags *)((char *)p + 8);
    f->hi = v;
}
