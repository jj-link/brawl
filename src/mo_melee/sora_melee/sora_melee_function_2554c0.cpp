#pragma force_active on
#include <types.h>
#include <ip/ip_switch.h>

struct GameState {
    char pad0[8];
    u8 mode : 6;
    u8 modeLow : 2;
    char pad9[0x11];
    u16 kind;
    char pad1c[0x47];
    u8 flag63;
    u8 flag64;
    char pad65[3];
    int value68;
    int value6c;
};

struct GameGlobal {
    char pad0[8];
    GameState* state;
    char pad10[0x24];
    int unk30;
    char pad34[0xC];
    int unk40;
};

extern "C" {
extern GameGlobal* g_GameGlobal;
void fn_801104C4(void* arg0);
void fn_8004B060(void* obj, int arg1);
void fn_8004B0F8(void* obj, void* src);
void fn_8004B1F4(void* obj, int src, int size);
void fn_8004B184(void* obj, int src);
}

static inline bool isAllowed(u32 mode) {
    switch (mode) {
    case 13: case 15: case 17: case 19: case 21: case 22:
    case 25: case 27: case 29: case 30: case 31: case 32: case 33:
        return false;
    default:
        return true;
    }
}

extern "C" void fn_27_2554C0() {
    fn_801104C4(g_GameGlobal->state);
    GameState* state = g_GameGlobal->state;
    bool special = false;
    if (state->kind == 0x34 && state->flag63 == 0 && state->flag64 == 0) {
        special = true;
    }
    u8 value = 0;
    if (special) {
        value = state->value68 + state->value6c * 2;
    }
    if (!((((u8*)ipSwitch::getInstance())[0x24] >> 7) & 1)) {
        if (isAllowed(state->mode)) {
            void* obj = ipSwitch::getInstance()->m_keyRecorder;
            if (value == 0) {
                fn_8004B060(obj, state->mode == 8 ? 5 : 3);
                fn_8004B0F8(obj, state);
                if (state->kind == 0x35) {
                    fn_8004B1F4(obj, g_GameGlobal->unk40, 0x470);
                }
                if (state->mode == 6) {
                    fn_8004B184(obj, g_GameGlobal->unk30);
                }
            }
        }
    }
}
