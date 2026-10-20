#pragma force_active on
typedef unsigned int u32;
typedef unsigned char u8;

struct Pair {
    u32 a, b;
};

struct Data {
    Pair a, b;
};

struct Object {
    u32 zero;
    void* vtable;
    u32 value;
    u8 flag;
    Data data;
    u32 state;
    u8 enabled;
};

struct GlobalData {
    u8 pad[0x4924];
    u8 flags;
};

struct GameGlobal {
    u8 pad[0x30];
    GlobalData* data;
};

extern "C" {
extern u8 lbl_27_data_4C234[];
extern GameGlobal* g_GameGlobal;

Object* fn_27_236E64(Object* self, u32 value, Data* data, u8 flag) {
    self->zero = 0;
    self->value = value;
    self->flag = flag;
    self->vtable = lbl_27_data_4C234;
    self->data = *data;
    self->state = 0;
    self->enabled = 0;
    if ((((u32)g_GameGlobal->data->flags >> 7) & 1) == 1)
        self->enabled = 1;
    return self;
}
}
