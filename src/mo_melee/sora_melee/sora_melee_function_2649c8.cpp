#pragma force_active on
extern "C" {
struct __attribute__((packed)) X_27 {
    unsigned int a;
    unsigned int b;
    signed int c;
};

signed int fn_27_2649C8(X_27* p) {
    return p->c >> 28;
}
}
