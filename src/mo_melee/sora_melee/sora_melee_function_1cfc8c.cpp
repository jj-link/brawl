#pragma force_active on
struct Object {
    unsigned int pad[2];
    unsigned int value : 5;
    unsigned int rest : 27;
};

extern "C" void fn_27_1CFC8C(Object* self, unsigned int value) {
    self->value = value;
}
