#pragma force_active on
struct S {
    int x;
    int y;
    unsigned a : 12;
    unsigned b : 1;
};

extern "C" int fn_27_1A5864(const S* obj) {
    return obj->b;
}
