#pragma force_active on
#define V(n) virtual void v##n();
#define V10(n) \
    V(n##0) V(n##1) V(n##2) V(n##3) V(n##4) \
    V(n##5) V(n##6) V(n##7) V(n##8) V(n##9)

struct Object;

extern "C" void fn_27_12BAF8(Object*, int);
extern "C" int fn_27_111E30(void*);

struct Motion {
    V(0) V(1) V(2) V(3) V(4) V(5)
    V(6) V(7) V(8) V(9) V(10)
    virtual void reset(int);
    V(12) V(13) V(14) V(15) V(16)
    virtual void change(int, int, int);
    virtual void on(int);
    virtual void off(int);
};

struct OtherBase {
    char pad[8];
};

struct Other : OtherBase {
    V10(0) V10(1) V10(2)
    V(30) V(31) V(32) V(33) V(34) V(35)
};

struct Modules {
    char pad0[0x20];
    Motion* motion;
    char pad1[0x40];
    Motion* work;
    char pad2[0x34];
    Other* other;
};

struct Access {
    char pad[0xd8];
    Modules* modules;
};

struct ObjectBase {
    char pad[0x3c];
};

struct Object : ObjectBase {
    V10(0) V10(1) V10(2) V10(3) V10(4)
    V10(5) V10(6) V10(7) V10(8) V10(9)
    V10(10) V10(11) V10(12) V10(13)
    V10(14) V10(15) V10(16) V10(17)
    V(180) V(181) V(182) V(183) V(184)
    virtual void* get();

    char pad1[0x20];
    Access* access;
};

#undef V10
#undef V

extern "C" void fn_123_8C64(Object* self, int param) {
    fn_27_12BAF8(self, param);
    self->access->modules->motion->change(0x13, 3, 0);
    self->access->modules->motion->reset(0);
    self->access->modules->other->v35();

    if (fn_27_111E30(self->get())) {
        self->access->modules->work->on(0x1200003e);
    } else {
        self->access->modules->work->off(0x1200003e);
    }
}
