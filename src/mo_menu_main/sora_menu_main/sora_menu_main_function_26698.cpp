#include <gf/gf_pad_system.h>
#include <mu/mu_object.h>
#pragma force_active on

struct Child {
    char pad[0x668];
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual int v2c(); virtual void v30(); virtual void v34();
    virtual void v38(); virtual void v3c(); virtual void v40();
};
struct VIface {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual float getVal();
};
struct Node { char pad[0xc]; VIface* iface; };
struct Mu { char pad[0x14]; Node* node; };
struct Objects { char pad[0x1bc]; Mu* m1bc; char pad2[0x68]; MuObject* m228; MuObject* m22c; };
struct Menu {
    char pad[0x634]; int s634; char pad1[0x14]; Objects* o64c;
    char pad2[0x14]; int s664; char pad3[8]; int s670; int s674;
    char pad4[8]; Child* children[4];
};
extern "C" {
unsigned fn_18_12E0(Menu*);
int fn_18_1A58(Menu*);
void fn_2_26A38(Menu*, int);
void fn_2_26DC4(Menu*, int);
void fn_2_26F4C(Menu*);
void fn_2_26BE4(Menu*);
extern const float lbl_2_rodata_DDC;
extern const float lbl_2_rodata_DE0;
extern const unsigned char lbl_2_rodata_DE4[];
}
extern "C" int fn_2_26698(Menu* self) {
    int result = 0;
    switch (self->s664) {
    case 0:
        if (self->s674 != 1) self->s664 = 2;
        break;
    case 1:
        if (self->s674 != 1) self->s664 = 2;
        break;
    case 2: {
        unsigned flags = fn_18_12E0(self);
        int condition;
        if (self->s670 <= 0 && (flags & 0x20)) condition = 0;
        else condition = 1;
        if (condition == 0) {
            fn_2_26A38(self, 3);
            fn_2_26DC4(self, 3);
            self->s664 = 3;
            for (int i = 0; i < 4; i++) {
                Child* child = self->children[i];
                child->v40();
            }
            self->s634 = 0x10;
            result = 1;
        } else {
            fn_2_26F4C(self);
            Child* child = self->children[self->s670];
            if (child->v2c() == 0) {
                child = self->children[self->s670];
                child->v30();
            }
        }
        break;
    }
    case 3:
        if (self->s674 == 0) result = 3;
        break;
    }
    switch (self->s674) {
    case 0: break;
    case 1:
        if (self->o64c->m1bc->node->iface->getVal() >= lbl_2_rodata_DDC)
            fn_2_26A38(self, 2);
        break;
    case 2: {
        gfPadStatus status;
        g_gfPadSystem->getSysPadStatus(fn_18_1A58(self), &status);
        float frame = lbl_2_rodata_DE4[status.m_controllerType];
        self->o64c->m228->setFrameTex(frame);
        self->o64c->m22c->setFrameTex(frame);
        break;
    }
    case 3:
        if (self->o64c->m1bc->node->iface->getVal() >= lbl_2_rodata_DE0)
            fn_2_26A38(self, 0);
        break;
    }
    fn_2_26BE4(self);
    for (int i = 0; i < 4; i++) {
        Child* child = self->children[i];
        child->v38();
    }
    return result;
}