#pragma force_active on
struct Data {
    unsigned int padding[2];
    unsigned int : 5;
    unsigned int field : 5;
    unsigned int : 22;
};

extern "C" void fn_76_3DD4(Data* self, unsigned int value) {
    self->field = value;
}
