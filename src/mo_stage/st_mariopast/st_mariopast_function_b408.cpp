#pragma force_active on
struct Bits {
    unsigned int pad[2];
    unsigned int hi : 9;
    unsigned int lo : 23;
};

extern "C" {
void fn_48_B408(Bits *p, unsigned int v)
{
    p->hi = v;
}
}
