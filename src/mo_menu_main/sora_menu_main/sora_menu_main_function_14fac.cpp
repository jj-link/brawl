#include <gf/gf_model.h>
#include <gf/gf_scene.h>
#include <snd/snd_system.h>
#pragma force_active on

struct Class_728_base { char pad[0x3c]; };
class Class_728 : public Class_728_base {
public:
    virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
    virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
    virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11();
    virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15();
    virtual void slot16(); virtual void slot17(); virtual void slot18(); virtual void slot19();
    virtual void slot20(); virtual void slot21(); virtual void slot22(); virtual void slot23();
    virtual void slot24(); virtual void fn_2_36914(); virtual void fn_2_36908(); virtual void fn_2_361C4(int, int);
    virtual void fn_2_35FDC(); virtual void fn_2_36648();
    char pad40[0x128 - 0x40];
    int state;
    char pad12c[0x138 - 0x12c];
    int type;
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
    char pad0[0x42];
    unsigned short selection;
    char pad44[0x634 - 0x44];
    int result;
    char pad638[0x648 - 0x638];
    char* config;
    Object** objects;
    int f650;
    int f654;
    Class_728* view;
    char pad65c[0x664 - 0x65c];
    int mode;
};
struct Menu : MenuBase {
    virtual void slot0(); virtual void slot1(); virtual void slot2();
    virtual void slot3(); virtual void slot4(); virtual void slot5();
    virtual int slot6(unsigned);
    Class_728* child;
    unsigned counter;
};

extern "C" {
extern const float lbl_2_rodata_5A8[];
extern char lbl_2_data_19A0[];
extern char lbl_2_data_19D0[];
float getFrame__16gfModelAnimationFd(gfModelAnimation*);
unsigned fn_18_12E0(Menu*);
void fn_18_1D48(Menu*, int, int);
void fn_18_1AE0(Menu*, int, int);
void fn_18_1F34(Menu*, int);
void fn_800B330C(Object*, void*, int);
int fn_2_12F28(void*, int);
void* fn_2_38530(int, void*, int, int, int, void*, void*);
void* __dynamic_cast(void*, int, const void*, const void*, int);
void* getInstance__14gfSceneManagerFv();
}

extern "C" int fn_2_14FAC(Menu* self) {
    unsigned short sel3;
    int r28;
    unsigned flags = 0;

    if (self->child != 0) {
        r28 = 0;
        if (self->child->type == 0xc) {
            switch (self->child->state) {
            case 0:
                fn_18_1F34(self, 1);
                self->result = 3;
                self->mode = 4;
                r28 = 2;
                break;
            case 1:
            case 3:
                break;
            }
            self->child->slot23();
            self->child = 0;
            if (r28 != 0) {
                return r28;
            }
        }
    } else {
        flags = fn_18_12E0(self);
    }

    switch (self->mode) {
    case 0: {
        if (9.0f == getFrame__16gfModelAnimationFd(self->objects[self->selection]->anim)) {
            fn_800B330C(self->objects[self->selection], self->config + 0x3c, 1);
            self->mode = 1;
        }
        break;
    }
    case 1:
        self->counter++;
        if ((float)self->counter >= 25.0f) {
            self->mode = 3;
        }
        break;
    case 2: {
        Object* o = self->objects[self->selection];
        unsigned type;
        if (o->a) type = o->a->value;
        else if (o->b) type = o->b->value;
        else type = -1;
        if (type == 2 && 9.0f == getFrame__16gfModelAnimationFd(o->anim)) {
            fn_800B330C(self->objects[self->selection], self->config + 0x28, 1);
            self->mode = 3;
        }
        unsigned short sel = self->selection;
        if (self->slot6(flags)) {
            fn_18_1D48(self, sel, 1);
            self->view->fn_2_361C4(self->selection + 1, self->selection);
            self->mode = 3;
            return 4;
        }
        if (flags & 0x10) {
            if (self->selection == 2) {
                g_sndSystem->playSE((SndID)1, -1, 0, 0, -1);
                flags = (unsigned)__dynamic_cast(gfSceneManager::getInstance()->m_currentScene, 4, lbl_2_data_19A0, lbl_2_data_19D0, 0);
                self->child = (Class_728*)fn_2_38530(0, (char*)flags + 0xa94, fn_2_12F28((void*)flags, 9), self->f654, 0x29, (char*)flags + 0xa98, (char*)flags + 0xa9c);
                break;
            }
            self->view->fn_2_36648();
            fn_18_1F34(self, 1);
            self->mode = 4;
            self->result = self->selection + 1;
            return 2;
        }
        if (flags & 0x20) {
            fn_18_1AE0(self, 0, 0);
            g_sndSystem->playSE((SndID)2, -1, 0, 0, -1);
        }
        break;
    }
    case 3: {
        Object* o = self->objects[self->selection];
        unsigned type;
        if (o->a) type = o->a->value;
        else if (o->b) type = o->b->value;
        else type = -1;
        if (type == 4 && getFrame__16gfModelAnimationFd(o->anim) >= 179.0f) {
            fn_800B330C(self->objects[self->selection], self->config + 0x28, 1);
        }
        sel3 = self->selection;
        if (self->slot6(flags)) {
            fn_18_1D48(self, sel3, 0);
            self->view->fn_2_361C4(self->selection + 1, self->selection);
            return 0;
        }
        if (flags & 0x10) {
            if (self->selection == 2) {
                g_sndSystem->playSE((SndID)1, -1, 0, 0, -1);
                flags = (unsigned)__dynamic_cast(gfSceneManager::getInstance()->m_currentScene, 4, lbl_2_data_19A0, lbl_2_data_19D0, 0);
                self->child = (Class_728*)fn_2_38530(0, (char*)flags + 0xa94, fn_2_12F28((void*)flags, 9), self->f654, 0x29, (char*)flags + 0xa98, (char*)flags + 0xa9c);
                break;
            }
            fn_18_1F34(self, 1);
            self->mode = 4;
            self->result = self->selection + 1;
            return 2;
        }
        if (flags & 0x20) {
            fn_18_1AE0(self, 0, 0);
            g_sndSystem->playSE((SndID)2, -1, 0, 0, -1);
        }
        break;
    }
    case 4: {
        Object* o = self->objects[self->selection];
        if (0.0f == o->anim->getUpdateRate()) {
            return 3;
        }
        break;
    }
    }
    return 0;
}
