#pragma force_active on

struct Vec3f {
    float x, y, z;
};

struct Work {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual int getInt(int);
    virtual void setInt(int, int);
};

struct Model {
    char pad[8];
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
    virtual void setNodeScale(int, const Vec3f*);
};

extern "C" {
extern const float lbl_95_rodata_68;
extern float lbl_95_data_7FDC[4];
extern float lbl_95_data_7FEC[4];

Vec3f* fn_95_ABB4(Vec3f*, float, float, float);

void fn_95_100C4(void* fighter) {
    char* modules = *reinterpret_cast<char**>(
        static_cast<char*>(fighter) + 0xd8);
    Work* work = *reinterpret_cast<Work**>(modules + 0x64);
    Model* model = *reinterpret_cast<Model**>(modules + 4);

    Vec3f scale;
    fn_95_ABB4(&scale, lbl_95_rodata_68,
              lbl_95_rodata_68, lbl_95_rodata_68);

    int count = work->getInt(0x20000002);
    if (count >= 0 && count < 4) {
        scale.y *= lbl_95_data_7FDC[count];
        scale.z *= lbl_95_data_7FEC[count];
        ++count;
    }

    model->setNodeScale(2, &scale);
    work->setInt(count, 0x20000002);
}
}
