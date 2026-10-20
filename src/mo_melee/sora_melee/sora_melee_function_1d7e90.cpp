#pragma force_active on
struct Obj {
    int a;
    int b;
    int val;
};

extern "C" {
void* fn_27_1D7E90(Obj* p, int idx)
{
    int i = (p->val >> 27) + idx;
    if (i >= 10) {
        i -= 10;
    }
    return (char*)p + i * 12 + 12;
}
}
