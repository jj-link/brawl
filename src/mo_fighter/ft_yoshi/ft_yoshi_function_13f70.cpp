#include <mt/mt_vector.h>
#pragma force_active on

extern "C" {
extern const unsigned char lbl_95_data_810C[];
extern const unsigned char lbl_95_data_81D8[];
extern const unsigned char lbl_95_data_2C38[];
extern const float lbl_95_rodata_110;

void* __dynamic_cast(void*, long, const void*, const void*, short);
float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
    void*, unsigned long, unsigned long);
void fn_95_11ADC(void*, const Vec2f*);
}

struct Energy {
    virtual void v0();
    virtual void v1();
    virtual Vec2f getSpeed();
    char pad[2];
    bool flag;
    char pad7;
    float speedX;
    float speedY;
};

struct Kinetic {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void* getEnergy(int);
};

struct Situation {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int getKind();
};

struct Controller {
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
    virtual float getStickY();
};

struct GroundBase {
    unsigned int a, b;
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
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void ignoreTouchLine(int, unsigned int);
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual void v76();
    virtual void v77();
    virtual void v78();
    virtual void v79();
    virtual void v80();
    virtual void v81();
    virtual void v82();
    virtual void v83();
    virtual void v84();
    virtual void v85();
    virtual void v86();
    virtual void v87();
    virtual void v88();
    virtual void v89();
    virtual void v90();
    virtual void v91();
    virtual void v92();
    virtual void v93();
    virtual void v94();
    virtual void v95();
    virtual void v96();
    virtual void v97();
    virtual void v98();
    virtual void v99();
    virtual void v100();
    virtual void v101();
    virtual void v102();
    virtual void v103();
    virtual void v104();
    virtual void v105();
    virtual void v106();
    virtual void v107();
    virtual void v108();
    virtual bool isPassableGround(unsigned int);
};

struct Modules {
    char pad0[0x10];
    Ground* ground;
    Situation* situation;
    char pad18[0x44];
    Controller* controller;
    char pad60[0x1c];
    Kinetic* kinetic;
};

struct Accesser {
    char pad[0xd8];
    Modules* modules;
};

extern "C" void fn_95_13F70(void*, Accesser* accesser) {
    Modules* modules = accesser->modules;
    Controller* controller = modules->controller;
    Situation* situation = modules->situation;
    Kinetic* kinetic = modules->kinetic;
    Ground* ground = modules->ground;

    Energy* first = static_cast<Energy*>(__dynamic_cast(
        kinetic->getEnergy(1), 0,
        lbl_95_data_810C, lbl_95_data_2C38, 1));
    Energy* second = static_cast<Energy*>(__dynamic_cast(
        kinetic->getEnergy(2), 0,
        lbl_95_data_81D8, lbl_95_data_2C38, 1));

    Vec2f speed1;
    Vec2f::copy(speed1, first->getSpeed());
    Vec2f speed2;
    Vec2f::copy(speed2, second->getSpeed());

    if (situation->getKind() == 0) {
        if (ground->isPassableGround(0) &&
            controller->getStickY() <
                getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
                    accesser, 0xc5f, 0)) {
            ground->ignoreTouchLine(8, 0);
            first->flag = false;
        } else {
            if (speed2.m_y < lbl_95_rodata_110)
                speed2.m_y = lbl_95_rodata_110;
            if (speed1.m_y < lbl_95_rodata_110)
                speed1.m_y = lbl_95_rodata_110;
            first->flag = true;
        }
    } else {
        first->flag = false;
    }

    first->speedY = speed1.m_y;
    fn_95_11ADC(second, &speed2);
}
