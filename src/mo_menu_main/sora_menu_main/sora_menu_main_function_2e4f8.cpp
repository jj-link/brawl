#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Node {
    char pad[0x10];
    void* value;
};

struct Model {
    char pad[0x3C];
    float pos[3];
};

struct Models {
    char pad[0x33C];
    void* objects[3];
};

struct Loader {
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
    virtual void attach(void*, void*);
    char pad[0xE0];
    void* context;
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
    u16 selection;
    char pad44[0x638 - 0x44];
    int state;
    const void* config;
    int field640;
    int count;
    int field648;
    Models* models;
    int field650;
    Loader* loader;
    Class_728* view;
    int field65C;
    int field660;
    int mode;
};

extern "C" {
extern u16 lbl_2_data_3A98[];
extern float lbl_2_rodata_F80;
extern float lbl_2_rodata_F84;
u32 fn_8014FEDC(u32);
void fn_800B6838(void*, const float*);
void fn_18_1C4C(Menu*, int);
int fn_18_1A9C(Menu*);
void fn_18_1D48(Menu*, int, int);

void fn_2_2E4F8(Menu* self, Loader* loader, short arg) {
    int sel = arg;
    unsigned off;
    unsigned cnt;
    u32 num;

    self->loader = loader;
    self->config = lbl_2_data_3A98;
    self->count = 0xCF;
    num = fn_8014FEDC(0x10);
    cnt = 0;
    off = 0;

    do {
        if (num != 0 || cnt != 0) {
            loader->attach(
                loader->context,
                ((Node*)*(void**)((char*)self->models + 0x33C + off))->value);
        }
        cnt++;
        off += 4;
    } while (cnt < 3);

    switch (sel) {
    case 3:
        self->mode = 0;
        self->selection = 1;
        self->state = 3;
        fn_18_1C4C(self, 1);
        break;
    default:
        self->mode = 2;
        switch (fn_18_1A9C(self)) {
        case 29:
            sel = 0;
            break;
        case 30:
            sel = 1;
            break;
        case 31:
            sel = 2;
            break;
        }
        self->selection = sel;
        fn_18_1D48(self, sel, 1);
        self->state = 0x22;
        break;
    }

    if (num == 1) {
        lbl_2_data_3A98[12] = 0;
        lbl_2_data_3A98[14] = 0;
        lbl_2_data_3A98[20] = 0;
        lbl_2_data_3A98[22] = 1;

        float pos1[3];
        Model* m = (Model*)self->models->objects[1];
        pos1[0] = m->pos[0];
        pos1[1] = m->pos[1];
        pos1[2] = m->pos[2];
        pos1[0] = lbl_2_rodata_F80;
        fn_800B6838(self->models->objects[1], pos1);

        m = (Model*)self->models->objects[2];
        pos1[0] = m->pos[0];
        pos1[1] = m->pos[1];
        pos1[2] = m->pos[2];
        pos1[0] = lbl_2_rodata_F80;
        fn_800B6838(self->models->objects[2], pos1);
    }

    if (num == 0) {
        lbl_2_data_3A98[12] = 2;
        lbl_2_data_3A98[14] = 2;
        lbl_2_data_3A98[20] = 1;
        lbl_2_data_3A98[22] = 1;

        float pos2[3];
        Model* m = (Model*)self->models->objects[1];
        pos2[0] = m->pos[0];
        pos2[1] = m->pos[1];
        pos2[2] = m->pos[2];
        pos2[0] = lbl_2_rodata_F84;
        fn_800B6838(self->models->objects[1], pos2);

        m = (Model*)self->models->objects[2];
        pos2[0] = m->pos[0];
        pos2[1] = m->pos[1];
        pos2[2] = m->pos[2];
        pos2[0] = lbl_2_rodata_F84;
        fn_800B6838(self->models->objects[2], pos2);
    }

    self->view->fn_2_361C4(0x12, self->selection + 0x32);
}
}