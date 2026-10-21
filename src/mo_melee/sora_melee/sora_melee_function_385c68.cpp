#pragma force_active on
struct Data {
    unsigned int pad[2];
    unsigned int upper : 20;
    unsigned int field : 10;
    unsigned int lower : 2;
};

extern "C" void fn_27_385C68(Data* self, unsigned int value) {
    self->field = value;
}
