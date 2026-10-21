#pragma force_active on

typedef unsigned int u32;

struct S { u32 a, b, c; };

extern "C" u32 fn_27_D16BC(const S *p) {
    return (p->c >> 7) & 1;
}
