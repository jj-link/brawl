#include <types.h>
#include <mt/mt_vector.h>
#include <nw4r/math/math_arithmetic.h>
#include <revolution/OS/OSFastCast.h>
#pragma force_active on

extern "C" {
extern const float lbl_80_rodata_0[];
void* getGround__5StageFi(void*, int);
void* getInstance__16CameraControllerFv();
float fn_801622C4(float);
void fn_27_1F299C(void*, int);
int setDangerZone__5aiMgrFP5Vec2fP5Vec2fibb(void*, Vec2f*, Vec2f*, int, bool, bool);
}
extern void* g_aiMgr;

struct Pad3C { char pad[0x3C]; };

#define V(n) virtual void n();
class Ground : public Pad3C {
public:
    V(vf0) V(vf1) V(vf2) V(vf3) V(vf4) V(vf5) V(vf6) V(vf7) V(vf8) V(vf9)
    V(vf10) V(vf11) V(vf12) V(vf13) V(vf14) V(vf15) V(vf16) V(vf17) V(vf18) V(vf19)
    V(vf20) V(vf21) V(vf22) V(vf23) V(vf24) V(vf25) V(vf26) V(vf27) V(vf28) V(vf29)
    V(vf30) V(vf31) V(vf32) V(vf33) V(vf34) V(vf35) V(vf36) V(vf37) V(vf38) V(vf39)
    V(vf40) V(vf41) V(vf42) V(vf43) V(vf44) V(vf45) V(vf46) V(vf47) V(vf48) V(vf49)
    V(vf50) V(vf51) V(vf52) V(vf53) V(vf54) V(vf55) V(vf56) V(vf57) V(vf58) V(vf59)
    V(vf60) V(vf61) V(vf62) V(vf63) V(vf64) V(vf65) V(vf66)
    virtual float vf67(int, float, float, float, float);
};
#undef V

inline float clampRange(float value, float lo, float hi) {
    float t = nw4r::math::FSelect(value - lo, value, lo);
    return nw4r::math::FSelect(t - hi, hi, t);
}

extern "C" void fn_80_1CCC(void* arg) {
    Vec3f tgt;
    Vec3f pos;
    Vec2f b;
    Vec2f a;
    u8* self = (u8*)arg;
    const float* k = lbl_80_rodata_0;

    Ground* ground = (Ground*)getGround__5StageFi(self, 1);
    if (ground == 0) return;

    u8* cam = (u8*)getInstance__16CameraControllerFv();
    float py = *(float*)(cam + 0x160);
    float px = *(float*)(cam + 0x158);
    pos.m_x = px;
    pos.m_y = py;
    pos.m_z = k[0];
    float ty = *(float*)(cam + 0x164);
    float tx = *(float*)(cam + 0x15C);
    tgt.m_x = tx;
    tgt.m_y = ty;
    tgt.m_z = k[0];

    float v = ground->vf67(0, px, py, tx, ty);

    if (v > k[20] && v < k[21]) {
        float t = (v - k[20]) / k[22];
        t = clampRange(t, k[0], k[1]);
        u16 ang = (u16)(k[23] * t);
        float r = fn_801622C4(k[24] * __OSu16tof32(&ang));
        b.m_x = tgt.m_x;
        a.m_x = tgt.m_x - r * (k[25] * (tgt.m_x - pos.m_x));
        b.m_y = tgt.m_y;
        a.m_y = tgt.m_y + k[3] * (pos.m_y - tgt.m_y);
        *(int*)(self + 0xFFC) = setDangerZone__5aiMgrFP5Vec2fP5Vec2fibb(
            g_aiMgr, &a, &b, *(int*)(self + 0xFFC), false, false);
    } else {
        int cur = *(int*)(self + 0xFFC);
        if (cur != -1) {
            fn_27_1F299C(g_aiMgr, cur);
            *(int*)(self + 0xFFC) = -1;
        }
    }

    if (v > k[26] && v < k[27]) {
        float t = (v - k[26]) / k[28];
        t = clampRange(t, k[0], k[1]);
        u16 ang = (u16)(k[23] * t);
        float r = fn_801622C4(k[24] * __OSu16tof32(&ang));
        a.m_x = pos.m_x;
        a.m_y = pos.m_y;
        b.m_x = pos.m_x + r * (k[29] * (tgt.m_x - pos.m_x));
        b.m_y = tgt.m_y;
        *(int*)(self + 0x1000) = setDangerZone__5aiMgrFP5Vec2fP5Vec2fibb(
            g_aiMgr, &a, &b, *(int*)(self + 0x1000), false, false);
    } else if (v >= k[27] && v < k[30]) {
        float t = (v - k[27]) / k[31];
        float u = k[1] - t;
        u = clampRange(u, k[0], k[1]);
        u16 ang = (u16)(k[23] * u);
        float r = fn_801622C4(k[24] * __OSu16tof32(&ang));
        a.m_x = pos.m_x;
        a.m_y = pos.m_y;
        b.m_x = pos.m_x + (k[32] + k[32] * r) * (tgt.m_x - pos.m_x);
        b.m_y = tgt.m_y;
        *(int*)(self + 0x1000) = setDangerZone__5aiMgrFP5Vec2fP5Vec2fibb(
            g_aiMgr, &a, &b, *(int*)(self + 0x1000), false, false);
    } else if (v >= k[30] && v < k[33]) {
        float t = (v - k[30]) / k[28];
        float u = k[1] - t;
        u = clampRange(u, k[0], k[1]);
        u16 ang = (u16)(k[23] * u);
        float r = fn_801622C4(k[24] * __OSu16tof32(&ang));
        a.m_x = pos.m_x;
        a.m_y = pos.m_y;
        b.m_x = pos.m_x + r * (k[32] * (tgt.m_x - pos.m_x));
        b.m_y = tgt.m_y;
        *(int*)(self + 0x1000) = setDangerZone__5aiMgrFP5Vec2fP5Vec2fibb(
            g_aiMgr, &a, &b, *(int*)(self + 0x1000), false, false);
    } else if (v >= k[33] && v < k[34]) {
        float t = (v - k[33]) / k[35];
        t = clampRange(t, k[0], k[1]);
        u16 ang = (u16)(k[23] * t);
        float r = fn_801622C4(k[24] * __OSu16tof32(&ang));
        a.m_x = pos.m_x;
        a.m_y = pos.m_y;
        b.m_x = pos.m_x + r * (k[29] * (tgt.m_x - pos.m_x));
        b.m_y = tgt.m_y;
        *(int*)(self + 0x1000) = setDangerZone__5aiMgrFP5Vec2fP5Vec2fibb(
            g_aiMgr, &a, &b, *(int*)(self + 0x1000), false, false);
    } else if (v >= k[34] && v < k[36]) {
        float t = (v - k[34]) / k[28];
        t = clampRange(t, k[0], k[1]);
        u16 ang = (u16)(k[23] * t);
        float r = fn_801622C4(k[24] * __OSu16tof32(&ang));
        a.m_x = pos.m_x;
        a.m_y = pos.m_y;
        b.m_x = pos.m_x + (k[29] + k[32] * r) * (tgt.m_x - pos.m_x);
        b.m_y = tgt.m_y;
        *(int*)(self + 0x1000) = setDangerZone__5aiMgrFP5Vec2fP5Vec2fibb(
            g_aiMgr, &a, &b, *(int*)(self + 0x1000), false, false);
    } else {
        int cur = *(int*)(self + 0x1000);
        if (cur != -1) {
            fn_27_1F299C(g_aiMgr, cur);
            *(int*)(self + 0x1000) = -1;
        }
    }

    if (v > k[37] && v < k[27]) {
        float t = (v - k[37]) / k[38];
        t = clampRange(t, k[0], k[1]);
        u16 ang = (u16)(k[23] * t);
        float r = fn_801622C4(k[24] * __OSu16tof32(&ang));
        a.m_x = pos.m_x;
        a.m_y = tgt.m_y + r * (k[39] * (pos.m_y - tgt.m_y));
        b.m_x = tgt.m_x;
        b.m_y = tgt.m_y;
        *(int*)(self + 0x1004) = setDangerZone__5aiMgrFP5Vec2fP5Vec2fibb(
            g_aiMgr, &a, &b, *(int*)(self + 0x1004), false, false);
    } else if (v >= k[27] && v < k[40]) {
        float t = (v - k[27]) / k[41];
        float u = k[1] - t;
        u = clampRange(u, k[0], k[1]);
        u16 ang = (u16)(k[23] * u);
        float r = fn_801622C4(k[24] * __OSu16tof32(&ang));
        a.m_x = pos.m_x;
        a.m_y = tgt.m_y + r * (k[39] * (pos.m_y - tgt.m_y));
        b.m_x = tgt.m_x;
        b.m_y = tgt.m_y;
        *(int*)(self + 0x1004) = setDangerZone__5aiMgrFP5Vec2fP5Vec2fibb(
            g_aiMgr, &a, &b, *(int*)(self + 0x1004), false, false);
    } else if (v > k[42] && v < k[43]) {
        float t = (v - k[42]) / k[7];
        t = clampRange(t, k[0], k[1]);
        u16 ang = (u16)(k[23] * t);
        float r = fn_801622C4(k[24] * __OSu16tof32(&ang));
        a.m_x = pos.m_x;
        a.m_y = pos.m_y;
        b.m_x = tgt.m_x;
        b.m_y = pos.m_y - r * (k[3] * (pos.m_y - tgt.m_y));
        *(int*)(self + 0x1004) = setDangerZone__5aiMgrFP5Vec2fP5Vec2fibb(
            g_aiMgr, &a, &b, *(int*)(self + 0x1004), false, false);
    } else if (v > k[43] && v < k[44]) {
        float t = (v - k[43]) / k[28];
        float u = k[1] - t;
        u = clampRange(u, k[0], k[1]);
        u16 ang = (u16)(k[23] * u);
        float r = fn_801622C4(k[24] * __OSu16tof32(&ang));
        a.m_x = pos.m_x;
        a.m_y = pos.m_y;
        b.m_x = tgt.m_x;
        b.m_y = pos.m_y - r * (k[3] * (pos.m_y - tgt.m_y));
        *(int*)(self + 0x1004) = setDangerZone__5aiMgrFP5Vec2fP5Vec2fibb(
            g_aiMgr, &a, &b, *(int*)(self + 0x1004), false, false);
    } else {
        int cur = *(int*)(self + 0x1004);
        if (cur != -1) {
            fn_27_1F299C(g_aiMgr, cur);
            *(int*)(self + 0x1004) = -1;
        }
    }
}
