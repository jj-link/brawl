#pragma force_active on
typedef struct {
    char pad[8];
    int a : 4;
    int b : 2;
} T;

extern "C" int fn_47_4D54(T *p) {
    return p->b;
}
