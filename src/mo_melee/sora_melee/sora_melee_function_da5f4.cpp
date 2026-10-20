#pragma force_active on
struct Work {
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
    virtual short call(int*, int, short*, int);
};

struct Object {
    int padding[2];
    Work* work;
};

extern "C" int fn_27_DA5F4(Object* self, int value, signed char flag) {
    short result = 0;
    return self->work->call(&value, -1, &result, flag);
}
