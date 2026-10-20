#pragma force_active on
extern "C" unsigned int fn_27_112E20(unsigned int** arg) {
    unsigned char value = *reinterpret_cast<unsigned char*>(*arg + 8);
    int bit = (value >> 7) & 1;
    return (unsigned int)((-bit) | bit) >> 31;
}
