#pragma force_active on
extern "C" {
struct Menu {
    char pad[0x138];
    int state;
    int previous;
};

struct StateEntry {
    void (*enter)(Menu*);
    int (*update)(Menu*);
};

extern const StateEntry lbl_2_rodata_1698[];
void fn_800B9984(void*);

void fn_2_38C78(Menu* self) {
    fn_800B9984((char*)self + 0x78);
    if (self->previous != self->state) {
        if (lbl_2_rodata_1698[self->state].enter)
            lbl_2_rodata_1698[self->state].enter(self);
        self->previous = self->state;
    }
    if (lbl_2_rodata_1698[self->state].update)
        self->state = lbl_2_rodata_1698[self->state].update(self);
}
}
