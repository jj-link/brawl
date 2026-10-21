#pragma force_active on
extern "C" bool fn_27_8C08C(void*, int, int id);

extern "C" bool fn_27_14B4B0(void* a, int b, int id) {
    if (fn_27_8C08C(a, b, id) == 1) {
        return true;
    }
    if (id > 0x3e7 && id < 0x40d) {
        if (id >= 0x3f2 && id <= 0x404) {
            return true;
        }
    } else if (id > 0x5207 && id < 0x5226) {
        if (id >= 0x5209 && id <= 0x521d) {
            return true;
        }
    }
    return false;
}
