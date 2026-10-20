#pragma force_active on
struct Object {
    unsigned int padding[2];
    unsigned int : 2;
    unsigned int field : 2;
    unsigned int : 28;
};

extern "C" void fn_78_5764(Object* self, unsigned int value) {
    self->field = value;
}
