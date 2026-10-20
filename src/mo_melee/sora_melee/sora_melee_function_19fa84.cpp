#pragma force_active on
struct fn_27_19FA84_S {
    unsigned int pad0 : 10;
    unsigned int field : 5;
    unsigned int pad1 : 17;
};

extern "C" void fn_27_19FA84(void *p, unsigned int v)
{
    ((struct fn_27_19FA84_S *)((char *)p + 8))->field = v;
}
