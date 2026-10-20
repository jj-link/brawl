#pragma force_active on
struct S76 {
    unsigned int pad[2];
    unsigned int hi : 8;
    unsigned int f : 4;
    unsigned int lo : 20;
};

extern "C" void fn_76_4088(struct S76 *p, unsigned int v)
{
    p->f = v;
}
