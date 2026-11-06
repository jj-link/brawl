#include <ft/ft_common_data_accesser.h>
#include <mt/mt_vector.h>

#pragma force_active on

extern "C" {
extern const unsigned char lbl_95_data_81D8[];
extern const unsigned char lbl_95_data_810C[];
extern const unsigned char lbl_95_data_2C38[];

void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_95_10570(void*, int);
void fn_95_10374(void*);
void fn_95_10704(void*);
int fn_95_10678(void*);
float fn_95_A8B4(float);
void fn_95_DF08(void*, const Vec2f*);
}

class Class_8DBC {
public:
    virtual void fn_95_8008();
    virtual void fn_95_16C80();
    virtual void fn_95_17664();
    virtual void fn_95_1765C();
    virtual void fn_95_17654();
    virtual void fn_95_1764C();
    virtual void fn_95_17644();
    virtual void fn_95_1763C();
    virtual void fn_95_17634();
    virtual void fn_95_1762C();
    virtual void fn_95_17624();
    virtual void fn_95_1761C();
    virtual void fn_95_17614();
    virtual void fn_95_1760C();
    virtual void fn_95_175BC();
    virtual void fn_95_17604();
    virtual float fn_95_175F4();
    virtual void fn_95_175E4();
    virtual void fn_95_175D4();
    virtual void fn_95_175C4();
};

struct Work {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void setInt(int, int);
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual float getFloat(int);
    virtual void setFloat(float, int);
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
    virtual float getLr();
    virtual void setLr(float);
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void updateRot();
};

struct Situation {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int getKind();
    virtual void v4();
    virtual void v5();
    virtual void setKind(int, bool);
};

struct Kinetic {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void* getEnergy(int);
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual Vec2f getSumSpeed(const short&);
};

struct GroundBase {
    char pad[8];
};

struct Ground : GroundBase {
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
    virtual void correct(int, int);
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
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual bool isTouch(int, int);
};

struct Modules {
    char pad0[0xc];
    Posture* posture;
    Ground* ground;
    Situation* situation;
    char pad18[0x44];
    Class_8DBC* controller;
    char pad60[4];
    Work* work;
    char pad68[0x14];
    Kinetic* kinetic;
};

struct Accesser {
    char pad[0xd8];
    Modules* modules;
};

struct Params {
    char pad[0x1c];
    float a;
    float b;
    char pad24[0x30];
    float c;
    char pad58[0xc];
    float d;
    float e;
    float f;
    float g;
    float h;
};

// The constant-pool address still differs from the original relocation.
extern "C" void fn_95_13070(void*, Accesser* accesser) {
    Modules* modules = accesser->modules;
    Work* work = modules->work;
    Class_8DBC* controller = modules->controller;
    Situation* situation = modules->situation;
    Kinetic* kinetic = modules->kinetic;
    Posture* posture = modules->posture;
    Ground* ground = modules->ground;
    Params* params = *(Params**)((char*)g_ftCommonDataAccesser.getData((ftKind)4) + 0x7c);

    (void)0.0f;
    (void)0.10471976f;
    short mask = 1;
    Vec2f speed;
    __memcpy(&speed, &kinetic->getSumSpeed(mask), sizeof(speed));

    float value = work->getFloat(0x21000006);
    float lr = posture->getLr();
    bool grounded = situation->getKind() == 0;
    bool touch;

    if (1.0f == lr) {
        touch = ground->isTouch(4, 0);
        if (touch)
            fn_95_10570(accesser, 4);
    } else {
        touch = ground->isTouch(2, 0);
        if (touch)
            fn_95_10570(accesser, 2);
    }

    if (touch) {
        work->setInt(0x11a, 0x20000008);
        speed.m_x *= -params->d;
        speed.m_y = params->e;
    } else if (grounded) {
        speed.m_y = fn_95_A8B4(speed.m_y * params->f);
        if (speed.m_y < params->g) {
            situation->setKind(0, false);
            ground->correct(1, 0);
            fn_95_10374(accesser);
            speed.m_y = 0.0f;

            if (fn_95_A8B4(speed.m_x) < 0.01f)
                speed.m_x = 0.01f * lr;

            value = controller->fn_95_175F4();
            if (fn_95_A8B4(value) > params->c) {
                if (value > 0.0f)
                    lr = 1.0f;
                else
                    lr = -1.0f;

                value = params->h * fn_95_A8B4(value);
                speed.m_x = value * lr;
                posture->setLr(lr);
                posture->updateRot();
            }
        } else {
            fn_95_10704(accesser);
            situation->setKind(2, false);
            ground->correct(5, 0);
        }

        work->setInt(0x119, 0x20000008);
        value = params->a;
        if (fn_95_10678(accesser))
            value *= params->b;
        speed.m_x = value * lr;
        work->setInt(0, 0x20000002);
    }

    work->setFloat(value, 0x21000006);

    void* stop = __dynamic_cast(
        kinetic->getEnergy(2), 0, lbl_95_data_81D8, lbl_95_data_2C38, 1);
    fn_95_DF08((char*)stop + 8, &Vec2f(speed.m_x, 0.0f));

    void* gravity = __dynamic_cast(
        kinetic->getEnergy(1), 0, lbl_95_data_810C, lbl_95_data_2C38, 1);
    *(float*)((char*)gravity + 0xc) = speed.m_y;
}
