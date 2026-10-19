#pragma force_active on
struct FnBits {
    int a;
    int b;
    unsigned int pad : 5;
    int field : 5;
};

extern "C" int fn_113_13A08(struct FnBits *p) {
    return p->field;
}
