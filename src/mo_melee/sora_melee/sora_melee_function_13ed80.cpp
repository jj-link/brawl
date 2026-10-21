#pragma force_active on
struct Vec3 {
    float x, y, z;
};

struct ModelBase {
    char unused[8];
};

struct Model : ModelBase {
    virtual void unused0();
    virtual void unused1();
    virtual void unused2();
    virtual void unused3();
    virtual void unused4();
    virtual void unused5();
    virtual void unused6();
    virtual void unused7();
    virtual void unused8();
    virtual void unused9();
    virtual void unused10();
    virtual void unused11();
    virtual void unused12();
    virtual void unused13();
    virtual void unused14();
    virtual void unused15();
    virtual void unused16();
    virtual void unused17();
    virtual void unused18();
    virtual void unused19();
    virtual void unused20();
    virtual void unused21();
    virtual void unused22();
    virtual void unused23();
    virtual void unused24();
    virtual void unused25();
    virtual void unused26();
    virtual void unused27();
    virtual void unused28();
    virtual void unused29();
    virtual void unused30();
    virtual void unused31();
    virtual void unused32();
    virtual int getNodeId(int);
    virtual void unused34();
    virtual void unused35();
    virtual Vec3 getPosition(int, int);
};

struct Posture {
    virtual void unused0();
    virtual void unused1();
    virtual void unused2();
    virtual void unused3();
    virtual void unused4();
    virtual void unused5();
    virtual void unused6();
    virtual void unused7();
    virtual void setPosition(const Vec3&);
};

struct Modules {
    char unused0[4];
    Model* model;
    char unused1[4];
    Posture* posture;
};

struct Accessor {
    char unused[0xd8];
    Modules* modules;
};

struct Object {
    char unused[0x60];
    Accessor* accessor;
};

extern "C" void fn_27_13ED80(Object* object) {
    int node = object->accessor->modules->model->getNodeId(0x12d);
    Modules* modules = object->accessor->modules;
    Model* model = modules->model;
    Posture* posture = modules->posture;
    const Vec3& position = model->getPosition(node, 0);
    posture->setPosition(position);
}
