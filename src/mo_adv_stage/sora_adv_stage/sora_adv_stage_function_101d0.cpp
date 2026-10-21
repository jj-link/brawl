#pragma force_active on
typedef int s32;
typedef unsigned char u8;

struct Vec3 {
    float x;
    float y;
    float z;
};

struct Sub {
    u8 pad[0x14];
    s32 sndId;
};

struct Obj {
    u8 pad[0xc];
    Sub* sub;
};

extern "C" {
void* fn_8009D2DC();
void fn_8009D564(void*, unsigned long, Vec3*);
void playSE__9sndSystemF5SndIDiiii(void*, s32, s32, s32, s32, s32);
extern void* g_sndSystem;

void fn_40_101D0(void* self) {
    Sub* sub = ((Obj*)self)->sub;
    u8 state = sub->pad[0xc];
    switch (state) {
    case 0:
        fn_8009D564(fn_8009D2DC(), 3, (Vec3*)sub);
        break;
    case 1:
        fn_8009D564(fn_8009D2DC(), 4, (Vec3*)sub);
        break;
    case 2:
        fn_8009D564(fn_8009D2DC(), 5, (Vec3*)sub);
        break;
    default:
        break;
    }
    playSE__9sndSystemF5SndIDiiii(g_sndSystem, ((Obj*)self)->sub->sndId, 0, 0, 0, -1);
}
}
