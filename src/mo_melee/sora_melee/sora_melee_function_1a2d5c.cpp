#pragma force_active on
struct Object {
    unsigned int padding[2];
    unsigned int flags : 2;
    unsigned int other : 30;
};

extern "C" void fn_27_1A2D5C(Object* self, unsigned int value) {
    self->flags = value;
}
