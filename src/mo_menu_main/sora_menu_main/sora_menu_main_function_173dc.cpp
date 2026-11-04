#pragma force_active on
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;

struct HandlerBase {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void attach(void*, void*);
};
struct Handler : HandlerBase {
    char pad[0xE0];
    void* resource;
};
struct ControlBase { char pad[0x3C]; };
struct Control : ControlBase {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void select(int, int, int);
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void setup(int, int);
};
struct Anim {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void set(float);
};
struct Node {
    char pad[0xC];
    Anim* anim;
};
struct Object {
    char pad[0x14];
    Node* node;
};
struct Objects {
    char pad[0x154];
    Object* frame;
    Object* items[2];
};
struct Resources {
    char pad[0x10];
    void* data;
};
struct Menu {
    char pad0[0x42];
    u16 selected;
    char pad1[0x5F4];
    int state;
    char pad2[0x10];
    Objects* objects;
    Resources* resources;
    Handler* handler;
    Control* control;
    char pad3[0x8];
    int choice;
    char pad4[0x4];
    u16 count;
    u16 maximum;
};

extern "C" {
extern void* g_GameGlobal;
void* getGlobalRecordMenuDatap__10GameGlobalFv(void*);
extern char lbl_2_data_20D0[];
extern float lbl_2_rodata_610;
void fn_800B330C(void*, void*, int);
void fn_18_17B0(void*, int, int, float);
void setFrameNode__8MuObjectFf(void*, float);

void fn_2_173DC(Menu* self, Handler* handler, int mode) {
    self->handler = handler;
    s8* record = (s8*)getGlobalRecordMenuDatap__10GameGlobalFv(g_GameGlobal);
    self->count = record[0x18];
    self->maximum = 20;
    handler->attach(handler->resource, self->resources->data);
    self->control->setup(0x18, 0x44);
    switch (mode) {
    case 5:
        self->control->select(0x44, 1, 0);
        self->choice = 0;
        self->selected = 0;
        self->state = 5;
        break;
    case 15:
        self->control->select(0x45, 1, 0);
        self->choice = 1;
        self->selected = 1;
        self->state = 15;
        break;
    }
    for (int i = 0; i < 2; ++i) {
        if (i == self->selected)
            fn_800B330C(self->objects->items[i], lbl_2_data_20D0, 1);
        else
            fn_800B330C(self->objects->items[i], lbl_2_data_20D0 + 0x14, 1);
    }
    fn_18_17B0(self, 0x56, 9, (float)self->count);
    setFrameNode__8MuObjectFf(self->objects->frame, (float)self->selected);
    self->objects->frame->node->anim->set(lbl_2_rodata_610);
}
}
