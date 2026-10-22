#pragma force_active on
struct Menu {
    unsigned char padding[0x50];
    union {
        int state;
        unsigned int stateIndex;
    };
    int previousState;
};

typedef void (*EnterFn)(Menu*);
typedef int (*UpdateFn)(Menu*);
struct StateEntry {
    EnterFn enter;
    UpdateFn update;
};

extern "C" {
extern const StateEntry lbl_80408550[];

void fn_800DAC20(Menu* self) {
    if (self->previousState != self->state) {
        if (lbl_80408550[self->stateIndex].enter)
            lbl_80408550[self->stateIndex].enter(self);
        self->previousState = self->state;
    }
    if (lbl_80408550[self->stateIndex].update)
        self->state = lbl_80408550[self->stateIndex].update(self);
}
}
