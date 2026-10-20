#pragma force_active on
struct A {
    char pad[0x7F8];
    int value;
};

extern "C" int fn_27_112ABC(A** p) {
    return (*p)->value;
}
