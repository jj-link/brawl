#pragma force_active on
struct Entry {
    unsigned char flag : 1;
    unsigned char padding[23];
};

class Array {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual int size() const;

    int count;
    Entry entries[1];
};

struct Object {
    unsigned char padding[16];
    Array array;
};

extern "C" bool fn_27_D84D4(Object* self, int index) {
    if (index < 0 || index >= self->array.size())
        return false;
    return self->array.entries[index].flag;
}
