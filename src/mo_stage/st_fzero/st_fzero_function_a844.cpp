#pragma force_active on
struct FnBits {
    unsigned long hi : 8;
    unsigned long f : 4;
    unsigned long lo : 20;
};

extern "C" void fn_61_A844(void *p, unsigned long v)
{
    struct FnBits *b = (struct FnBits *)((char *)p + 8);
    b->f = v;
}
