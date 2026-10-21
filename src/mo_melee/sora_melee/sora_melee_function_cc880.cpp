#pragma force_active on
struct Object {
    unsigned int pad[2];
    unsigned int : 3;
    unsigned int field : 3;
    unsigned int : 26;
};

extern "C" void fn_27_CC880(Object* self, unsigned int value) {
    self->field = value;
}
