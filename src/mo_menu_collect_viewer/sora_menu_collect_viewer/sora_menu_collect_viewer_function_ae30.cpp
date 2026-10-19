#pragma force_active on
struct Viewer {
    unsigned char padding[0x128];
    union {
        int state;
        unsigned int stateIndex;
    };
    int previousState;
};

typedef int (*StateFunction)(Viewer*);

extern "C" {
void fn_800B9984(void*);
extern StateFunction lbl_6_rodata_768[14][2];

void fn_6_AE30(Viewer* self) {
    fn_800B9984((unsigned char*)self + 0x80);

    if (self->previousState != self->state) {
        StateFunction enter = lbl_6_rodata_768[self->stateIndex][0];
        if (enter) {
            enter(self);
        }
        self->previousState = self->state;
    }

    StateFunction update = lbl_6_rodata_768[self->stateIndex][1];
    if (update) {
        self->state = update(self);
    }
}
}
