#pragma force_active on
struct Entry {
    unsigned int unused;
    void* value;
};

class Container {
public:
    virtual void unused();
    virtual Entry* at(int index);
};

class Object {
public:
    virtual void unused0();
    virtual void unused1();
    virtual void unused2();
    virtual void unused3();
    virtual void unused4();
    virtual void unused5();
    virtual void unused6();
    virtual void unused7();
    virtual void unused8();
    virtual void unused9();
    virtual void unused10();
    virtual void unused11();
    virtual void unused12();
    virtual void unused13();
    virtual int valid(int index);

    unsigned char padding[0x34];
    Container* entries;
};

extern "C" void fn_27_28F418(void*, void*);

extern "C" void fn_27_BC024(Object* self, void* value, int index) {
    if (self->valid(index) != 0) {
        fn_27_28F418(self->entries->at(index)->value, value);
    }
}
