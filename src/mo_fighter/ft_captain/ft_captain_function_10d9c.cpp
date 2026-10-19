#pragma force_active on
extern "C" {
extern const float lbl_100_rodata_74;
}

extern "C" void fn_100_10D9C(void* object) {
    char* storage = static_cast<char*>(object);
    float zero = lbl_100_rodata_74;
    *reinterpret_cast<float*>(storage + 0x24) = zero;
    *reinterpret_cast<float*>(storage + 0x28) = zero;
    *reinterpret_cast<float*>(storage + 0x2C) = zero;
    unsigned int flags = *reinterpret_cast<unsigned int*>(storage + 0x38);
    *reinterpret_cast<unsigned int*>(storage + 0x38) = flags & ~31u;
}
