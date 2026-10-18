#pragma force_active on
struct FighterFlags {
    unsigned char high : 1;
    unsigned char selected : 1;
    unsigned char low : 6;
};

extern "C" void fn_108_1093C(void* object, bool selected) {
    reinterpret_cast<FighterFlags*>(static_cast<unsigned char*>(object) + 0xA4)->selected = selected;
}
