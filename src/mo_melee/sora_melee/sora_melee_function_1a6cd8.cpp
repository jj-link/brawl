#pragma force_active on
struct S {
    int pad[2];
    unsigned int hi : 20;
    unsigned int field : 10;
    unsigned int lo : 2;
};

extern "C" void fn_27_1A6CD8(S* s, unsigned int v)
{
    s->field = v;
}
