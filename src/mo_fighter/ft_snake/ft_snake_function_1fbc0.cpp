#pragma force_active on
#define V1(n) virtual void unused##n();
#define V2(n) V1(n##a) V1(n##b)
#define V4(n) V2(n##a) V2(n##b)
#define V8(n) V4(n##a) V4(n##b)
#define V16(n) V8(n##a) V8(n##b)
#define V32(n) V16(n##a) V16(n##b)
#define V64(n) V32(n##a) V32(n##b)

struct Vec3 { float x, y, z; };
struct Module54;
struct Ground;
struct Posture;
struct Module14;
struct Situation;
struct OwnerModule;
struct Accesser;

struct Module54 {
    V64(a) V16(b) V4(c) V2(d) V1(e)
    virtual void enable(int);
};

struct Ground {
    char pad[8];
    V64(a) V32(b) V8(c) V4(d) V2(e) V1(f)
    virtual float getZ();
    virtual unsigned attach(int);
};

struct Posture {
    V4(a) V1(b)
    virtual void setPos(const Vec3*);
};

struct Module14 {
    V4(a) V2(b)
    virtual void set(int, bool);
};

struct Situation {
    V2(a) V1(b)
    virtual void set(int, Accesser*);
};

struct OwnerModule {
    char pad[60];
    V32(a) V8(b) V2(c) V1(d)
    virtual void update();
};

struct Modules {
    char pad0[0xc];
    Posture* posture;
    Ground* ground;
    Module14* module14;
    char pad18[0x54 - 0x18];
    Module54* module54;
    char pad58[0x70 - 0x58];
    Situation* situation;
};

struct Accesser {
    char pad0[8];
    OwnerModule* owner;
    char padc[0xd8 - 0xc];
    Modules* modules;
};

struct Object {
    char pad0[0x60];
    Accesser* accesser;
};

extern "C" void fn_122_1FBC0(Object* self, const Vec3* input) {
    Module54* m54 = self->accesser->modules->module54;
    m54->enable(1);

    Vec3 pos = *input;
    Ground* ground = self->accesser->modules->ground;
    pos.z = ground->getZ();

    Posture* posture = self->accesser->modules->posture;
    posture->setPos(&pos);

    ground = self->accesser->modules->ground;
    if (ground->attach(0) == 1) {
        Module14* m14 = self->accesser->modules->module14;
        m14->set(0, false);
        Accesser* accesser = self->accesser;
        Situation* situation = accesser->modules->situation;
        situation->set(1, accesser);
    } else {
        Module14* m14 = self->accesser->modules->module14;
        m14->set(2, false);
        Accesser* accesser = self->accesser;
        Situation* situation = accesser->modules->situation;
        situation->set(2, accesser);
    }

    OwnerModule* owner = self->accesser->owner;
    owner->update();
}
