#pragma force_active on
struct Vec3f {
    float x, y, z;

    Vec3f() {}
    Vec3f(const Vec3f& v) : x(v.x), y(v.y), z(v.z) {}

    Vec3f& operator=(const Vec3f& v) {
        x = v.x;
        y = v.y;
        z = v.z;
        return *this;
    }
};

struct Data {
    char pad[0x2c];
    float z;
};

struct Padding {
    char pad[0x3c];
};

struct Object : Padding {
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
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual Data* getData();
};

extern "C" void getRot__9grGimmickFv(Vec3f*, void*);
extern "C" void setRot__9grGimmickFfff(void*, float, float, float);

extern "C" void fn_74_B3F0(Object* self) {
    Data* data = self->getData();
    if (data) {
        Vec3f rot;
        Vec3f temp;
        getRot__9grGimmickFv(&temp, self);
        rot = temp;
        rot.z = data->z;
        setRot__9grGimmickFfff(self, rot.x, rot.y, rot.z);
    }
}
