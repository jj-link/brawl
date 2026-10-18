#pragma force_active on
struct Data {
    char pad[0x188];
    int value;
    float amount;
};

extern "C" void fn_47_14A8(Data *this_, int *value, float *amount) {
    *value = this_->value;
    *amount = this_->amount;
}
