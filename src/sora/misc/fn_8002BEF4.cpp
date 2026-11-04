#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;
typedef long s32;
struct RumbleEntry {
    u32 input;
    u8 priority;
    u8 pad5[3];
};
struct gfRumble {
    char pad0[0xF0];
    RumbleEntry* unkF0;
    RumbleEntry* unkF4;
    u16 unkF8;
    u8 padFA[2];
    float unkFC;

    void lbSetRumble(s32, s32, s32, s32, s32);
};
extern "C" int fn_8002C510(gfRumble* self, s32 index, s32 value, s32 data, u8 priority, u32 input, s32 type);
void gfRumble::lbSetRumble(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    if (arg0 < 4) {
        fn_8002C510(this, arg0, arg1, arg3 != 0 ? arg3 : -2, unkF0[arg2].priority, unkF0[arg2].input, arg4);
        return;
    }
    if (arg3 > 0x1E) {
        arg3 = unkF8 + (s32)(unkFC * (float)(arg3 - unkF8));
    }
    fn_8002C510(this, arg0, arg1, arg3 != 0 ? arg3 : -2, unkF4[arg2].priority, unkF4[arg2].input, arg4);
}
