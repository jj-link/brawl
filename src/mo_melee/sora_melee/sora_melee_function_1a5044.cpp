#pragma force_active on
struct Obj {
    unsigned a;
    unsigned b;
    unsigned lo:15;
    unsigned bit:1;
};

extern "C" unsigned fn_27_1A5044(Obj* self) {
    return self->bit;
}
