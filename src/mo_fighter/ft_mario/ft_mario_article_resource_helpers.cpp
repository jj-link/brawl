struct MarioArticleFloatResources {
    unsigned char prefix[0x10];
    unsigned int firstBank;
    unsigned int reserved;
    const float* banks[6];
};
struct MarioArticleIntResources {
    unsigned char prefix[0x14];
    unsigned int firstBank;
    unsigned char middle[0x18];
    const int* banks[1];
};
struct MarioArticleIndefiniteResources {
    unsigned char prefix[0x18];
    unsigned int firstBank;
    unsigned char middle[0x18];
    void* banks[1];
};
extern "C" {
void* fn_91_141A0(void*, int);
int fn_27_8D3E4(void*);
void fn_91_140C4(void* object) {
    for (int index = 0; index < 12; ++index) {
        void* member = fn_91_141A0(static_cast<unsigned char*>(object) + 0xc, index);
        if (fn_27_8D3E4(static_cast<unsigned char*>(member) + 0x88) == 0) break;
    }
}
bool fn_91_14124(void*) { return true; }
void fn_91_1412C(void* object, unsigned char value) {
    static_cast<unsigned char*>(object)[0x16c30] = value;
}
float fn_91_14138(const MarioArticleFloatResources* resources, void*, unsigned int bank, unsigned int index) {
    return resources->banks[bank - resources->firstBank][index];
}
int fn_91_14158(const MarioArticleIntResources* resources, void*, unsigned int bank, unsigned int index) {
    return resources->banks[bank - resources->firstBank][index];
}
void* fn_91_14178(const MarioArticleIndefiniteResources* resources, void*, unsigned int bank) {
    return resources->banks[bank - resources->firstBank];
}
}
