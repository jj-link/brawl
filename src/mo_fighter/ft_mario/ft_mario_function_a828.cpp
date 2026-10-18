#pragma force_active on
struct FloatArrayOwner {
    unsigned char pad[0x14];
    float* values;
};

extern "C" void fn_91_A828(FloatArrayOwner* owner, int index, float delta) {
    owner->values[index] += delta;
}
