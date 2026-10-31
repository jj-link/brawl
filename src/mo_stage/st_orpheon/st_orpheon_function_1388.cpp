#pragma force_active on

#include <gr/gr_tengan_event.h>

struct StOrpheon {
    char padding[0x488];
    grTenganEvent event;
    char padding2[0xC0];
    float progress;
    char padding3[8];
    float waitTarget;
};

extern "C" {
extern const float lbl_55_rodata_0[];
float randf__Fv();

void fn_55_1388(void* self, float delta) {
    StOrpheon* s = (StOrpheon*)self;
    const float* rd = lbl_55_rodata_0;

    switch (s->event.getPhase()) {
    case 0:
        s->progress = rd[0];
        s->event.setPhase(s->event.getPhase() + 1);
        break;

    case 1:
        s->progress += rd[0x44 / 4] * delta;
        if (s->progress >= rd[0x40 / 4]) {
            s->progress = rd[0x40 / 4];
            s->event.setPhase(s->event.getPhase() + 1);
            s->event.m_manualFramesLeft = rd[0];

            float random = randf__Fv();
            float base = rd[0x50 / 4];
            float spread = rd[0x54 / 4];
            float scaled = spread * random;
            float offset = base - scaled;
            s->waitTarget = base + offset;
        }
        break;

    case 2:
        s->event.m_manualFramesLeft += delta;
        if (s->event.m_manualFramesLeft >= s->waitTarget) {
            s->event.setPhase(s->event.getPhase() + 1);
        }
        break;

    case 3:
        s->progress -= rd[0x44 / 4] * delta;
        if (s->progress < rd[0]) {
            s->event.m_manualFramesLeft = rd[0];
            s->progress = rd[0];
            s->event.setPhase(s->event.getPhase() + 1);
            s->waitTarget =
                rd[0x58 / 4] +
                (rd[0x50 / 4] - rd[0x54 / 4] * randf__Fv());
        }
        break;

    case 4:
        s->event.m_manualFramesLeft += delta;
        if (s->event.m_manualFramesLeft >= s->waitTarget) {
            s->event.end();
            s->event.start();
        }
        break;
    }

    s->event.update(delta);
}
}
