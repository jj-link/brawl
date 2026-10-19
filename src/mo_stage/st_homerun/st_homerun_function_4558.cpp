#pragma force_active on
typedef unsigned int u32;

struct Item {
    u32 unk0;
    u32 flags;
    char pad[0x78];
};

class Container {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void initialize(int, int);

    Item* items;
    u32 count;
    char pad[0x7C];
};

struct Object {
    char pad0[0x3C];
    void* vtable;
    char pad40[0x90];
    Container container;
    u32 field158;
    float field15C;
    float field160;
    float field164;
    u32 field168;
    u32 field16C;
    u32 field170;
    u32 field174;
    u32 field178;
    u32 field17C;
    u32 field180;
    u32 field184;
    u32 field188;
    u32 field18C;
    u32 field190;
    float field194;
};

extern "C" void fn_88_4368(Object*);
extern "C" const float lbl_88_rodata_E8[];
extern "C" char lbl_88_data_B04[];

extern "C" Object* fn_88_4558(Object* self) {
    fn_88_4368(self);
    self->vtable = lbl_88_data_B04;
    self->field158 = 0;
    self->field15C = lbl_88_rodata_E8[0];
    self->field160 = lbl_88_rodata_E8[0];
    self->field164 = lbl_88_rodata_E8[0];
    self->field168 = 0;
    self->field16C = 0;
    self->field170 = 0;
    self->field174 = 0;
    self->field178 = 0;
    self->field17C = 0;
    self->field180 = 0;
    self->field184 = 0;
    self->field188 = 0;
    self->field18C = 0;
    self->field190 = 0;
    self->field194 = lbl_88_rodata_E8[0];

    Container* c = &self->container;
    if (!c) return self;
    {
        c->count = 4;
        c->initialize(0, 15);
        c->items[0].flags |= 1;
        c->items[1].flags |= 16;
        c->items[2].flags |= 16;
        c->items[3].flags |= 16;
    }
    return self;
}
