#pragma force_active on
extern "C" int fn_80110310(int*, int*);

extern "C" int fn_27_2559B8() {
    int a;
    int b;
    fn_80110310(&a, &b);
    return a;
}
