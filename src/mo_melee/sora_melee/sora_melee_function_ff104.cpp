#pragma force_active on
struct Elem {
    int a;
    int b;
    int c;
};

struct Owner {
    int pad[2];
    int f8;
};

extern "C" Elem* fn_27_FF104(Owner* p, int n)
{
    int idx = (p->f8 >> 30) + n;
    if (idx >= 1) {
        idx = idx - 1;
    }
    return (Elem*)((char*)p + idx * 12 + 12);
}
