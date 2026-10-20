#pragma force_active on
typedef unsigned int u32;
typedef unsigned short u16;

struct Vec3 {
    float x, y, z;
};

struct CallbackData {
    u32 id;
    u32 flags;
    Vec3 position;
};

struct Callback {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void initialize(int, int);

    CallbackData* data;
    void* owner;
    u32 state;
};

struct Model {
    char pad0[0x11C];
    Callback* callback;
    u16 field120;
    u16 priority;
};

struct ObjectBase {
    char pad0[0x3C];
};

#define DECLARE_SLOT(n) virtual void slot##n();

struct Object : ObjectBase {
    DECLARE_SLOT(0) DECLARE_SLOT(1) DECLARE_SLOT(2) DECLARE_SLOT(3) DECLARE_SLOT(4)
    DECLARE_SLOT(5) DECLARE_SLOT(6) DECLARE_SLOT(7) DECLARE_SLOT(8) DECLARE_SLOT(9)
    DECLARE_SLOT(10) DECLARE_SLOT(11) DECLARE_SLOT(12) DECLARE_SLOT(13) DECLARE_SLOT(14)
    DECLARE_SLOT(15) DECLARE_SLOT(16) DECLARE_SLOT(17) DECLARE_SLOT(18) DECLARE_SLOT(19)
    DECLARE_SLOT(20) DECLARE_SLOT(21) DECLARE_SLOT(22) DECLARE_SLOT(23) DECLARE_SLOT(24)
    DECLARE_SLOT(25) DECLARE_SLOT(26) DECLARE_SLOT(27) DECLARE_SLOT(28) DECLARE_SLOT(29)
    DECLARE_SLOT(30) DECLARE_SLOT(31) DECLARE_SLOT(32) DECLARE_SLOT(33) DECLARE_SLOT(34)
    DECLARE_SLOT(35) DECLARE_SLOT(36) DECLARE_SLOT(37) DECLARE_SLOT(38) DECLARE_SLOT(39)
    DECLARE_SLOT(40) DECLARE_SLOT(41) DECLARE_SLOT(42) DECLARE_SLOT(43) DECLARE_SLOT(44)
    DECLARE_SLOT(45) DECLARE_SLOT(46) DECLARE_SLOT(47) DECLARE_SLOT(48) DECLARE_SLOT(49)
    DECLARE_SLOT(50) DECLARE_SLOT(51) DECLARE_SLOT(52) DECLARE_SLOT(53) DECLARE_SLOT(54)
    DECLARE_SLOT(55) DECLARE_SLOT(56) DECLARE_SLOT(57) DECLARE_SLOT(58) DECLARE_SLOT(59)
    DECLARE_SLOT(60) DECLARE_SLOT(61) DECLARE_SLOT(62) DECLARE_SLOT(63) DECLARE_SLOT(64)
    DECLARE_SLOT(65) DECLARE_SLOT(66) DECLARE_SLOT(67) DECLARE_SLOT(68) DECLARE_SLOT(69)
    DECLARE_SLOT(70) DECLARE_SLOT(71) DECLARE_SLOT(72) DECLARE_SLOT(73) DECLARE_SLOT(74)
    DECLARE_SLOT(75) DECLARE_SLOT(76) DECLARE_SLOT(77) DECLARE_SLOT(78) DECLARE_SLOT(79)
    DECLARE_SLOT(80) DECLARE_SLOT(81) DECLARE_SLOT(82) DECLARE_SLOT(83) DECLARE_SLOT(84)
    DECLARE_SLOT(85) DECLARE_SLOT(86) DECLARE_SLOT(87) DECLARE_SLOT(88) DECLARE_SLOT(89)
    DECLARE_SLOT(90) DECLARE_SLOT(91) DECLARE_SLOT(92) DECLARE_SLOT(93) DECLARE_SLOT(94)
    DECLARE_SLOT(95) DECLARE_SLOT(96) DECLARE_SLOT(97) DECLARE_SLOT(98) DECLARE_SLOT(99)
    DECLARE_SLOT(100) DECLARE_SLOT(101) DECLARE_SLOT(102) DECLARE_SLOT(103) DECLARE_SLOT(104)
    DECLARE_SLOT(105) DECLARE_SLOT(106) DECLARE_SLOT(107) DECLARE_SLOT(108) DECLARE_SLOT(109)
    DECLARE_SLOT(110) DECLARE_SLOT(111) DECLARE_SLOT(112) DECLARE_SLOT(113) DECLARE_SLOT(114)
    virtual void* getOwner();

    u32 field40;
    Model** model;
    char pad48[0xC4 - 0x48];
    u32 id;
    char padC8[8];
    Callback callback;
    char padE0[0x158 - 0xE0];
    Vec3* position;
};

#undef DECLARE_SLOT

extern "C" void EnableScnMdlCallbackTiming__Q34nw4r3g3d12ScnMdlSimpleFUl(void*, u32);

extern "C" void fn_51_3E64(Object* self) {
    Callback* callback = &self->callback;
    if (callback) {
        Model* model = *self->model;
        if (model) {
            if (!callback->data) {
                callback->owner = self->getOwner();
                callback->initialize(0, 15);
                callback->data->flags |= 1;
            }
            if (!model->callback) {
                callback->state = 0;
                callback->data->id = self->id;
                model->callback = callback;
                EnableScnMdlCallbackTiming__Q34nw4r3g3d12ScnMdlSimpleFUl(model, 1);
                model->priority = callback->data->id;
            }
            Vec3* position = self->position;
            if (position) {
                callback->data->position = *position;
            }
        }
    }
}
