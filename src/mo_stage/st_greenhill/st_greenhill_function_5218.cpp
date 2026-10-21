#pragma force_active on
struct State {
    unsigned int padding[2];
    unsigned int field : 2;
    unsigned int : 30;
};

extern "C" void fn_72_5218(State* self, unsigned int value) {
    self->field = value;
}
