#pragma force_active on
struct FloatWorkHolder {
    char pad[0x14];
    float* floats;
};

extern "C" void fn_92_9A60(FloatWorkHolder* work, unsigned int index, float value) {
    work->floats[index] *= value;
}
