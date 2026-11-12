#pragma force_active on

extern "C" void fn_56_46BC(void* self);
extern "C" void fn_56_4780(void* self);
extern "C" double cos(double);
extern "C" const float lbl_56_rodata_80[16];

struct CrayonObj {
    char pad0[8];
    float f8;
    float fC;
    char pad1[8];
    float f18;
};

struct CrayonHolder {
    char pad[4];
    CrayonObj* obj;
};

struct Crayon {
    char pad0[0x170];
    float f170;
    float f174;
    float f178;
    float f17C;
    float f180;
    int state;
    char pad1[4];
    float f18C;
};

extern "C" void fn_56_3B94(Crayon* self, float farg0) {
    const float* lbl = lbl_56_rodata_80;
    CrayonHolder* h = (CrayonHolder*)((char*)self + 0xD0);
    float f31;
    float t;
    float c;

    if (h == 0) {
        return;
    }
    f31 = lbl[12];
    self->f180 = lbl[13];
    switch (self->state) {
    case 0:
        fn_56_46BC(self);
        h->obj->f8 = self->f170;
        h->obj->fC = self->f174;
        if (self->f178 >= lbl[0]) {
            h->obj->f18 = lbl[0];
        }
        if (self->f178 < lbl[0]) {
            h->obj->f18 = lbl[14];
        }
        self->state = 1;
        self->f18C = lbl[0];
        return;
    case 1:
        t = self->f178 * farg0;
        h->obj->f8 = h->obj->f8 + t;
        c = (float)cos((lbl[10] * self->f18C) / f31);
        h->obj->fC = h->obj->fC - farg0 * (self->f17C * c);
        if (self->f18C >= f31 * lbl[15]) {
            self->state = 2;
            self->f18C = lbl[0];
            return;
        }
        break;
    case 2:
        if (self->f18C >= lbl[13]) {
            self->state = 3;
            self->f18C = f31 * lbl[15];
        }
        break;
    case 3:
        t = self->f178 * farg0;
        h->obj->f8 = h->obj->f8 + t;
        c = (float)cos((lbl[10] * self->f18C) / f31);
        h->obj->fC = h->obj->fC - farg0 * (self->f17C * c);
        if (self->f18C >= f31 * lbl[9]) {
            fn_56_4780(self);
        }
        break;
    }
}
