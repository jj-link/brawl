#pragma force_active on
extern "C" {
extern const float lbl_100_rodata_8;
extern const float lbl_100_rodata_10;
float* fn_100_B818(float*, const float*);
}

extern "C" void fn_100_B82C(float* obj) {
    float zero[2] = {lbl_100_rodata_8, lbl_100_rodata_8};
    float* result = fn_100_B818(obj + 8, zero);
    result = fn_100_B818(obj + 4, result);
    fn_100_B818(obj + 2, result);

    float other[2] = {lbl_100_rodata_10, lbl_100_rodata_10};
    result = fn_100_B818(obj + 10, other);
    fn_100_B818(obj + 6, result);

    reinterpret_cast<unsigned char*>(obj)[0x31] = 0;
    reinterpret_cast<unsigned char*>(obj)[0x30] = 0;
    reinterpret_cast<unsigned char*>(obj)[0x32] = 1;
}
