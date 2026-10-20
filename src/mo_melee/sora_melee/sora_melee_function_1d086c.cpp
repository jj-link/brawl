#pragma force_active on
struct BF { unsigned int a : 12; unsigned int b : 1; };
extern "C" int fn_27_1D086C(int* p) {
    BF* s = (BF*)(p + 2);
    return s->b;
}
