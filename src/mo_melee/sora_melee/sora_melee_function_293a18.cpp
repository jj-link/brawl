#pragma force_active on
struct Rec {
    int pad;
    int id;
};

struct Container {
    virtual void f0();
    virtual void f1();
    virtual Rec* get(int);
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void activate(int);
};

struct Holder {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual int count();

    int pad[3];
    Container arr;

    int search(int id) {
        int n = count();
        for (int i = 0; i < n; ++i) {
            if (id == arr.get(i)->id)
                return i;
        }
        return -1;
    }
};

extern "C" void fn_27_293A18(Holder* self, int id) {
    int index;
    if (id <= -1)
        index = -1;
    else
        index = self->search(id);
    if (index >= 0)
        self->arr.activate(index);
}
