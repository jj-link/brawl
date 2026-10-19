#pragma force_active on
extern "C" bool fn_88_3B90(void* object) {
    unsigned char* p = static_cast<unsigned char*>(object);
    if (p[0x1d8] > 3) {
        return true;
    }
    return p[0x5d4] == 1;
}
