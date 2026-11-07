#include <gf/gf_model.h>
#pragma force_active on

struct AnimInfoA { char pad[0x10]; int value; };
struct AnimInfoB { char pad[0xc]; int value; };
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
    char pad638[0x64c - 0x638];
    Object** objects;
    char pad650[0x664 - 0x650];
    unsigned mode;
};
struct Menu : MenuBase {
    virtual void slot0(); virtual void slot1(); virtual void slot2();
    virtual void slot3(); virtual void slot4(); virtual void slot5();
    virtual int slot6(unsigned);
    char pad66c[0x690 - 0x66c];
    unsigned short row;
};
extern "C" {
extern const float lbl_2_rodata_660[];
extern char lbl_2_data_2328[];
float getFrame__16gfModelAnimationFd(gfModelAnimation*);
unsigned fn_18_12E0(Menu*);
void fn_18_17B0(Menu*, int, int, float);
void fn_2_19BCC(Menu*, int);
void fn_800B330C(Object*, void*, int);
}

extern "C" int fn_2_19014(Menu* self) {
    const float* ro = lbl_2_rodata_660;
    if (self->mode == 2) {
        if (ro[3] == self->objects[self->selection + 0x2a]->anim->getUpdateRate())
            return 3;
        return 0;
    }
    Object* obj = self->objects[self->selection + 0x2a];
    int type;
    if (obj->a) type = obj->a->value;
    else if (obj->b) type = obj->b->value;
    else type = -1;
    switch (type) {
    case 4:
        if (ro[4] == getFrame__16gfModelAnimationFd(obj->anim))
            fn_800B330C(self->objects[self->selection + 0x2a], lbl_2_data_2328 + 0x28, 1);
        break;
    case 2:
        if (ro[5] == getFrame__16gfModelAnimationFd(obj->anim))
            fn_800B330C(self->objects[self->selection + 0x2a], lbl_2_data_2328 + 0x3c, 1);
        break;
    }
    for (int i = 0; i < 8; i++)
        fn_2_19BCC(self, i);
    unsigned flags = fn_18_12E0(self);
    int r = self->slot6(flags);
    if (flags & 0x20) {
        fn_800B330C(self->objects[0x2a], lbl_2_data_2328 + 0x64, 1);
        fn_800B330C(self->objects[0x2b], lbl_2_data_2328 + 0x64, 1);
        fn_18_17B0(self, self->row + 0x44, 0x10, ro[3]);
        self->result = 5;
        self->mode = 2;
        return 1;
    }
    if (r && (int)self->mode == 0) {
        self->mode = 1;
        return 4;
    }
    return 0;
}
