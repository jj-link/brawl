#pragma force_active on
extern "C" void fn_27_1A2724(unsigned int* a, unsigned int b) {
    union {
        unsigned int v;
        struct {
            unsigned int lo : 8;
            unsigned int field : 4;
            unsigned int hi : 20;
        };
    } u;
    u.v = a[2];
    u.field = b;
    a[2] = u.v;
}
