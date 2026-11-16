#include <types.h>
#include <ai/ai_mgr.h>
#include <mt/mt_vector.h>
#pragma force_active on
extern "C" void fn_27_1F299C(aiMgr*, int);
extern "C" const float lbl_50_rodata_0[];
struct StDonkeySelf {
    char p0[0x1DC]; f32 f1dc;
    char p1[0x214 - 0x1E0]; f32 f214; f32 f218;
    char p2[0x310 - 0x21C]; f32 f310;
    char p3[0x3DC - 0x314]; f32 f3dc; f32 f3e0;
    char p4[0x3F8 - 0x3E4]; u8 state;
    char p5[0x418 - 0x3F9]; s32 d418;
    char p6[0x420 - 0x41C]; s32 d420;
};
inline void setVec(Vec2f& v, float x, float y) {
    v.m_x = x;
    v.m_y = y;
}
extern "C" void fn_50_1924(StDonkeySelf* self) {
    const float* rodata = lbl_50_rodata_0;
    if (self->state == 3) {
        Vec2f b;
        Vec2f a(self->f3dc, self->f3e0);
        setVec(b, self->f310, self->f1dc - rodata[16]);
        self->d418 = g_aiMgr->setDangerZone(&a, &b, self->d418, false, false);
    } else if (self->d418 != -1) {
        fn_27_1F299C(g_aiMgr, self->d418);
        self->d418 = -1;
    }
    Vec2f d;
    Vec2f c(self->f214 - rodata[17], rodata[9] + self->f218);
    setVec(d, rodata[17] + self->f214, self->f218 - rodata[18]);
    self->d420 = g_aiMgr->setDangerZone(&c, &d, self->d420, false, false);
}