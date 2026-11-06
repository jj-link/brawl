#include <cm/cm_camera_controller.h>
#include <cm/cm_controller_ai.h>
#include <mt/mt_prng.h>
#pragma force_active on

struct Words4 { unsigned int a, b, c, d; };
struct Words3 { unsigned int a, b, c; };
struct Vec4 { float x, y, z, w; };
struct Target {
    char pad0[8];
    unsigned int flags;
    char padc[4];
    Vec3f pos;
    char pad1c[0x50];
    float value;
    char pad70[4];
    Vec4 rect;
};
struct Owner {
    char pad0[0x60];
    Vec3f pos;
    char pad6c[0x30];
    Vec3f a;
    char pada8[0xc];
    Vec3f b;
};
struct State {
    Owner* owner;
    void* p4;
    int kind;
    float time;
    unsigned char fixed;
    char pad11[3];
    float angle, rotation, value;
    Vec4 v20;
    Vec4 rect;
    float x, y, fov;
};
extern "C" Target* fn_800AADDC(int);
extern "C" void fn_8009FCF4(cmAIController*, float);
extern Vec4 lbl_80455038;
extern const float lbl_805A2170, lbl_805A2178, lbl_805A217C, lbl_805A2180;
extern const float lbl_805A2184, lbl_805A2188, lbl_805A218C, lbl_805A2190, lbl_805A2194;

inline bool inRange(const Vec3f& pos) {
    CameraController* camera = CameraController::getInstance();
    float* bounds = (float*)camera->_328;
    if (pos.m_x < bounds[0] || pos.m_x > bounds[1] || pos.m_y > bounds[2] || pos.m_y < bounds[3]) return false;
    else return true;
}
extern "C" void fn_800AAAD8(State* self, int kind) {
    Owner* owner = self->owner;
    self->kind = kind;
    self->time = lbl_805A2170;
    if (owner) {
        Vec3f zero(lbl_805A2170, lbl_805A2170, lbl_805A2170);
        if (kind < 5 || kind > 9) {
            owner->a = zero;
            owner->b = zero;
        }
    }
    switch (kind) {
    case 0: {
        cmAIController* ai = g_cmAIController;
        if (!((((unsigned char*)ai)[0x94] >> 4) & 1))
            ((unsigned char*)ai)[0x94] |= 0x10;
        fn_8009FCF4(ai, lbl_805A2180);
        break;
    }
    case 1: case 2: case 3: case 4: {
        if (self->fixed) {
            self->angle = lbl_805A2170;
            self->rotation = lbl_805A2170;
        } else {
            self->rotation = lbl_805A2184 * (lbl_805A2188 * randf() - lbl_805A2178);
            self->angle = lbl_805A218C * -randf();
        }
        Target* target = fn_800AADDC(kind - 1);
        self->value = target ? target->value : lbl_805A2190;
        break;
    }
    case 5: case 6: case 7: case 8: {
        Target* target = fn_800AADDC(kind - 5);
        Vec3f pos;
        if (target && ((target->flags >> 16) & 1))
            *(struct Words3*)&pos = *(struct Words3*)&target->pos;
        else {
            pos.m_x = lbl_805A2170;
            pos.m_y = lbl_805A2170;
            pos.m_z = lbl_805A2170;
        }
        Vec4 rect2;
        Vec4 rect = lbl_80455038;
        if (target) {
            float w = target->rect.w;
            float z = target->rect.z;
            float y = target->rect.y;
            float x = target->rect.x;
            rect.y = y;
            rect.x = x;
            rect.z = z;
            rect.w = w;
        }
        *(Words4*)&rect2 = *(Words4*)&rect;
        self->rect.x = rect2.x;
        self->rect.y = rect2.y;
        self->rect.z = rect2.z;
        self->rect.w = rect2.w;
        if (!(target && ((target->flags >> 16) & 1) && inRange(pos)))
            pos = self->owner->pos;
        self->x = pos.m_x;
        self->y = pos.m_y;
        self->rotation = lbl_805A2170;
        self->angle = lbl_805A2194;
        float fov = lbl_805A217C;
        cmStageParam* param = &CameraController::getInstance()->m_stageCameraParam;
        if (param) fov = param->m_48;
        self->fov = fov;
        break;
    }
    case 9: {
        float fov = lbl_805A217C;
        cmStageParam* param = &CameraController::getInstance()->m_stageCameraParam;
        if (param) fov = param->m_48;
        self->fov = fov;
        break;
    }
    }
}