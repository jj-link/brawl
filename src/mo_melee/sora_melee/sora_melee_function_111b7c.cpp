#pragma force_active on
struct Obj {
    unsigned char pad[0x4d8];
    unsigned int a;
    unsigned int b;
    unsigned int c;
};

struct Triple {
    unsigned int a;
    unsigned int b;
    unsigned int c;
};

extern "C" {
Triple fn_27_111B7C(Obj **src) {
    Obj *o = *src;
    return *(Triple *)&o->a;
}
}
