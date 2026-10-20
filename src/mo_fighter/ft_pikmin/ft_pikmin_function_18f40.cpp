#pragma force_active on
static inline bool first(int value) {
    switch (value) {
    case 0x1e:
    case 0x1f:
    case 0x2c:
        return true;
    default:
        return false;
    }
}

static inline bool second(int value) {
    switch (value) {
    case 0x2b:
    case 0x2c:
    case 0x2d:
        return true;
    default:
        return false;
    }
}

extern "C" bool fn_113_18F40(void*, int value) {
    if (first(value) == true)
        return false;
    if (second(value) == true)
        return false;
    return true;
}
