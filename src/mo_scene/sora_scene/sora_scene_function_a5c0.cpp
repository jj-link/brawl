#pragma force_active on

typedef unsigned int u32;
typedef unsigned char u8;

struct Scene { char pad[0x10]; int index; };
struct State { u8 pad; u8 mode; u8 pad2[2]; u8 stage; };
struct GameGlobal { char pad[0x2c]; State* state; };

extern "C" GameGlobal* g_GameGlobal;

struct Table { u32 values[3][9][5]; };
extern "C" const Table lbl_1_rodata_4B0;

extern "C" int fn_1_A5C0(Scene* self, int* index, int* count) {
    Table table = lbl_1_rodata_4B0;
    int mode = g_GameGlobal->state->mode - 2;
    int stage = g_GameGlobal->state->stage;
    int idx = *index;
    int cnt = *count;
    ++cnt;
    int result = 0;
    u32 value = *(u32*)((char*)&table + mode * 180 + stage * 20 + self->index * 4);
    if (value == (u32)cnt) {
        ++idx;
        cnt = 0;
        if (*(u32*)((char*)&table + mode * 180 + stage * 20 + idx * 4) == 0) {
            result = 11;
        } else if (*(u32*)((char*)&table.values[0][0][1] + mode * 180 + stage * 20 + idx * 4) == 0) {
            result = 10;
        }
    } else if (*(u32*)((char*)&table.values[0][0][1] + mode * 180 + stage * 20 + idx * 4) == 0 && idx != 0) {
        result = 10;
    }
    *index = idx;
    *count = cnt;
    return result;
}
