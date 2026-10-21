#pragma force_active on
struct Vec3 {
    float x, y, z;
};

struct Posture {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual Vec3 getPos();
};

struct Modules {
    char pad[0x0C];
    Posture* posture;
};

struct Accesser {
    char pad[0xD8];
    Modules* modules;

    Posture& getPosture() {
        return *modules->posture;
    }
};

struct Object {
    char pad[0x60];
    Accesser* accesser;
};

extern "C" Vec3 getPos__23soExternalValueAccesserFP11StageObject(void*);
extern "C" void fn_105_CBC8(Vec3*, const Vec3*, const Vec3*);
extern "C" float* fn_27_1F21B8();
extern "C" float fn_105_CBEC(const Vec3*);

extern "C" bool fn_105_D38C(Object* object, void* target) {
    const Vec3& position =
        getPos__23soExternalValueAccesserFP11StageObject(target);
    Vec3 difference;
    const Vec3& ownPosition = object->accesser->getPosture().getPos();
    fn_105_CBC8(&difference, &ownPosition, &position);
    float radius = *fn_27_1F21B8();
    return fn_105_CBEC(&difference) <= radius * radius;
}
