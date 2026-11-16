#pragma force_active on

extern "C" const float lbl_27_rodata_400[];

struct Vec3f {
    float x;
    float y;
    float z;
};

class Other {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual Vec3f getBase();
};

struct AccessorHead {
    void* head0;
    void* head4;
};

class Accesser : public AccessorHead {
public:
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
    virtual Vec3f getPoint(void* item, int flag);
};

struct Module {
    void* pad0;
    Accesser* accesser;
    void* pad8;
    Other* other;
};

struct Object {
    char pad[0xd8];
    Module* module;
};

struct List {
    void* pad0;
    void** items;
    unsigned int count;
};

extern "C" void fn_27_2F06C(List** listp, Object* obj, float* minX, float* minY, float* maxX, float* maxY) {
    (void)0.0f;
    (void)1.0f;
    List* list = *listp;
    Module* module = obj->module;
    const Vec3f& base = module->other->getBase();
    *minX = 3.4028234663852886e+38f;
    *minY = 0.0f;
    *maxX = 1.1754943508222875e-38f;
    *maxY = 1.1754943508222875e-38f;
    for (unsigned int i = 0; i < list->count; i++) {
        const Vec3f& p = obj->module->accesser->getPoint(list->items[i], 0);
        float dx = p.x - base.x;
        float dy = p.y - base.y;
        if (*minX > dx) {
            *minX = dx;
        }
        if (*maxX < dx) {
            *maxX = dx;
        }
        if (*minY > dy) {
            *minY = dy;
        }
        if (*maxY < dy) {
            *maxY = dy;
        }
    }
}
