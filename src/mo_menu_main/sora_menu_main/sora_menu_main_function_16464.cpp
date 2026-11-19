#include <gf/gf_model.h>
#include <gf/gf_scene.h>

#pragma force_active on

struct Class_728_base { char pad[0x3c]; };

class Class_728 : public Class_728_base {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23(int, int, int);
};

class Dialog : public Class_728_base {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();

    int type;
    char pad44[0x128 - 0x44];
    int response;
    char pad12c[0x138 - 0x12c];
    int state;
};

struct AnimInfoA { char pad[0x10]; unsigned int value; };
struct AnimInfoB { char pad[0x0c]; unsigned int value; };

struct AnimEntry {
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
    AnimEntry** objects;
    char pad650[4];
    void* resource;
    Class_728* view;
    char pad65c[8];
    int mode;
};

struct Menu : MenuBase {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual int slot6(int);

    Dialog* dialog;
};

extern "C" {
extern const float lbl_2_rodata_5D0[];
extern char lbl_2_data_19A0[];
extern char lbl_2_data_19D0[];
unsigned int fn_18_12E0(Menu*);
void fn_18_1F34(Menu*, int);
void fn_18_1D48(Menu*, int, int);
void* fn_2_12F28(void*, int);
void* fn_2_38530(int, void*, void*, void*, int, int, int);
void fn_800B330C(AnimEntry*, void*, int);
void* __dynamic_cast(void*, int, void*, void*, int);
float getFrame__16gfModelAnimationFd(gfModelAnimation*);
}

extern "C" int fn_2_16464(Menu* self) {
    int idx;
    const float* c = lbl_2_rodata_5D0;
    unsigned int flags = 0;
    Dialog* dialog = self->dialog;
    if (dialog) {
        int result = 0;
        if (dialog->state == 12) {
            if (dialog->type == 1) {
                if (dialog->response != 3) {
                    fn_18_1F34(self, 0);
                    self->result = 0;
                    result = 1;
                    self->mode = 3;
                }
            } else {
                switch (dialog->response) {
                case 1:
                case 3:
                    break;
                case 0:
                    fn_18_1F34(self, 1);
                    if (self->selection == 0) self->result = 0x1a;
                    else self->result = 0x1b;
                    result = 2;
                    self->mode = 3;
                    break;
                }
            }
            self->dialog->slot23();
            self->dialog = 0;
            if (result) return result;
        }
    } else {
        flags = fn_18_12E0(self);
    }

    switch (self->mode) {
    case 0: {
        unsigned short idx;
        AnimEntry* e = self->objects[self->selection + 0x12];
        unsigned int kind;
        if (e->a) kind = e->a->value;
        else if (e->b) kind = e->b->value;
        else kind = -1;
        if (kind == 2 && c[2] == getFrame__16gfModelAnimationFd(e->anim)) {
            fn_800B330C(self->objects[self->selection + 0x12], self->config + 0x3c, 1);
            self->mode = 2;
        }
        idx = self->selection;
        if (self->slot6(flags)) {
            self->view->slot23(self->selection + 0x12, 1, 0);
            fn_18_1D48(self, idx, 1);
            self->mode = 2;
            return 4;
        }
        if (flags & 0x10) {
            switch (self->selection) {
            case 0: self->result = 0x1a; break;
            case 1: self->result = 0x1b; break;
            case 2: self->result = 0x1c; break;
            }
            fn_18_1F34(self, 1);
            self->mode = 3;
            return 2;
        }
        if (flags & 0x20) {
            flags = (unsigned int)__dynamic_cast(
                gfSceneManager::getInstance()->m_currentScene, 4,
                lbl_2_data_19A0, lbl_2_data_19D0, 0);
            self->dialog = (Dialog*)fn_2_38530(
                1, (char*)flags + 0xa94, fn_2_12F28((void*)flags, 9),
                self->resource, 0x29, 0, 0);
        }
        break;
    }
    case 1: {
        AnimEntry* e = self->objects[self->selection + 0x12];
        if (c[2] == getFrame__16gfModelAnimationFd(e->anim)) {
            fn_800B330C(self->objects[self->selection + 0x12], self->config + 0x28, 1);
            self->mode = 2;
        }
        break;
    }
    case 2: {
        AnimEntry* e = self->objects[self->selection + 0x12];
        unsigned int kind;
        if (e->a) kind = e->a->value;
        else if (e->b) kind = e->b->value;
        else kind = -1;
        if (kind == 4 && getFrame__16gfModelAnimationFd(e->anim) >= c[3]) {
            fn_800B330C(self->objects[self->selection + 0x12], self->config + 0x28, 1);
        }
        idx = self->selection;
        if (self->slot6(flags)) {
            self->view->slot23(self->selection + 0x12, 1, 0);
            fn_18_1D48(self, idx, 0);
        }
        if (flags & 0x10) {
            switch (self->selection) {
            case 0: self->result = 0x1a; break;
            case 1: self->result = 0x1b; break;
            case 2: self->result = 0x1c; break;
            }
            fn_18_1F34(self, 1);
            self->mode = 3;
            return 2;
        }
        if (flags & 0x20) {
            flags = (unsigned int)__dynamic_cast(
                gfSceneManager::getInstance()->m_currentScene, 4,
                lbl_2_data_19A0, lbl_2_data_19D0, 0);
            self->dialog = (Dialog*)fn_2_38530(
                1, (char*)flags + 0xa94, fn_2_12F28((void*)flags, 9),
                self->resource, 0x29, 0, 0);
        }
        break;
    }
    case 3: {
        AnimEntry* e = self->objects[self->selection + 0x12];
        if (c[0] == e->anim->getUpdateRate()) return 3;
        break;
    }
    }
    return 0;
}