#pragma force_active on
struct ObjA {
    unsigned char pad[0x6A9];
    unsigned char f;
};

struct ObjB {
    unsigned char pad[0x69B];
    unsigned char f;
};

struct ObjC {
    unsigned char pad[0x688];
    unsigned char f;
};

struct ObjD {
    unsigned char pad[0x761];
    unsigned char f;
};

struct S {
    unsigned char pad[0x268];
    ObjA* o1;
    ObjB* o2;
    ObjC* o3;
    ObjD* o4;
    unsigned char pad2[0x20];
    unsigned char f;
};

extern "C" void fn_18_1098(S* self, bool value) {
    self->f = value;
    if (self->o1) self->o1->f = value;
    if (self->o2) self->o2->f = value;
    if (self->o3) self->o3->f = value;
    if (self->o4) self->o4->f = value;
}
