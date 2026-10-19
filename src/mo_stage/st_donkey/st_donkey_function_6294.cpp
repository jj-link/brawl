#pragma force_active on
struct Data {
    unsigned int padding[2];
    unsigned int value : 2;
    unsigned int other : 30;
};

extern "C" void fn_50_6294(Data* self, unsigned int value) {
    self->value = value;
}
