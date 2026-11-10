#pragma force_active on
#include <types.h>

struct Node16 {
    char pad[0x10];
    void* value;
};

struct Models {
    char pad[0x30];
    Node16* objects[6];
};

struct SceneBase {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void attach(void*, void*);
};

struct Scene : SceneBase {
    char pad4[0xE0];
    void* root;
};

struct Class_728_base { char pad[0x3C]; };
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
    virtual void slot23();
    virtual void slot24();
    virtual void fn_2_36914();
    virtual void fn_2_36908();
    virtual void fn_2_361C4(int, int);
};

struct Menu {
    char pad0[0x42];
    u16 target;
    char pad44[0x638 - 0x44];
    int state;
    u16* data;
    int field640;
    int count;
    int field648;
    Models* models;
    int field650;
    Scene* scene;
    Class_728* control;
    int field65C;
    int field660;
    int mode;
};

extern "C" {
extern u16 lbl_2_data_19D8[];
extern const f32 lbl_2_rodata_520[6];
extern void* g_GameGlobal;

u32 fn_8004E7C8(void*);
void fn_800B6838(void*, const f32*);
void fn_18_1C4C(Menu*, int);
int fn_18_1A9C(Menu*);
void fn_18_1D48(Menu*, int, int);

void fn_2_130A0(Menu* self, Scene* scene, int arg) {
    const f32* rod = lbl_2_rodata_520;
    s16 sel;
    int off;
    u32 i;

    self->data = lbl_2_data_19D8;
    self->scene = scene;
    self->count = 12;
    i = 0;
    off = 0;

    do {
        if (fn_8004E7C8(g_GameGlobal) != 0 || 2 != i) {
            scene->attach(scene->root,
                ((Node16*)*(void**)((char*)self->models + off + 0x30))->value);
        }
        off = off + ((4));
        i++;
    } while (i < 6);

    if (fn_8004E7C8(g_GameGlobal) == 1) {
        f32 pos[3];
        pos[0] = rod[0];
        pos[1] = rod[0];
        pos[2] = rod[0];
        fn_800B6838(self->models->objects[0], pos);
        lbl_2_data_19D8[2] = 2;
        lbl_2_data_19D8[24] = 2;
    }

    if (fn_8004E7C8(g_GameGlobal) == 0) {
        f32 pos[3];
        pos[0] = rod[1];
        pos[1] = rod[2];
        pos[2] = rod[0];
        fn_800B6838(self->models->objects[0], pos);
        *(2 + lbl_2_data_19D8) = 3;
        lbl_2_data_19D8[24] = 0;
    }

    switch (arg) {
    case 0:
        self->mode = 0;
        self->target = 1;
        self->state = 0;
        fn_18_1C4C(self, 1);
        break;
    case 0x19:
        self->mode = 1;
        self->target = 4;
        self->state = 0x19;
        fn_18_1C4C(self, 1);
        break;
    default:
        self->mode = 2;
        switch (fn_18_1A9C(self)) {
        case 4:
            sel = 0;
            break;
        case 5:
            sel = 1;
            break;
        case 6:
            sel = 2;
            break;
        case 8:
            sel = 3;
            break;
        case 12:
            sel = 5;
            break;
        }
        self->target = sel;
        fn_18_1D48(self, sel, 1);
        self->state = 0x22;
        break;
    }

    self->control->fn_2_361C4(8, self->target + 12);
}
}
