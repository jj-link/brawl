#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;

struct Scene {
    u8 pad0[0x24];
    s32 count24;
    s32 count28;
    u8 pad2c[5];
    u8 field31;
    u8 field32;
};

struct Result {
    u8 pad[0x260];
    u32 value;
};

struct Global {
    u8 pad0[8];
    u8* mode;
    u32 padc;
    u8* select;
    u32 pad14;
    Result* result;
    u8 pad1c[0x20];
    u8* corps;
};

extern "C" {
extern Global* g_GameGlobal;
extern s32 lbl_1_data_7298[5];
void fn_800514C4(s32);
}

static inline int lower(int x) {
    return x < 0 ? 0 : x;
}

extern "C" void fn_1_25EA0(Scene* self) {
    u32 rem;
    Result* result = g_GameGlobal->result;
    u8* select = g_GameGlobal->select;
    rem = result->value % 10;
    u32 val = result->value - rem;
    if (val != 0) val = val / 20 * 10;
    if (rem < 9) ++rem;
    result->value = val + rem;

    fn_800514C4(lbl_1_data_7298[self->field32] * 10);

    u8 x = (select[0x2e] >> 2) & 7;
    self->field31 = x;
    u8* mode = g_GameGlobal->mode;
    mode[0x9c] = x;
    *(u16*)(mode + 0xba) = 0;
    mode[0xa0] = 0;
    mode[0xfc] = 1;
    mode[0x158] = 2;
    mode[0x1b4] = 3;

    if (self->count28 < 9) ++self->count28;
    if (self->count24 < 3) {
        ++self->count24;
        if ((((u32)mode[8] >> 2) & 63) != 6) {
            if (mode[0x14] == 0) {
                u8* player = mode + 0x5c;
                for (int i = 1; i < 4; ++i, player += 0x5c) {
                    if ((u32)player[0x99] == 1 &&
                        ((u32)mode[0x13] != 1 ||
                         (u32)mode[0xa3] != (u32)player[0xa3])) {
                        player[0xb7] = lower(player[0xb7] - 10);
                    }
                }
            } else {
                u8* corps = g_GameGlobal->corps;
                corps[0xc] = lower(corps[0xc] - 10);
            }
        }
    }
}
