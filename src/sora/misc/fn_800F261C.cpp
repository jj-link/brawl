#pragma force_active on

struct Target {
    unsigned char pad[0x350];
    int state;
};

struct Object {
    unsigned char pad0[0xAC];
    Target* target;
    unsigned char enabled;
    unsigned char padB1[3];
    int timer;
    int state;
    unsigned char padBC[0x1D];
    unsigned char started;
};

extern "C" void fn_800C6E3C(Target*, int, int);
extern "C" void fn_800C6E64(Target*, int, int, int);
extern "C" void fn_800F218C(Object*);

extern "C" void fn_800F261C(Object* self) {
    switch (self->state) {
    case 0:
        if (self->enabled != 0) {
            Target* target = self->target;
            if (target->state == 0) {
                if (self->started == 0) {
                    fn_800C6E3C(target, 0, 0);
                    self->started = 1;
                } else {
                    fn_800C6E64(target, 1, 0, 0);
                }
                self->state = 1;
            }
        }
        break;
    case 1:
        if (self->target->state == 0) {
            fn_800F218C(self);
            self->timer = 60;
            self->state = 2;
        }
        break;
    case 2:
        if (--self->timer <= 0) {
            self->state = 0;
        }
        break;
    }
}
