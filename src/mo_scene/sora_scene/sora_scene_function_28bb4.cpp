#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;

struct Scene {
    u8 pad[0x18];
    s32 count;
    s32 index;
    s32 level;
    s32 stage;
};
struct Result {
    u8 pad[0x260];
    u32 value;
    u8 pad264[0x2a8];
    u32 value2;
};
struct Global {
    u8 pad[8];
    u8* mode;
    u8 padc[0xc];
    Result* result;
    u8 pad1c[0x20];
    u8* corps;
};
extern "C" {
extern Global* g_GameGlobal;
extern s32 lbl_1_data_7808[];
void fn_800514C4(s32);
void fn_1_2902C(Scene*);
}
static inline int lower(int x) { return x < 0 ? 0 : x; }
extern "C" void fn_1_28BB4(Scene* self) {
    u32 rem;
    Result* result = g_GameGlobal->result;
    u8* mode = g_GameGlobal->mode;
    rem = result->value % 10;
    u32 val = result->value - rem;
    if (val != 0) val = val / 20 * 10;
    if (rem < 9) ++rem;
    result->value = val + rem;
    if (self->count == 2) {
        u32 rem2 = result->value2 % 10;
        u32 val2 = result->value2 - rem2;
        if (val2 != 0) val2 = val2 / 20 * 10;
        if (rem2 < 9) ++rem2;
        result->value2 = val2 + rem2;
    }
    fn_800514C4(lbl_1_data_7808[self->index] * 10);
    for (int i = 0; i < self->count; ++i, mode += 0x5c) {
        mode[0x9c] = 1;
        *(u16*)(mode + 0xba) = 0;
    }
    u8* entry;
    u8* corps = g_GameGlobal->corps;
    for (int i = 0; i < corps[3]; ++i) {
        entry = corps + (corps[0x1c] + i) * 0x14;
        if (entry[0x24] >= 0x1d && entry[0x24] <= 0x22)
            entry[0x26] = 3;
        else
            entry[0x26] = 1;
        if (self->level < 3)
            entry[0x28] = lower(entry[0x28] - 10);
    }
    if (self->stage < 9) ++self->stage;
    if (self->level < 3) ++self->level;
    fn_1_2902C(self);
}
