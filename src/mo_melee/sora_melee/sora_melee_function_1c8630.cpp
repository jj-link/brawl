#pragma force_active on

class Element {
public:
    int pad;
    int value;
};

class Container {
public:
    virtual void a();
    virtual void b();
    virtual Element* get(int index);
    virtual int size();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual void h();
    virtual void i();
    virtual void j();
    virtual void k();
    virtual void l();
    virtual unsigned int m();
};

class Main {
public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual unsigned int check();

    char pad[12];
    Container container;
};

extern "C" int fn_27_1C8630(Main* self) {
    if (self->container.m() == 1) {
        return 0x7FFF;
    }
    if (self->check() == 1) {
        return 0;
    }

    int idx = self->container.size() - 1;
    if (self->container.get(idx)->value < 0x7FFF) {
        idx = self->container.size() - 1;
        return self->container.get(idx)->value + 1;
    }

    int prev_val;
    int i = self->container.size() - 1;
    while (i >= 0) {
        if (i == 0) {
            if (self->container.get(i)->value == 0) {
                return -1;
            }
            return self->container.get(i)->value - 1;
        }

        prev_val = self->container.get(i - 1)->value;
        if (self->container.get(i)->value - 1 > prev_val) {
            return self->container.get(i)->value - 1;
        }
        i--;
    }

    return -1;
}
