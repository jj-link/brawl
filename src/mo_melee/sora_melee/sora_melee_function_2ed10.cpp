#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Object {
    u8 pad0[0xE];
    u16 fieldE;
    u8 pad10[0x62];
    union {
        u8 flags72;
        struct {
            u8 : 4;
            u8 flag72_3 : 1;
            u8 : 2;
            u8 flag72_0 : 1;
        };
    };
    union {
        u8 flags73;
        struct {
            u8 : 4;
            u8 flag73_3 : 1;
            u8 : 1;
            u8 flag73_1 : 1;
            u8 : 1;
        };
    };
    u8 pad74[8];
    unsigned int field7C : 8;
    unsigned int : 24;
};

struct Owner {
    u8* data;
    Object* object;
    u8 pad8[0x2E];
    u16 field36;
    union {
        u32 flags38;
        struct {
            u32 : 16;
            u32 flag38_12 : 4;
            u32 : 12;
        };
    };
    u32 flags3C;
};

extern "C" void fn_80134C88(void*);
extern "C" void fn_80134440(void*, int);
extern "C" void fn_80137684(void*, u32, u32, u32, u32);

extern "C" void fn_27_2ED10(Owner* self) {
    if (self->object) {
        fn_80134C88(self->object);
        self->object->fieldE = 0;
        fn_80134440(self->object, 1);
        self->object->flag72_0 = 0;
        fn_80137684(self->object, 0, 0, 0, 0);
        self->object->flags73 &= ~0x40;
        self->object->flag73_3 = self->flags3C >> 31;
        self->object->field7C = ((self->flags38 >> 2) & 1) ^ 1;
        self->object->flag73_1 = self->flags38 >> 1;
        self->object->flags73 &= ~4;
        self->object->flag72_3 = self->flags38;
    }
    self->field36 = 0;
    self->flag38_12 = *self->data;
}
