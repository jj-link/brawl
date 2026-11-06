#pragma force_active on
#include <gr/gr_gimmick_spring.h>

class PictchatSpring : public grGimmickSpring {
public:
    u8 state;
    char pad19D[7];
    u8* selection;
    u8 id;
    char pad1A9[7];
    u8* event;
    u8* ready;
    char pad1B8;
    u8 flag;
};

extern "C" void fn_27_2704CC(void*);

extern "C" void fn_73_D964(PictchatSpring* self) {
    switch (self->state) {
    case 0:
        self->setVisibility(0);
        self->flag = 1;
        self->state = 1;
        break;
    case 1:
        if (*self->selection == self->id && *self->ready == 1) {
            self->setVisibility(1);
            self->enableArea();
            self->state = 2;
        }
        break;
    case 2:
        if (*self->selection != self->id && *self->event == 5) {
            self->state = 0;
            break;
        }
        if (*self->event == 2) {
            fn_27_2704CC(self);
            *self->event = 3;
        } else {
            self->presentPosEvent();
        }
        break;
    }
}
