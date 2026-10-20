#pragma force_active on
struct FloatWorkHolder {
    char pad[0x7ec];
    float *floatWorks;
};

extern "C" {
float fn_73_9C24(FloatWorkHolder *work, unsigned long index) {
    return work->floatWorks[index];
}
}
