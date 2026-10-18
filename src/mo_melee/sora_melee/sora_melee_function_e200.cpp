#pragma force_active on
struct Base {
    virtual void f0();
    virtual int* f1(int);
    virtual void f2();
    virtual void f3();
};

struct Owner {
    int a;
    Base* obj;
    void* data;
    int count;
};

extern "C" int* fn_27_E200(Owner* self, int index) {
    if (index >= self->count && self->obj) {
        return self->obj->f1(index - self->count);
    }
    return (int*)((char*)self->data + index * 8);
}
