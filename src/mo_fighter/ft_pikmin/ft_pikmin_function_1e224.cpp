#pragma force_active on

struct Vec2 {
    float x, y;
};

struct Flag {
    unsigned char value;
};

struct ParamAccess;
struct Fighter;

struct ParamBase { char pad[8]; };
struct ParamAccess : ParamBase {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual float getParamFloat(Fighter*, unsigned int, unsigned int);
};

struct Posture {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual float v9();
};

struct Work {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual unsigned int testFlag(unsigned int);
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual float getFloat(unsigned int);
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
    virtual ParamAccess* getParamAccess();
};

struct Kinetic {
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
    virtual void unableEnergyAll();
    virtual Vec2 getSumSpeed(short*);
};

struct Modules {
    char p0[0x0c];
    Posture* posture;
    char p1[0x64 - 0x10];
    Work* work;
    char p2[0x7c - 0x68];
    Kinetic* kinetic;
};

struct Fighter {
    char pad[0xd8];
    Modules* mods;
};

struct Energy {
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
    virtual void activate();
    unsigned char pad[0x30 - 0x04];
    unsigned char active;
};

extern "C" {
extern const float lbl_113_rodata_90;
extern const float lbl_113_rodata_98;
float fn_113_182E4(Vec2*);
unsigned int fn_113_1E50C(Vec2*);
Vec2 fn_113_1E58C(Vec2*);
void fn_113_1E5B8(Vec2*, float);
void fn_8003DBA8(Vec2*);
float fn_113_22580(void*);
float fn_113_225F4(void*);
float fn_113_22668(void*);
float fn_113_226DC(void*);
void fn_113_BC00(Vec2*, const Vec2*);
}

extern "C" void fn_113_1E224(void*, unsigned char* owner_arg, Fighter* fighter) {
    Energy* obj;
    short attr = 1;
    Vec2 speed;
    Vec2 original = fighter->mods->kinetic->getSumSpeed(&attr);
    __memcpy(&speed, &original, sizeof(Vec2));
    fighter->mods->kinetic->unableEnergyAll();

    ParamAccess* params = fighter->mods->work->getParamAccess();
    Flag flag = {0};
    obj = reinterpret_cast<Energy*>(owner_arg += 0x10);
    obj->active = 1;
    obj->activate();

    if (fighter->mods->work->testFlag(0x10000011) & 1) {
        Work* work = fighter->mods->work;
        Posture* posture = fighter->mods->posture;
        if (posture->v9() * work->getFloat(0x11000007) >= lbl_113_rodata_90) {
            float limit = params->getParamFloat(fighter, 0xfce, 0);
            if (fn_113_182E4(&speed) < limit) {
                if (fn_113_1E50C(&speed) == 1) {
                    speed.x = lbl_113_rodata_98;
                    speed.y = lbl_113_rodata_90;
                    if (fighter->mods->posture->v9() < lbl_113_rodata_90) {
                        Vec2 converted = fn_113_1E58C(&speed);
                        speed = converted;
                    }
                } else {
                    fn_8003DBA8(&speed);
                }
                float s = params->getParamFloat(fighter, 0xfce, 0);
                fn_113_1E5B8(&speed, s);
            }
        }
    }

    fn_113_BC00(reinterpret_cast<Vec2*>(
                    reinterpret_cast<char*>(obj) + 8),
                &speed);

    Vec2 v1;
    v1.x = fn_113_22580(fighter);
    v1.y = lbl_113_rodata_90;
    fn_113_BC00(reinterpret_cast<Vec2*>(
                    reinterpret_cast<char*>(obj) + 0x18),
                &v1);

    Vec2 v2;
    v2.x = fn_113_225F4(fighter);
    v2.y = lbl_113_rodata_90;
    fn_113_BC00(reinterpret_cast<Vec2*>(
                    reinterpret_cast<char*>(obj) + 0x20),
                &v2);

    Vec2 v3;
    v3.x = fn_113_22668(fighter);
    v3.y = lbl_113_rodata_90;
    fn_113_BC00(reinterpret_cast<Vec2*>(
                    reinterpret_cast<char*>(obj) + 0x28),
                &v3);

    float d = fn_113_226DC(fighter);
    if (fighter->mods->posture->v9() < lbl_113_rodata_90) {
        d = -d;
    }

    Vec2 v4;
    v4.x = d;
    v4.y = lbl_113_rodata_90;
    fn_113_BC00(reinterpret_cast<Vec2*>(
                    reinterpret_cast<char*>(obj) + 0x10),
                &v4);

    reinterpret_cast<unsigned char*>(obj)[5] |= 0x80;
}
