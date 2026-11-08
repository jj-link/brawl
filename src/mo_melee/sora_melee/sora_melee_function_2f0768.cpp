#pragma force_active on

extern "C" void* __dynamic_cast(void*, long, const void*, const void*, short);
extern "C" unsigned int fn_27_2EFED4(void*);
extern "C" char lbl_27_data_7E6B0[];
extern "C" char lbl_27_data_248[];
extern "C" char lbl_27_data_457C0[];
extern "C" char lbl_27_data_CDF8[];
extern float lbl_27_rodata_64B0;

struct Vec2 {
    float x;
    float y;

    Vec2(float y_, float x_) {
        y = y_;
        x = x_;
    }
};

struct DynamicObject {
    virtual void s0();
    virtual void s1();
    virtual unsigned long long getHandle(float);
    virtual void s3();
    virtual void s4();
    virtual void initialize(int, float*, float*, void*, float);

    char pad04[1];
    unsigned char flags;
    char pad06[0x12];
    float scaleX;
    float scaleY;

    void setScale(const Vec2& scale) {
        scaleX = scale.x;
        scaleY = scale.y;
    }
};

struct StateModule {
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
    virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7();
    virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
    virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15();
    virtual int getState();
};

struct FloatModule {
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
    virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7();
    virtual void s8(); virtual float getValue();
};

struct GetObjectModule {
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
    virtual void s4(); virtual void s5(); virtual void* getObject(int);
};

struct SubmitModule {
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
    virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7();
    virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
    virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15();
    virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19();
    virtual void s20(); virtual void s21(); virtual void s22(); virtual void s23();
    virtual void s24(); virtual void s25(); virtual void s26(); virtual void s27();
    virtual void s28(); virtual void s29(); virtual void s30(); virtual void s31();
    virtual void s32(); virtual void s33(); virtual void s34(); virtual void s35();
    virtual void s36(); virtual void s37(); virtual void s38(); virtual void s39();
    virtual void s40(); virtual void submit(int*);
};

struct SetModule {
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
    virtual void s4(); virtual void set(int, int);
};

struct Modules {
    char pad00[0x0c];
    FloatModule* floatModule;
    char pad10[0x0c];
    SubmitModule* submitModule;
    char pad20[0x44];
    SetModule* setModule;
    char pad68[0x08];
    StateModule* stateModule;
    char pad74[0x08];
    GetObjectModule* getObjectModule;
};

struct Object {
    char pad00[0x08];
    void* castObject;
    char pad0c[0xcc];
    Modules* modules;
};

struct AttackData {
    char pad00[4];
    int value;
    char pad08[4];
    float scaleX;
    char pad10[4];
    float scaleY;
};

struct ManagerData {
    char pad00[0x34];
    AttackData* attackData;
};

extern "C" void fn_27_2F0768(void*, Object* object) {
    switch (object->modules->stateModule->getState()) {
    case 1:
        break;
    case 0: {
        void* cast = __dynamic_cast(object->castObject, 0x3c,
                                    lbl_27_data_7E6B0, lbl_27_data_248, 1);
        ManagerData* manager = (ManagerData*)fn_27_2EFED4(cast);
        AttackData* attack = manager->attackData;
        float factor = object->modules->floatModule->getValue();
        int value = attack->value;
        void* energy = object->modules->getObjectModule->getObject(0);
        DynamicObject* collision = (DynamicObject*)__dynamic_cast(
            energy, 0, lbl_27_data_457C0, lbl_27_data_CDF8, 1);

        float extent[3];
        float position[2];
        extent[0] = lbl_27_rodata_64B0;
        extent[1] = lbl_27_rodata_64B0;
        extent[2] = lbl_27_rodata_64B0;
        position[0] = attack->scaleX * factor;
        position[1] = lbl_27_rodata_64B0;
        collision->initialize(0, position, extent, object, lbl_27_rodata_64B0);

        float scaled = attack->scaleY;
        scaled *= factor;
        Vec2 scale(lbl_27_rodata_64B0, scaled);
        collision->setScale(scale);
        collision->flags |= 0x80;

        unsigned long long handle = collision->getHandle(scale.x);
        int result[2];
        result[0] = (int)(handle >> 32);
        result[1] = (int)handle;
        object->modules->submitModule->submit(result);
        object->modules->setModule->set(0, 0x10000006);
        object->modules->setModule->set(value, 0x10000005);
        break;
    }
    }
}
