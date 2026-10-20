#pragma force_active on
struct St08 {
    unsigned int pad0;
    unsigned int pad1;
    unsigned int hi : 3;
    unsigned int field : 3;
    unsigned int lo : 26;
};

extern "C" void fn_62_60F4(St08 *p, unsigned int v)
{
    p->field = v;
}
