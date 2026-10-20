#pragma force_active on
typedef unsigned char u8;

struct State {
    u8 padding[0xC];
    u8 value;
};

struct Base {
    u8 padding[0x3C];
};

#define VIRTUAL_SLOT(n) virtual void unused##n();
#define VIRTUAL_TEN(n) \
    VIRTUAL_SLOT(n##0) VIRTUAL_SLOT(n##1) \
    VIRTUAL_SLOT(n##2) VIRTUAL_SLOT(n##3) \
    VIRTUAL_SLOT(n##4) VIRTUAL_SLOT(n##5) \
    VIRTUAL_SLOT(n##6) VIRTUAL_SLOT(n##7) \
    VIRTUAL_SLOT(n##8) VIRTUAL_SLOT(n##9)

struct Object : Base {
    VIRTUAL_TEN(0)
    VIRTUAL_TEN(1)
    VIRTUAL_TEN(2)
    VIRTUAL_TEN(3)
    virtual State* getState();
    VIRTUAL_TEN(4)
    VIRTUAL_TEN(5)
    VIRTUAL_TEN(6)
    VIRTUAL_TEN(7)
    VIRTUAL_TEN(8)
    VIRTUAL_TEN(9)
    VIRTUAL_TEN(10)
    VIRTUAL_TEN(11)
    VIRTUAL_SLOT(120)
    VIRTUAL_SLOT(121)
    VIRTUAL_SLOT(122)
    VIRTUAL_SLOT(123)
    VIRTUAL_SLOT(124)
    VIRTUAL_SLOT(125)
    VIRTUAL_SLOT(126)
    VIRTUAL_SLOT(127)
    VIRTUAL_SLOT(128)
    virtual void update();

    u8 padding1[0x14C - 0x40];
    void* object;
    u8 padding2[0x1B4 - 0x150];
    u8 value;
};

#undef VIRTUAL_TEN
#undef VIRTUAL_SLOT

extern "C" void fn_27_26399C(void*);

extern "C" void fn_51_F3EC(Object* self) {
    State* state = self->getState();
    if (state) {
        fn_27_26399C(self->object);
        if (self->value != state->value) {
            self->update();
        }
    }
}
