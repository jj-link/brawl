#pragma force_active on
struct Data {
    unsigned int padding[2];
    unsigned int : 8;
    unsigned int value : 4;
    unsigned int : 20;
};

extern "C" void fn_27_19C79C(Data* data, unsigned int value) {
    data->value = value;
}
