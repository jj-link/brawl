#pragma force_active on
extern "C" float fn_98_A0E8(void* object, unsigned index) {
    float* values = *reinterpret_cast<float**>(static_cast<char*>(object) + 0x14);
    return values[index];
}
