#include <gr/gr_tengan_event.h>
#include <nw4r/math/math_arithmetic.h>

#pragma force_active on

struct StOrpheon {
    char pad[0x3dc];
    grTenganEvent event;
    char pad2[0x5f0 - 0x3dc - sizeof(grTenganEvent)];
    float progress;
    char pad3[8];
    float waitTarget;
};

extern "C" {
extern const float lbl_55_rodata_0[];
float randf__Fv();

void fn_55_105C(void* self, float dt) {
    StOrpheon* s = (StOrpheon*)self;
    const float* rd = lbl_55_rodata_0;

    switch (s->event.getPhase()) {
    case 0:
        s->progress = rd[0];
        s->event.setPhase(s->event.getPhase() + 1);
        break;
    case 1:
        s->progress += rd[0x44 / 4] * dt;
        if (s->progress >= rd[0x48 / 4]) {
            s->progress = rd[0x48 / 4];
            s->event.setPhase(s->event.getPhase() + 1);
            s->event.m_manualFramesLeft = rd[0];
            s->waitTarget = rd[0x50 / 4] +
                            nw4r::math::FAbs(rd[0x4 / 4] - rd[0x4C / 4] * randf__Fv());
        }
        break;
    case 2:
        s->event.m_manualFramesLeft += dt;
        if (s->event.m_manualFramesLeft >= s->waitTarget)
            s->event.setPhase(s->event.getPhase() + 1);
        break;
    case 3:
        s->progress += rd[0x44 / 4] * dt;
        if (s->progress >= rd[0x40 / 4]) {
            s->progress = rd[0x40 / 4];
            s->event.setPhase(s->event.getPhase() + 1);
            s->event.m_manualFramesLeft = rd[0];
            s->waitTarget = rd[0x50 / 4] +
                            nw4r::math::FAbs(rd[0x4 / 4] - rd[0x4C / 4] * randf__Fv());
        }
        break;
    case 4:
        s->event.m_manualFramesLeft += dt;
        if (s->event.m_manualFramesLeft >= s->waitTarget)
            s->event.setPhase(s->event.getPhase() + 1);
        break;
    case 5:
        s->progress -= rd[0x44 / 4] * dt;
        if (s->progress < rd[0x48 / 4]) {
            s->progress = rd[0x48 / 4];
            s->event.m_manualFramesLeft = rd[0];
            s->event.setPhase(s->event.getPhase() + 1);
            s->waitTarget = rd[0x50 / 4] +
                            nw4r::math::FAbs(rd[0x4 / 4] - rd[0x4C / 4] * randf__Fv());
        }
        break;
    case 6:
        s->event.m_manualFramesLeft += dt;
        if (s->event.m_manualFramesLeft >= s->waitTarget)
            s->event.setPhase(s->event.getPhase() + 1);
        break;
    case 7:
        s->progress -= rd[0x44 / 4] * dt;
        if (s->progress < rd[0]) {
            s->event.m_manualFramesLeft = rd[0];
            s->progress = rd[0];
            s->event.setPhase(s->event.getPhase() + 1);
            s->waitTarget = rd[0x50 / 4] +
                            nw4r::math::FAbs(rd[0x4 / 4] - rd[0x4C / 4] * randf__Fv());
        }
        break;
    case 8:
        s->event.m_manualFramesLeft += dt;
        if (s->event.m_manualFramesLeft >= s->waitTarget) {
            s->event.end();
            s->event.start();
        }
        break;
    }

    s->event.update(dt);
}
}
