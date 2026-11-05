#pragma force_active on

#include <cm/cm_camera_controller.h>
#include <gf/gf_pad_status.h>
#include <mt/mt_vector.h>

struct CrollItem {
    char pad0[0xA4];
    unsigned int flags;
    float distance;
    char padAC[0xC0 - 0xAC];
    unsigned char active;
    char padC1[0xF4 - 0xC1];
};

struct Croll {
    char pad0[0x200];
    int state;
    int mode;
    int phase;
    void* control;
    char pad210[8];
    CrollItem* items;
    void* scene;
    char pad220[8];
    int count;
    char pad22C[0x2A8 - 0x22C];
    float rotation[4];
    char pad2B8[0x2D8 - 0x2B8];
    Vec3f position;
    float startY;
    float endY;
    char pad2EC[0x308 - 0x2EC];
    int timer;
    float speed;
    int cameraKind;
};

extern "C" {
int fn_90_1C7C(int, gfPadStatus*);
int fn_90_1C94(CameraController*);
void fn_90_16E4(Croll*);
void fn_90_1C9C(float*);
void fn_90_1CA0(float*);
void fn_90_1EA4(float*, float*);
Vec3f* fn_90_12D8(Vec3f*, float, float, float);
void fn_90_12BC(Vec3f*, const Vec3f*);
void fn_90_13E8(void*);
void fn_90_1304(void*);
void fn_90_15CC(void*);
void fn_90_1ED4(Vec3f*, const Vec3f*);
void fn_90_181C(Croll*, float);
void fn_90_1EF0(CrollItem*, float, Vec3f*, float*, void*);
int fn_90_29B0(gfPadStatus*, unsigned int);
void fn_90_162C(Croll*, int);
int fn_90_29C8(void*);
void fn_90_29D4(void*, bool);
void fn_90_29FC(void*, gfPadStatus*, float);
void fn_90_3640(void*, float);
void fn_90_37F0(void*);
int fn_90_384C(void*, gfPadStatus*, float);
int fn_90_4C38(void*);
void fn_80051440(int);

extern const float lbl_90_rodata_0;
extern const float lbl_90_rodata_20;
extern const float lbl_90_rodata_24;
extern const float lbl_90_rodata_28;
extern const float lbl_90_rodata_3C;
}

extern "C" void fn_90_18F4(Croll* self, float delta) {
    gfPadStatus pad;
    float rotation[4];
    Vec3f initialPos;
    Vec3f activePos;
    Vec3f temp;

    fn_90_1C7C(0xF0, &pad);
    int oldKind = self->cameraKind;
    int kind = fn_90_1C94(CameraController::getInstance());
    if (oldKind != kind) {
        self->cameraKind = kind;
        if (kind == 2)
            fn_90_16E4(self);
    }

    fn_90_1C9C(rotation);
    fn_90_1CA0(rotation);
    fn_90_1EA4(self->rotation, rotation);

    switch (self->state) {
    case 0:
        fn_90_12BC(
            &self->position,
            fn_90_12D8(&temp, lbl_90_rodata_0,
                         lbl_90_rodata_24 + self->startY,
                         lbl_90_rodata_0));
        self->timer = 0;
        self->speed = lbl_90_rodata_28;
        fn_90_13E8(self->scene);
        if (self->phase == 2)
            self->state = 1;
        break;

    case 1:
        fn_90_1304(self->control);
        fn_90_15CC(self->scene);
        self->state = 2;
        fn_90_1ED4(&initialPos, &self->position);
        fn_90_181C(self, lbl_90_rodata_0);
        for (int i = 0; i < self->count; ++i)
            fn_90_1EF0(&self->items[i], lbl_90_rodata_0,
                         &initialPos, self->rotation, self->scene);
        break;

    case 2:
        if (self->phase == 2)
            self->phase = 3;

        if (fn_90_29B0(&pad, 0x181000))
            fn_90_162C(self, (self->mode + 1) & 1);

        fn_90_181C(self, delta);

        if (self->phase == 3) {
            fn_90_1ED4(&activePos, &self->position);
            float minimum = lbl_90_rodata_20;
            int selected = -1;

            for (int i = 0; i < self->count; ++i) {
                if (self->items[i].active) {
                    float distance = self->items[i].distance;
                    if (distance < minimum) {
                        minimum = distance;
                        selected = i;
                    }
                }
            }

            if (selected >= 0 && fn_90_29C8(self->control))
                self->items[selected].flags |= 0x40;

            for (int i = 0; i < self->count; ++i)
                fn_90_1EF0(&self->items[i], delta, &activePos,
                             self->rotation, self->scene);

            fn_90_29D4(self->control, selected >= 0);
            fn_90_29FC(self->control, &pad, delta);
            fn_90_3640(self->scene, delta);
        }

        if (self->position.m_y < self->endY - lbl_90_rodata_3C) {
            fn_90_162C(self, 0);
            self->state = 3;
            fn_90_37F0(self->scene);
        }
        break;

    case 3:
        fn_90_29FC(self->control, &pad, delta);
        fn_90_3640(self->scene, delta);
        if (fn_90_384C(self->scene, &pad, delta)) {
            fn_80051440(fn_90_4C38(self->scene) * 10);
            self->state = 4;
        }
        break;

    case 4:
        break;
    }
}
