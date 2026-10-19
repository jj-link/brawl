#pragma force_active on
struct FlagByte {
    unsigned char high : 1;
    unsigned char low : 7;
};

extern "C" bool fn_11_7DA0(char* object, int index, int sub) {
    char* entry = *reinterpret_cast<char**>(object + (index << 4) + 0x54);
    FlagByte* flags = reinterpret_cast<FlagByte*>(entry + sub * 0x18 + 0x17);
    return flags->high == 1;
}
