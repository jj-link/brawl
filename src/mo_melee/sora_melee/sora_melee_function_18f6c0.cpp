#pragma force_active on

struct Vec2 {
    float x, y;
};

struct Vec3 {
    float x, y, z;
};

struct Object;

struct Work {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void set(int, unsigned int);
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void onFlag(unsigned int);
};

struct Target {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void setup(int, Vec2*, Vec3*, Object*);
    unsigned char pad4;
    unsigned char flags;
};

struct Other {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void* get(int);
};

struct Modules {
    char pad[0x64];
    Work* work;
    char pad2[0x14];
    Other* other;
};

struct Object {
    char pad[0xd8];
    Modules* modules;
};

extern "C" void* __dynamic_cast(void*, long, const void*, const void*, short);
extern "C" char lbl_27_data_2E5F8[];
extern "C" char lbl_27_data_CDF8[];
extern "C" float lbl_27_rodata_2630;
extern "C" float lbl_27_rodata_2634;

extern "C" void fn_27_18F6C0(void*, Object* object) {
    object->modules->work->set(0x29, 0x20000001);

    Target* target = (Target*)__dynamic_cast(
        object->modules->other->get(3),
        0, lbl_27_data_2E5F8, lbl_27_data_CDF8, 1);

    Vec3 pos;
    pos.x = lbl_27_rodata_2630;
    pos.y = lbl_27_rodata_2630;
    pos.z = lbl_27_rodata_2630;

    Vec2 size;
    size.x = lbl_27_rodata_2630;
    size.y = lbl_27_rodata_2634;

    target->setup(0x16, &size, &pos, object);
    target->flags |= 0x80;
    object->modules->work->onFlag(0x22000010);
}
