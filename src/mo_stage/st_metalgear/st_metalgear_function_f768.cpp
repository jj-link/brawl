#pragma force_active on
extern "C" {
struct Bits {
    unsigned int pad[2];
    unsigned int hi : 4;
    unsigned int lo : 4;
    unsigned int rest : 24;
};
void fn_71_F768(struct Bits *p, unsigned int v)
{
    p->lo = v;
}
}
