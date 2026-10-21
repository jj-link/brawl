#pragma force_active on

struct Object {
    unsigned char padding[0x6E];
    unsigned char flag : 1;
    unsigned char unused : 7;
};

extern unsigned char* g_GameGlobal;

extern "C" bool fn_27_10AB14(Object* object, void* unused, int value) {
    unsigned char* state =
        *reinterpret_cast<unsigned char**>(g_GameGlobal + 0x18);
    unsigned char* entry = state + 0x24;

    for (int i = 0; i < 7; ++i) {
        if (static_cast<bool>(object->flag) == true) {
            if (entry[1] != 3 && entry[0] == value &&
                entry[6] != state[0x1E]) {
                return true;
            }
        } else if (entry[1] != 3 && entry[0] == value) {
            return true;
        }
        entry += 0x2AC;
    }

    return false;
}
