#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

struct Flags {
    u32 unused;
    u32 flags;
};

struct Component {
    virtual void unused0();
    virtual void unused1();
    virtual void unused2();
    virtual void unused3();
    virtual void init(int, int);
    Flags* data;
    u32 value;
};

struct Adv {
    u8 pad0[8];
    u8 mode : 6;
    u8 other : 2;
    u8 pad9[7];
    u8 kind;
};

struct Global {
    u8 pad[8];
    Adv* adv;
};

extern "C" {
void fn_67_2058(void*);
void __ct__14snd3DGeneratorFv(void*);
extern char lbl_67_data_11C8[];
extern const float lbl_67_rodata_10;
extern const float lbl_67_rodata_14;
extern Global* g_GameGlobal;
}

#define FIELD(type, offset) (*(type*)((char*)self + offset))

extern "C" void* fn_67_223C(void* self) {
    fn_67_2058(self);
    FIELD(char*, 0x3c) = lbl_67_data_11C8;
    __ct__14snd3DGeneratorFv((char*)self + 0x1c8);

    FIELD(u8, 0x158) = 1;
    FIELD(u32, 0x15c) = 0;
    FIELD(float, 0x160) = lbl_67_rodata_10;
    FIELD(u8, 0x164) = 0;
    FIELD(float, 0x168) = lbl_67_rodata_10;
    FIELD(u8, 0x16c) = 0;
    FIELD(float, 0x170) = lbl_67_rodata_10;
    FIELD(float, 0x174) = lbl_67_rodata_10;
    FIELD(float, 0x178) = lbl_67_rodata_10;
    FIELD(float, 0x17c) = lbl_67_rodata_10;
    FIELD(float, 0x180) = lbl_67_rodata_10;
    FIELD(float, 0x184) = lbl_67_rodata_10;
    FIELD(float, 0x188) = lbl_67_rodata_10;
    FIELD(float, 0x18c) = lbl_67_rodata_14;
    FIELD(float, 0x190) = lbl_67_rodata_14;
    FIELD(float, 0x194) = lbl_67_rodata_14;
    FIELD(u8, 0x198) = 10;
    FIELD(u8, 0x199) = 0;
    FIELD(float, 0x19c) = lbl_67_rodata_10;
    FIELD(u8, 0x1a0) = 0;
    FIELD(u32, 0x1a4) = 0;
    FIELD(u8, 0x1a8) = 0;
    FIELD(u8, 0x1a9) = 1;
    FIELD(float, 0x1ac) = lbl_67_rodata_10;
    FIELD(u8, 0x1b0) = 0;
    FIELD(u8, 0x1b1) = 0;
    FIELD(u32, 0x1b4) = 0;
    FIELD(u32, 0x1b8) = 0;
    FIELD(u32, 0x1bc) = 0;
    FIELD(u32, 0x1c0) = 0;
    FIELD(u32, 0x1c4) = 0;

    Component* component = (Component*)((char*)self + 0xd0);
    if (!component)
        return self;

    component->value = 1;
    component->init(0, 15);
    component->data->flags |= 0x10;
    component->data->flags |= 4;

    FIELD(u8, 0x1d0) = 0;
    Adv* adv = g_GameGlobal->adv;
    if (!adv)
        return self;
    if (adv->mode != 7)
        return self;
    if (adv->kind == 3)
        FIELD(u8, 0x1d0) = 1;

    return self;
}
