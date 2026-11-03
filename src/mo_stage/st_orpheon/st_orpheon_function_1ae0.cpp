#include <gr/gr_tengan_event.h>
#include <nw4r/math/math_arithmetic.h>
#include <nw4r/ut/ut_algorithm.h>

#pragma force_active on

struct StOrpheon {
    char pad[0x1D8];
    grTenganEvent event;
    grTenganEvent eventA;
    grTenganEvent eventB;
    char pad2[0x6C6 - 0x3DC];
    u8 counter;
    u8 lastChoice;
};

extern "C" {
extern const float lbl_55_rodata_0[];
float randf__Fv();

void fn_55_1AE0(StOrpheon* self, float dt) {
    const float* rd = lbl_55_rodata_0;

    switch (self->event.getPhase()) {
    case 0:
        if (self->event.isReadyEnd() && !self->eventA.isEvent() &&
            !self->eventB.isEvent()) {
            int choice = 0;
            if (nw4r::ut::Abs(rd[16] - rd[23] * randf__Fv()) < rd[24]) {
                choice = 1;
            }

            if (choice == (int)self->lastChoice) {
                self->counter = self->counter + 1;
                if ((signed char)self->counter >= 2) {
                    choice = !choice;
                    self->counter = 0;
                }
            } else {
                self->counter = 0;
            }

            self->lastChoice = choice;

            if (choice) {
                self->eventA.start();
            } else {
                self->eventB.start();
            }

            self->event.end();
            self->event.start();
        }
        break;
    }

    self->event.update(dt);
}
}
