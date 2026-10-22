#pragma force_active on
class gfTask;
extern "C" void exit__6gfTaskFv(gfTask* task);

struct Self {
    char pad0[0x50];
    int f50;
    char pad1[0x5C - 0x54];
    gfTask* f5C;
};

struct gfTask {
    char pad0[0x100];
    unsigned char f100;
    char pad1[0x104 - 0x101];
    int f104;
};

extern "C" int fn_800DB2D0(Self* self) {
    int state;
    gfTask* t;

    t = self->f5C;
    if (t == 0) {
        state = 0;
    } else if (t->f104 != 3) {
        state = 1;
    } else {
        state = 3;
        if (t->f100 != 0) {
            state = 2;
        }
    }

    if (state != 1) {
        if (t != 0) {
            exit__6gfTaskFv(t);
            self->f5C = 0;
        }
        return 5;
    }
    return self->f50;
}
