#pragma force_active on

extern "C" int fn_8014DD34(void*, int);
extern "C" int fn_8039A350(int);
extern "C" int fn_8039A52C();

struct Anim {
    virtual void vf0(int, int, int);
};

struct Unk {
    char pad[8];
    Anim* m_anim;
};

extern "C" int fn_8014D108(Unk* a, int b) {
    if (fn_8014DD34(a, 1) == 0) {
        return 0;
    }
    int r = 0;
    int c = fn_8039A350(b);
    switch (c) {
    case 0:
        r = 1;
        break;
    case -39: {
        int v = fn_8039A52C();
        Anim* o = a->m_anim;
        if (o != 0) {
            int av = v;
            if (v < 0) av = -v;
            o->vf0(5, c, av);
        }
        break;
    }
    case -31: {
        int v = fn_8039A52C();
        Anim* o = a->m_anim;
        if (o != 0) {
            int av = v;
            if (v < 0) av = -v;
            o->vf0(6, c, av);
        }
        break;
    }
    case -32: {
        int v = fn_8039A52C();
        Anim* o = a->m_anim;
        if (o != 0) {
            int av = v;
            if (v < 0) av = -v;
            o->vf0(7, c, av);
        }
        break;
    }
    case -6: {
        int v = fn_8039A52C();
        Anim* o = a->m_anim;
        if (o != 0) {
            int av = v;
            if (v < 0) av = -v;
            o->vf0(8, c, av);
        }
        break;
    }
    default: {
        int v = fn_8039A52C();
        Anim* o = a->m_anim;
        if (o != 0) {
            int av = v;
            if (v < 0) av = -v;
            o->vf0(3, c, av);
        }
        break;
    }
    }
    return r;
}
