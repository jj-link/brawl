#pragma force_active on
struct Accesser;

class Service {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void apply(int, int, Accesser*);
};

struct Modules {
    char pad[0x6C];
    Service* service;
};

struct Accesser {
    char pad[0xD8];
    Modules* modules;
};

struct Object {
    char pad0[0x44];
    Accesser* accesser;
    char pad1[0x28];
    int handle;
    int current;
};

extern "C" int fn_27_9A5EC(Object*, int);

extern "C" void fn_27_9A56C(Object* self, int value) {
    if (value == self->current) {
        self->accesser->modules->service->apply(self->handle, 0, self->accesser);
        self->current = -1;
    }

    while (fn_27_9A5EC(self, value) != 0) {}
}
