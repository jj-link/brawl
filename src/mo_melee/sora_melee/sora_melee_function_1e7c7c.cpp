#pragma force_active on
struct X {
    int a;
    int b;
    int c;
};

extern "C" int fn_27_1E7C7C(X* p)
{
    return p->c >> 30;
}
