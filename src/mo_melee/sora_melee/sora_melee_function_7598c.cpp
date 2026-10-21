#pragma force_active on

struct V3 {
    int a, b, c;
};

struct Data {
    V3 a;
    int b;
    V3 c;
    unsigned short d, e;
    unsigned char f0, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10;
};

struct Obj {
    unsigned char pad[0x7F];
    unsigned char flag;
    Data data;
};

extern "C" void fn_27_7598C(Obj* dst, const Data* src)
{
    dst->flag = 1;
    dst->data.b = -1;
    if (src != 0) {
        dst->data = *src;
    }
}
