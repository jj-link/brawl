#pragma force_active on
#define VIRTUAL_TEN(prefix) \
    virtual void prefix##0(); \
    virtual void prefix##1(); \
    virtual void prefix##2(); \
    virtual void prefix##3(); \
    virtual void prefix##4(); \
    virtual void prefix##5(); \
    virtual void prefix##6(); \
    virtual void prefix##7(); \
    virtual void prefix##8(); \
    virtual void prefix##9();

class Base {
public:
    unsigned char padding[0x3C];
    VIRTUAL_TEN(slot0)
    VIRTUAL_TEN(slot1)
    VIRTUAL_TEN(slot2)
    VIRTUAL_TEN(slot3)
    VIRTUAL_TEN(slot4)
    VIRTUAL_TEN(slot5)
    VIRTUAL_TEN(slot6)
    VIRTUAL_TEN(slot7)
    VIRTUAL_TEN(slot8)
    VIRTUAL_TEN(slot9)
    VIRTUAL_TEN(slot10)
    virtual void slot110();
    virtual void slot111();
    virtual void slot112();
    virtual void slot113();
    virtual void slot114();
    virtual void update();
};
#undef VIRTUAL_TEN

struct Object : Base {
    unsigned char padding1[0x14C - 0x40];
    int state;
    unsigned char padding2[0x175 - 0x150];
    unsigned char flag;
};

extern "C" void fn_71_E74C(Object* self) {
    if (self->flag != 1) {
        self->update();
        if (self->state != 0) {
            self->flag = 1;
        }
    }
}
