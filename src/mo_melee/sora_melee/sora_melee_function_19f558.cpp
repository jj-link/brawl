#pragma force_active on
struct Data {
    unsigned int pad[2];
    unsigned int : 4;
    unsigned int flags : 4;
    unsigned int : 24;
};

extern "C" void fn_27_19F558(Data* self, unsigned int value) {
    self->flags = value;
}
