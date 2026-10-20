#pragma force_active on
extern "C" int fn_27_2480CC(int);
extern "C" int exchangeGmCharacterKind2MuSelchkind__6muMenuFiii(int);
extern "C" int getNumCharColor__6muMenuFiii(int);

struct GameGlobal {
    unsigned char pad[8];
    unsigned char* data;
};

extern GameGlobal* g_GameGlobal;

extern "C" int fn_1_3D1D8(int kind, int color, int player) {
    unsigned char* data = g_GameGlobal->data;
    int mapped = fn_27_2480CC(kind);
    if (mapped != 0x23) {
        unsigned int mask = 0;
        for (int i = 0; i < 4; ++i, data += 0x5c) {
            if (i != player && data[0x99] != 3 &&
                mapped == fn_27_2480CC(data[0x98])) {
                mask |= 1 << data[0x9e];
            }
        }
        if (mask & (1 << color)) {
            int sel = exchangeGmCharacterKind2MuSelchkind__6muMenuFiii(kind);
            int count;
            if (sel == 0x28) {
                count = 1;
            } else {
                count = getNumCharColor__6muMenuFiii(sel);
            }
            for (int i = 0; i < count; ++i) {
                color = (color + 1) % count;
                if (!(mask & (1 << color))) {
                    break;
                }
            }
        }
    }
    return color;
}
