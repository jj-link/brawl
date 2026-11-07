#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

#define FIELD(type, offset) (*(type*)((char*)self + offset))

struct Flags {
    u32 unused;
    u32 flags;
};

class Class_1E10 {
public:
    virtual void fn_74_9ADC();
    virtual void fn_74_8FA4();
    virtual void fn_74_8FB4();
    virtual void fn_74_6B18();
    virtual void fn_74_6758(int, int);
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
void fn_74_264C(void*);
void* __ct__14snd3DGeneratorFv(void*);
void setPos__9grGimmickFfff(void*, float, float, float);
void setRot__9grGimmickFfff(void*, float, float, float);
extern char lbl_74_data_1520[];
extern const float lbl_74_rodata_D0;
extern Global* g_GameGlobal;
}

extern "C" void* fn_74_38DC(void* self) {
    fn_74_264C(self);
    FIELD(char*, 0x3c) = lbl_74_data_1520;
    __ct__14snd3DGeneratorFv((char*)self + 0x190);
    FIELD(u32, 0x158) = 0;
    FIELD(u32, 0x15c) = 0;
    FIELD(u32, 0x160) = 0;
    setPos__9grGimmickFfff(self, lbl_74_rodata_D0, lbl_74_rodata_D0, lbl_74_rodata_D0);
    setRot__9grGimmickFfff(self, lbl_74_rodata_D0, lbl_74_rodata_D0, lbl_74_rodata_D0);

    Class_1E10* comp = (Class_1E10*)((char*)self + 0xd0);
    FIELD(u8, 0x164) = 100;
    FIELD(float, 0x168) = lbl_74_rodata_D0;
    FIELD(float, 0x16c) = lbl_74_rodata_D0;
    FIELD(float, 0x170) = lbl_74_rodata_D0;
    FIELD(float, 0x174) = lbl_74_rodata_D0;
    FIELD(u8, 0x178) = 1;
    FIELD(u8, 0x179) = 0;
    FIELD(u32, 0x17c) = 0;
    FIELD(u32, 0x180) = 0;
    FIELD(u32, 0x184) = 0;
    FIELD(u32, 0x188) = 0;
    FIELD(u32, 0x18c) = 0;
    if (!comp)
        return self;

    comp->value = 1;
    comp->fn_74_6758(0, 15);
    comp->data->flags |= 0x10;
    comp->data->flags |= 0x20;

    FIELD(u8, 0x198) = 0;
    Adv* adv = g_GameGlobal->adv;
    if (!adv)
        return self;
    if (adv->mode != 7)
        return self;
    if (adv->kind == 0x24)
        FIELD(u8, 0x198) = 1;
    return self;
}
