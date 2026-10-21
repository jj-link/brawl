#pragma force_active on
struct Data {
    int a;
    int b;
    short c;
    short d;
};

extern "C" void fn_27_FE1C4(Data* dst, const int* a, int b, const short* c, short d)
{
    dst->a = *a;
    dst->b = b;
    dst->c = *c;
    dst->d = d;
}
