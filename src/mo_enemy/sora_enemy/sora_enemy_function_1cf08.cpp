#pragma force_active on
struct Vec3 {
    float x, y, z;

    Vec3() {}
    Vec3(const Vec3& v) : x(v.x), y(v.y), z(v.z) {}
};

class Module {
public:
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3C();
    virtual Vec3 get(int);
    virtual void set(const Vec3&, int);
    virtual void v48();
    virtual void v4C();
    virtual float value();
};

struct Access {
    char pad[12];
    Module* module;
};

struct Object {
    char pad[0xD8];
    Access* access;
};

extern "C" const float lbl_41_rodata_CD0[];
extern "C" Vec3 fn_41_1E768(Object*, int, int, int, float);
extern "C" void fn_41_1BEBC(Vec3*, const Vec3*, const Vec3*);

extern "C" void fn_41_1CF08(Object* obj, int index) {
    Module* mod = obj->access->module;
    Vec3 delta = fn_41_1E768(
        obj, 4, index, 0, -(lbl_41_rodata_CD0[0] * mod->value()));
    Vec3 pos = mod->get(index);
    fn_41_1BEBC(&pos, &delta, &pos);
    mod->set(pos, index);
}
