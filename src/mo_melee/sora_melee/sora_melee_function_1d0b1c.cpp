#pragma force_active on
struct Elem {
    int a;
    int b;
    int c;
};

struct Container {
    int a;
    int b;
    int c;
    Elem elems[];
};

extern "C" Elem* fn_27_1D0B1C(Container* self, int idx) {
    return &self->elems[idx];
}
