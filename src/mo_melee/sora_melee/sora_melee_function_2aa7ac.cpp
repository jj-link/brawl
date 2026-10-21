#pragma force_active on

struct Pair {
    unsigned int a;
    unsigned int b;
};

extern "C" unsigned char lbl_27_data_741A0[];

struct Desc {
    void* a;
    void* b;
    unsigned int f0 : 1;
    unsigned int f1 : 1;
    unsigned int f2 : 1;
    unsigned int f3 : 1;
    unsigned int f4 : 1;
    unsigned int f5 : 1;
    unsigned int f6 : 1;
    unsigned int rest : 25;

    Desc(void* p, void* q)
        : a(p), b(q),
          f0(0), f1(0), f2(0), f3(0), f4(0), f5(0), f6(0) {}
};

extern "C" void fn_27_2AA880(
    void*, Desc*, Pair, int, int, int, int, int, int);

extern "C" void fn_27_2AA7AC(
    void* a, Pair b, int c, int d, int e, int f, int g)
{
    Desc desc(lbl_27_data_741A0, lbl_27_data_741A0 + 0x48);
    fn_27_2AA880(a, &desc, b, c, d, d, e, f, g);
}
