#pragma force_active on
struct Fn117Prefix {
    unsigned int first;
    unsigned int second;
};

struct Fn117Interface : Fn117Prefix {
    virtual void slot00();
    virtual void slot01();
    virtual void slot02();
    virtual void slot03();
    virtual void slot04();
    virtual void slot05();
    virtual void slot06();
    virtual void slot07();
    virtual void slot08();
    virtual void slot09();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void call(int);
};

struct Fn117Holder {
    unsigned char pad[4];
    Fn117Interface* object;
};

struct Fn117Access {
    unsigned char pad[0xD8];
    Fn117Holder* holder;
};

extern "C" void fn_117_EFCC(void*, Fn117Access* access) {
    access->holder->object->call(6);
}
