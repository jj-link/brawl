struct MarioThirdArticleFloatResources {
    unsigned char prefix[0x10];
    unsigned int firstBank;
    unsigned int reserved;
    const float* banks[1];
};
struct MarioThirdArticleIntResources {
    unsigned char prefix[0x14];
    unsigned int firstBank;
    unsigned char middle[0x8];
    const int* banks[1];
};
struct MarioThirdArticleIndefiniteResources {
    unsigned char prefix[0x18];
    unsigned int firstBank;
    unsigned char middle[0xc];
    void* banks[1];
};
extern "C" {
bool fn_91_18F3C(void*) { return false; }
float fn_91_18F44(const MarioThirdArticleFloatResources* resources, void*, unsigned int bank, unsigned int index) {
    return resources->banks[bank - resources->firstBank][index];
}
int fn_91_18F64(const MarioThirdArticleIntResources* resources, void*, unsigned int bank, unsigned int index) {
    return resources->banks[bank - resources->firstBank][index];
}
void* fn_91_18F84(const MarioThirdArticleIndefiniteResources* resources, void*, unsigned int bank) {
    return resources->banks[bank - resources->firstBank];
}
}
