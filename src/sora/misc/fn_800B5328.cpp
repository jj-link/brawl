#pragma force_active on

struct Leaf {
    char pad[0x1C];
    unsigned short h;
};

struct Inner {
    char pad[0x2C];
    Leaf *p;
};

struct Mid {
    char pad[0xC];
    Inner *p;
};

struct Outer {
    char pad[0x14];
    Mid *m;
};

extern "C" unsigned short fn_800B5328(Outer *arg0) {
    Inner *t = arg0->m->p;
    if (t == 0) {
        return 0;
    }
    return t->p->h;
}
