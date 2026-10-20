#pragma force_active on
struct A {
    int v1;
    int v2;
    int m;
};
extern "C" int fn_27_39575C(const A* self) {
    return self->m >> 28;
}
