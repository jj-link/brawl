#pragma force_active on

struct Entry {
    void (*f0)(void*);
    int (*f4)(void*);
};

extern Entry lbl_804090F0[];

struct Self {
    char pad[8];
    int state;
};

extern "C" void fn_800FD8E0(Self* self) {
    int old = self->state;
    if (lbl_804090F0[old].f4 != 0) {
        self->state = lbl_804090F0[old].f4(self);
    }
    if (self->state != old) {
        if (lbl_804090F0[self->state].f0 != 0) {
            lbl_804090F0[self->state].f0(self);
        }
    }
}
