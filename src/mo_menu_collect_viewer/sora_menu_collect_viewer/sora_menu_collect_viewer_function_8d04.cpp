#pragma force_active on

extern "C" {

typedef int (*StateFunc)(void*);

struct StateTable {
    void (*enter)(void*);
    StateFunc update;
};

extern StateTable lbl_6_rodata_610[];
void fn_800B9984(void*);

struct Viewer {
    char pad[0x124];
    union {
        int state;
        unsigned int stateIndex;
    };
    int previousState;
    char pad2[0x60C];
    int fieldA;
    int fieldB;
    char pad3[0x34];
    unsigned char initialized;
    char pad4[7];
    int fieldA2;
    int fieldB2;
};

void fn_6_8D04(Viewer* self) {
    if (self->initialized == 0) {
        if (self->fieldA != 0) {
            self->fieldA2 = self->fieldA;
            self->fieldB2 = self->fieldB;
            self->initialized = 1;
            self->state = 0xd;
        }
    }

    fn_800B9984((char*)self + 0x7C);

    if (self->previousState != self->state) {
        StateFunc enter = (StateFunc)lbl_6_rodata_610[self->stateIndex].enter;
        if (enter)
            enter(self);
        self->previousState = self->state;
    }

    StateFunc update = lbl_6_rodata_610[self->stateIndex].update;
    if (update)
        self->state = update(self);
}

}
