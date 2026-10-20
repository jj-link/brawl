#pragma force_active on
typedef unsigned char u8;

struct Entry {
    unsigned int unused;
    u8* data;
};

class Array {
public:
    virtual void unused();
    virtual Entry* at(int index);
};

class Object {
public:
    virtual void unused00();
    virtual void unused01();
    virtual void unused02();
    virtual void unused03();
    virtual void unused04();
    virtual void unused05();
    virtual void unused06();
    virtual void unused07();
    virtual void unused08();
    virtual void unused09();
    virtual void unused10();
    virtual void unused11();
    virtual void unused12();
    virtual void unused13();
    virtual int enabled();

    u8 padding[0x34];
    Array* array;
};

extern "C" void fn_27_28ED10(u8* self);

extern "C" void fn_27_BA594(Object* self, int index) {
    if (self->enabled()) {
        fn_27_28ED10(self->array->at(index)->data);
    }
}
