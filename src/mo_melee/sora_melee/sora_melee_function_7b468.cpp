#pragma force_active on
extern "C" bool fn_27_7B468(unsigned int* self, int id, unsigned char* out) {
    if (id <= -1 || id >= 17)
        return false;

    unsigned int mask = 1u << id;
    if (self[2] & mask) {
        *out = (self[3] & mask) != 0;
        return true;
    }
    return false;
}
