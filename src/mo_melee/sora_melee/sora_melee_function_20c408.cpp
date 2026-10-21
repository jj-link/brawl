#pragma force_active on

typedef unsigned char u8;
typedef unsigned int u32;

struct Environment {
    u8 pad[0x40];
    u32 flags;
};

struct Fighter {
    u8 pad0[0x54];
    u32 flags;
    u8 pad58[0xBC - 0x58];
    Environment* environment;
    u8 state;
    u8 padC1[7];
    int index;
    u8 padCC[0x1BA - 0xCC];
    u8 mode;
};

extern "C" int fn_27_1F2E20(Environment*, int);
extern "C" int fn_27_1F2A3C(void*, int, int);

inline int environmentCheck(Environment* env, int index) {
    int found = 0;
    if ((env->flags & 0x1000) || fn_27_1F2E20(env, index) != 0)
        found = 1;
    return found;
}

extern "C" int fn_27_20C408(Fighter* self) {
    if (self->state == 0) {
        if (environmentCheck(self->environment, self->index))
            return 1;
    }

    bool a;
    if (self->mode == 1)
        a = true;
    else
        a = (self->flags & 0x99) == 0x99;

    if (a || (self->mode == 2 ? true : (self->flags & 0x6400) == 0x6400)) {
        if (fn_27_1F2E20(self->environment, self->index) != 0 &&
            fn_27_1F2A3C((u8*)self + 0x74, self->index, 0) != 0)
            return 1;
    }

    return 0;
}
