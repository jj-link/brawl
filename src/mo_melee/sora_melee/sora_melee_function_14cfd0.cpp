#pragma force_active on
struct Object {
    virtual void unused0();
    virtual void unused1();
    virtual void unused2();
    virtual void unused3();
    virtual int first();
    virtual void unused5();
    virtual void unused6();
    virtual void unused7();
    virtual void unused8();
    virtual void unused9();
    virtual void unused10();
    virtual void unused11();
    virtual void unused12();
    virtual void unused13();
    virtual void unused14();
    virtual void unused15();
    virtual void unused16();
    virtual void unused17();
    virtual void unused18();
    virtual void unused19();
    virtual int second(int);

    unsigned char padding0[0x20];
    int value;
    unsigned char padding1[0x150];
    void* component;
};

extern "C" int fn_27_112244(void*);

extern "C" int fn_27_14CFD0(Object* self, int arg) {
    int first = self->first();
    return fn_27_112244(self->component)
         + (self->value + (first + self->second(arg)));
}
