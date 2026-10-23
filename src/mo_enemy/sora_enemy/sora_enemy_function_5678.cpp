#pragma force_active on

struct Vec3 {
    float x, y, z;

    Vec3() {}
    Vec3(const Vec3& v) : x(v.x), y(v.y), z(v.z) {}
};

struct Obj {
    virtual void slot00();
    virtual void slot01();
    virtual void slot02();
    virtual void set(Vec3*);
    virtual Vec3 get();
    virtual void move(Vec3*);
    virtual void slot06();
    virtual void slot07();
    virtual void slot08();
    virtual void slot09();
    virtual void setZ(float);
};

struct Mid {
    char pad[0xc];
    Obj* obj;
};

struct Outer {
    char pad[0x1b4];
    Mid* mid;
};

extern "C" void fn_41_5678(Outer* self, Vec3* arg1, unsigned int arg2) {
    Obj* obj = self->mid->obj;
    Vec3 sp8 = obj->get();
    sp8.x = arg1->x;
    sp8.y = arg1->y;
    if (arg2 == 1) {
        obj->set(&sp8);
    } else {
        obj->move(&sp8);
    }
    obj->setZ(arg1->z);
}
