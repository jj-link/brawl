#pragma force_active on
extern "C" int fn_27_20B668(unsigned char* self) {
    if (*(unsigned char*)(self + 0x1ba) == 2) {
        return 1;
    }
    return (*(unsigned int*)(self + 0x54) & 0x6400) == 0x6400;
}
