#pragma force_active on
class Object {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void consume(int*);
};

extern "C" void fn_125_9EC0(Object* object, int* entries, int count) {
    if (entries == 0 || count <= 0) {
        return;
    }

    for (int i = 0; i < count; ++i) {
        object->consume(&entries[i]);
    }
}
