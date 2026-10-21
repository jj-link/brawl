#pragma force_active on
class Entry {
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
    virtual void call(float, unsigned int, unsigned int);
};

class Array {
public:
    virtual void v0();
    virtual Entry*& at(int);
    virtual void v2();
    virtual int size();
};

struct Context {
    char padding[0x30];
    Array* entries;
    int index;
};

extern "C" void fn_27_74274(Context* self, unsigned int a, unsigned int b, float f) {
    int index = self->index;
    if (index >= 0 && index < self->entries->size()) {
        Entry* entry = self->entries->at(index);
        if (entry) {
            entry->call(f, a, b);
        }
    }
}
