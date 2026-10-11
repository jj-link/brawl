struct MarioSecondArticleFloatResources {
    unsigned char prefix[0x10];
    unsigned int firstBank;
    unsigned int reserved;
    const float* banks[7];
};
struct MarioSecondArticleIntResources {
    unsigned char prefix[0x14];
    unsigned int firstBank;
    unsigned char middle[0x1c];
    const int* banks[1];
};
struct MarioSecondArticleIndefiniteResources {
    unsigned char prefix[0x18];
    unsigned int firstBank;
    unsigned char middle[0x24];
    void* banks[1];
};
extern "C" {
bool fn_91_16B14(void*) { return false; }
void fn_91_16B1C(void*) {}
void fn_91_16B20(void*) {}
void fn_91_16B24(void*) {}
void fn_91_16B28(void*) {}
void fn_91_16B2C(void*) {}
void fn_91_16B30(void*) {}
void fn_91_16B34(void*) {}
void fn_91_16B38(void*) {}
float fn_91_16B3C(const MarioSecondArticleFloatResources* resources, void*, unsigned int bank, unsigned int index) {
    return resources->banks[bank - resources->firstBank][index];
}
int fn_91_16B5C(const MarioSecondArticleIntResources* resources, void*, unsigned int bank, unsigned int index) {
    return resources->banks[bank - resources->firstBank][index];
}
void* fn_91_16B7C(const MarioSecondArticleIndefiniteResources* resources, void*, unsigned int bank) {
    return resources->banks[bank - resources->firstBank];
}
}
