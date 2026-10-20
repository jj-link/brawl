#pragma force_active on
struct Entry12 {
    int a;
    int b;
    int c;
};

struct Owner {
    int pad0;
    int pad4;
    int f8;
};

extern "C" {
Entry12* fn_27_1E7C44(Owner* self, int idx) {
    int i = (self->f8 >> 30) + idx;
    if (i >= 1) {
        i = i - 1;
    }
    return (Entry12*)((char*)self + i * 12 + 12);
}
}
