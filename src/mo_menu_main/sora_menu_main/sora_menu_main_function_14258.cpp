#include <gf/gf_model.h>
#pragma force_active on

struct Class_728_base { char pad[0x3c]; };
class Class_728 : public Class_728_base {
public:
    virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
    virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
    virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11();
    virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15();
    virtual void slot16(); virtual void slot17(); virtual void slot18(); virtual void slot19();
    virtual void slot20(); virtual void slot21(); virtual void slot22();
    virtual void slot23(int, int, int);
};
struct AnimInfoA { char pad[0x10]; unsigned value; };
struct AnimInfoB { char pad[0xc]; unsigned value; };
struct Object {
    char pad[0x14];
    gfModelAnimation* anim;
    AnimInfoA* a;
    AnimInfoB* b;
};
struct MenuBase {
    char pad[0x42];
    unsigned short selection;
    char pad44[0x634 - 0x44];
    int result;
    char pad638[0x648 - 0x638];
    char* config;
    Object** objects;
    char pad650[8];
    Class_728* view;
    char pad65c[8];
    int mode;
};
struct Menu : MenuBase {
    virtual void slot0(); virtual void slot1(); virtual void slot2();
    virtual void slot3(); virtual void slot4(); virtual void slot5();
    virtual int slot6(unsigned);
};
extern "C" {
extern const float lbl_2_rodata_548[];
float getFrame__16gfModelAnimationFd(gfModelAnimation*);
unsigned fn_18_12E0(Menu*);
void fn_18_1D48(Menu*, int, int);
void fn_18_1F34(Menu*, int);
void fn_800B330C(Object*, void*, int);
}
extern "C" int fn_2_14258(Menu* self) {
    const float* ro = lbl_2_rodata_548;
    switch (self->mode) {
    case 0: {
        Object* obj = self->objects[self->selection + 0x24];
        unsigned type;
        if (obj->a) type = obj->a->value;
        else if (obj->b) type = obj->b->value;
        else type = -1;
        if (type == 2 && ro[0] == getFrame__16gfModelAnimationFd(obj->anim)) {
            fn_800B330C(self->objects[self->selection + 0x24], self->config + 0x3c, 1);
            self->mode = 2;
        }
        unsigned short sel;
        unsigned flags = fn_18_12E0(self);
        sel = self->selection;
        if (self->slot6(flags)) {
            fn_18_1D48(self, sel, 1);
            self->view->slot23(self->selection + 0x25, 1, 0);
            self->mode = 2;
            return 4;
        }
        if (flags & 0x10) {
            self->result = self->selection + 0xe;
            fn_18_1F34(self, 1);
            self->mode = 3;
            return 2;
        }
        if (flags & 0x20) {
            fn_18_1F34(self, 0);
            self->result = 0;
            self->mode = 3;
            return 1;
        }
        break;
    }
    case 1:
        if (ro[0] == getFrame__16gfModelAnimationFd(self->objects[self->selection + 0x24]->anim)) {
            fn_800B330C(self->objects[self->selection + 0x24], self->config + 0x28, 1);
            self->mode = 2;
        }
        break;
    case 2: {
        Object* obj = self->objects[self->selection + 0x24];
        unsigned type;
        if (obj->a) type = obj->a->value;
        else if (obj->b) type = obj->b->value;
        else type = -1;
        if (type == 4 && getFrame__16gfModelAnimationFd(obj->anim) >= ro[1]) {
            fn_800B330C(self->objects[self->selection + 0x24], self->config + 0x28, 1);
        }
        unsigned short sel;
        unsigned flags = fn_18_12E0(self);
        sel = self->selection;
        if (self->slot6(flags)) {
            self->view->slot23(self->selection + 0x25, 1, 0);
            fn_18_1D48(self, sel, 0);
            return 0;
        }
        if (flags & 0x10) {
            self->result = self->selection + 0xe;
            fn_18_1F34(self, 1);
            self->mode = 3;
            return 2;
        }
        if (flags & 0x20) {
            fn_18_1F34(self, 0);
            self->result = 0;
            self->mode = 3;
            return 1;
        }
        break;
    }
    case 3:
        if (ro[2] == self->objects[self->selection + 0x25]->anim->getUpdateRate())
            return 3;
        break;
    }
    return 0;
}
