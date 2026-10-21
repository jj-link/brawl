#pragma force_active on
struct Data {
    unsigned int padding[2];
    unsigned int flags : 5;
    unsigned int rest : 27;
};

extern "C" void fn_27_19DAEC(Data* self, unsigned int value) {
    self->flags = value;
}
