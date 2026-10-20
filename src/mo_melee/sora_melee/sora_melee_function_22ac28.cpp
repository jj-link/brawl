#pragma force_active on
struct Data { int x; };

struct Obj {
    char pad[0x40];
    Data* a;
    Data* b;
    Data* c;
    Data* d;
    int e;
};

extern "C" void fn_27_22AC28(Obj* self) {
    self->e = 0;
    if (self->a)
        delete[] self->a;
    if (self->b)
        delete[] self->b;
    if (self->c)
        delete[] self->c;
    if (self->d)
        delete[] self->d;
    self->a = 0;
    self->b = 0;
    self->c = 0;
    self->d = 0;
}
