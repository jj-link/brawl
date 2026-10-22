#pragma force_active on
typedef float f32;
typedef int s32;

struct Vec3 {
    f32 x, y, z;
};

extern "C" void fn_801ECD70(void*, s32, void*);
extern "C" void fn_80162C48(void*, void*, void*);

extern unsigned char lbl_8049E030[];
extern unsigned char lbl_8049E060[];
extern f32 lbl_805A02B8[2];
extern const f32 lbl_805A2344;

extern "C" void fn_800DB5F4(s32 arg0, Vec3* arg1) {
    Vec3 sp14;
    Vec3 sp8;

    fn_801ECD70(lbl_8049E030, arg0, &sp14);
    fn_80162C48(&sp8, lbl_8049E060, &sp14);

    arg1->x = sp8.x * lbl_805A02B8[0];
    arg1->y = sp8.y * lbl_805A02B8[1];
    arg1->z = lbl_805A2344;
}
