#pragma force_active on
extern "C" int fn_63_10AC8(int* p) {
    union {
        int raw;
        struct {
            unsigned int x : 2;
            signed int y : 2;
        };
    } u;
    u.raw = p[2];
    return u.y;
}
