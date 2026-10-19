#pragma force_active on
extern "C" int fn_100_9CE4();

extern "C" float fn_100_9C8C(char* base, int unused, int index, int lane) {
    char* p = base + fn_100_9CE4() * 0x94;
    p = p + index * 4;
    float* table = *reinterpret_cast<float**>(p - 0x3E70);
    return table[lane];
}
