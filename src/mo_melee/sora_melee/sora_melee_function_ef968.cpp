#pragma force_active on
struct fn27Elem {
    int a;
    int b;
    int c;
};

struct fn27Obj {
    char pad[0x18];
    int flag;
    fn27Elem elems[1];
};

extern "C" {
void* fn_27_EF968(fn27Obj* p, int idx)
{
    int t = p->flag >> 30;
    int s = t + idx;
    if (s >= 1) {
        s--;
    }
    return (char*)p + 0x1c + s * 12;
}
}
