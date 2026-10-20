#pragma force_active on
extern "C" int fn_27_2BB9F0(int* p) {
    union {
        int i;
        struct {
            unsigned : 15;
            int f : 5;
        };
    } u;
    u.i = p[1];
    return u.f;
}
