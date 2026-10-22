#pragma force_active on
extern "C" {

typedef void (*fn_enter_t)(void*);
typedef int (*fn_update_t)(void*);

struct StateEntry {
    fn_enter_t enter;
    fn_update_t update;
};

extern StateEntry lbl_80407C08[];
extern void fn_800B9984(void*);

struct MyMenu {
    unsigned char pad[0x104];
    int state;   // 0x104
    int last;    // 0x108
};

void fn_800BF78C(MyMenu* self) {
    fn_800B9984((char*)self + 0x54);
    if (self->last != self->state) {
        fn_enter_t enter = lbl_80407C08[self->state].enter;
        if (enter) {
            enter(self);
        }
        self->last = self->state;
    }
    fn_update_t update = lbl_80407C08[self->state].update;
    if (update) {
        self->state = update(self);
    }
}
}
