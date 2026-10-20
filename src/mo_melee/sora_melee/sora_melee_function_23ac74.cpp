#pragma force_active on
extern "C" void fn_27_23F008(void*);
extern "C" unsigned char lbl_27_data_4D0E0[];

struct GameGlobal {
    unsigned char pad[0x30];
    void* data;
};

extern "C" GameGlobal* g_GameGlobal;

struct Object {
    unsigned char pad0[0x3C];
    void* vtable;
    unsigned char pad40[0x8C];
    unsigned int cc;
    void* d0;
    unsigned int d4;
    unsigned int d8;
    unsigned int dc;
    unsigned int e0;
};

extern "C" Object* fn_27_23AC74(Object* self) {
    fn_27_23F008(self);
    self->vtable = lbl_27_data_4D0E0;
    self->cc = 0;
    self->d4 = 0;
    self->d8 = 0;
    self->dc = 0;
    self->e0 = 0;
    self->d0 = g_GameGlobal->data;
    return self;
}
