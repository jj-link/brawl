#include <types.h>
#include <gr/gr_yakumono.h>
#include <mt/mt_vector.h>
#include <math.h>
#include <nw4r/ut/ut_algorithm.h>
#pragma force_active on

extern "C" {
extern const float lbl_40_rodata_6A0;
extern const float lbl_40_rodata_6BC;
extern float lbl_27_data_547E0;
}

struct MovementParams {
    char pad[0x28];
    float speed;
};

struct MovingGimmick : grYakumono {
    MovementParams* params;
    char pad154[4];
    u8 state;
    char pad159[3];
    float frame;
    Vec3f* positions;
    char pad164[4];
    u32 currentIndex;
    u32 targetIndex;
    float traveled;
    float remaining;
    float threshold;
    float acceleration;
    float speed;
    float duration;
};

static inline float magnitude(float value) {
    return (float)(double)nw4r::ut::Abs(value);
}

extern "C" void fn_40_354A0(MovingGimmick* self) {
    float oldSpeed = self->speed;
    double threshold = fabs(self->threshold);
    double traveled = fabs(self->traveled);
    if ((float)traveled < (float)threshold) {
        self->speed = oldSpeed + self->acceleration;
    } else {
        float remaining = fabs(self->remaining);
        if (remaining < (float)threshold) {
            self->speed = oldSpeed - self->acceleration;
        } else if (self->remaining > lbl_40_rodata_6A0) {
            self->speed = self->params->speed;
        } else {
            self->speed = -self->params->speed;
        }
    }

    Vec3f pos;
    pos = self->grGimmick::getPos();
    pos.m_y += self->speed;
    self->traveled += self->speed;
    self->remaining -= self->speed;

    if (self->duration - self->frame <= lbl_40_rodata_6BC) {
        float delta = lbl_27_data_547E0;
        if (self->duration - self->frame > lbl_40_rodata_6BC - delta) {
            self->startGimmickSE(3);
        }
    }

    if ((oldSpeed < lbl_40_rodata_6A0 && self->speed >= lbl_40_rodata_6A0) ||
        (oldSpeed > lbl_40_rodata_6A0 && self->speed <= lbl_40_rodata_6A0)) {
        goto reached;
    }
    {
        double step = fabs(self->speed);
        double distance = fabs(self->remaining);
        if (!((float)distance < (float)step)) {
            goto finished;
        }
    }
reached:
    {
        pos.m_y = self->positions[self->targetIndex].m_y;
        self->state = 2;
        self->frame = lbl_40_rodata_6A0;
        self->currentIndex = self->targetIndex;
        self->stopGimmickSE(0);
        self->startGimmickSE(1);
        self->grYakumono::enableArea();
    }
finished:
    self->grGimmick::setPos(&pos);
}
