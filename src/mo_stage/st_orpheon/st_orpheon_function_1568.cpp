#include <gr/gr_tengan_event.h>
#include <nw4r/math/math_arithmetic.h>

#pragma force_active on

struct StOrpheon {
    char pad[0x534];
    grTenganEvent event;
    char pad2[0x18];
    float f5f8;
    char pad3[8];
    float f604;
};

extern "C" {
extern const float lbl_55_rodata_0[];
float randf__Fv();

void fn_55_1568(StOrpheon* self, float dt) {
    const float* rd = lbl_55_rodata_0;

    switch (self->event.getPhase()) {
    case 0:
        self->f5f8 = rd[0];
        self->event.setPhase(self->event.getPhase() + 1);
        break;
    case 1:
        self->f5f8 += rd[17] * dt;
        if (self->f5f8 >= rd[16]) {
            self->f5f8 = rd[16];
            self->event.setPhase(self->event.getPhase() + 1);
            self->event.m_manualFramesLeft = rd[0];
            self->f604 = rd[20] +
                         nw4r::math::FAbs(rd[20] - rd[21] * randf__Fv());
        }
        break;
    case 2:
        self->event.m_manualFramesLeft += dt;
        if (self->event.m_manualFramesLeft >= self->f604)
            self->event.setPhase(self->event.getPhase() + 1);
        break;
    case 3:
        self->f5f8 -= rd[17] * dt;
        if (self->f5f8 < rd[0]) {
            self->event.m_manualFramesLeft = rd[0];
            self->f5f8 = rd[0];
            self->event.setPhase(self->event.getPhase() + 1);
            self->f604 = rd[22] +
                         nw4r::math::FAbs(rd[20] - rd[21] * randf__Fv());
        }
        break;
    case 4:
        self->event.m_manualFramesLeft += dt;
        if (self->event.m_manualFramesLeft >= self->f604) {
            self->event.end();
            self->event.start();
        }
        break;
    }

    self->event.update(dt);
}
}
