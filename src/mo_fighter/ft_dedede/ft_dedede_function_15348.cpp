#pragma force_active on
extern "C" void fn_117_15348(void* frame) {
    extern const float lbl_117_rodata_A8[];
    float* storage = static_cast<float*>(frame);
    float value = lbl_117_rodata_A8[0];
    storage[3] = value;
    storage[2] = value;
}
