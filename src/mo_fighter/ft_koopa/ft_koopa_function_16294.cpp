#pragma force_active on

#include <ft/ft_common_data_accesser.h>

struct KVec2 {
    float x, y;
};

struct KVec3 {
    float x, y, z;
};

struct KAccesser;

class KWork {
public:
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void setInt(int, int);
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
    virtual bool isFlag(unsigned int);
    virtual void v20();
    virtual void offFlag(unsigned int);
};

class KEnergy {
public:
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void resetEnergy(int, KVec2*, KVec3*, KAccesser*);

    unsigned char state;
    unsigned char flags;
    char pad0[10];
    float accel;
    float limit;
    KVec2 v18;
    char pad1[8];
    KVec2 v28;
    char pad2[12];
    float f3C;
};

class KKinetic {
public:
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual KEnergy* getEnergy(int);
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual KVec2 getSumSpeed(const unsigned short&);
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void unk5C(int, KAccesser*);
};

class KVisibility {
public:
    virtual void v2();
    virtual void v3();
    virtual void set(int, int);
};

class KAux {
public:
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
    virtual void unkAC(int, int);
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void unkCC(int, int);
};

struct KModules {
    char pad0[0x58];
    KVisibility* visibility;
    char pad1[8];
    KWork* work;
    char pad2[0x14];
    KKinetic* kinetic;
    char pad3[0x28];
    KAux* aux;
};

struct KAccesser {
    char pad[0xD8];
    KModules* modules;
};

struct KSpeedParam {
    float f0, f4, f8, fC, f10, f14, f18, f1C;
};

struct KFtData {
    char pad[0x84];
    KSpeedParam* speed;
};

extern "C" {
extern const char lbl_102_data_5E6C[];
extern const char lbl_102_data_5EBC[];
extern const char lbl_102_data_14F4[];
extern const float lbl_102_rodata_58;

void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_102_156C0(KAccesser*);
void fn_102_15788(KAccesser*);
void fn_102_B024(KVec2*, KVec2*);
void fn_102_C5AC(KVec2*, float, float);
KVec3* fn_102_C5B8(KVec3*, float, float, float);
}

extern "C" void fn_102_16294(void*, KAccesser* accesser) {
    KWork* work = accesser->modules->work;
    if (work->isFlag(0x1200003D)) {
        fn_102_15788(accesser);
        work->offFlag(0x1200003D);
    }

    KAux* aux = accesser->modules->aux;
    int notFlag = !work->isFlag(0x22000013);
    aux->unkAC(notFlag, 0);
    aux->unkCC(notFlag, 0xFF);
    work->setInt(0, 0x20000000);

    if (!work->isFlag(0x22000010)) {
        KSpeedParam* params = reinterpret_cast<KFtData*>(
            g_ftCommonDataAccesser.getData(static_cast<ftKind>(0x30)))->speed;
        unsigned short attr = 1;
        KVec2 speed;
        KVec2 tmp = accesser->modules->kinetic->getSumSpeed(attr);
        __memcpy(&speed, &tmp, sizeof(speed));
        fn_102_156C0(accesser);

        KEnergy* energy1 = (KEnergy*)__dynamic_cast(
            accesser->modules->kinetic->getEnergy(1), 0,
            lbl_102_data_5E6C, lbl_102_data_14F4, 1);
        float speedY = speed.y;
        KVec2 vert;
        vert.x = lbl_102_rodata_58;
        vert.y = speedY;
        KVec3 rot1;
        energy1->resetEnergy(0, &vert,
            fn_102_C5B8(&rot1, lbl_102_rodata_58, lbl_102_rodata_58, lbl_102_rodata_58),
            accesser);
        energy1->accel = -params->f8;
        energy1->limit = params->fC;
        energy1->v18.y = params->fC;
        energy1->flags |= 0x80;

        KEnergy* energy2 = (KEnergy*)__dynamic_cast(
            accesser->modules->kinetic->getEnergy(2), 0,
            lbl_102_data_5EBC, lbl_102_data_14F4, 1);
        KVec2 horiz;
        horiz.x = speed.x;
        horiz.y = lbl_102_rodata_58;
        KVec3 rot2;
        energy2->resetEnergy(0, &horiz,
            fn_102_C5B8(&rot2, lbl_102_rodata_58, lbl_102_rodata_58, lbl_102_rodata_58),
            accesser);
        energy2->f3C = params->f1C;
        KVec2 a;
        fn_102_C5AC(&a, params->f14, energy2->v18.y);
        fn_102_B024(&energy2->v18, &a);
        KVec2 b;
        fn_102_C5AC(&b, params->f14, energy2->v28.y);
        fn_102_B024(&energy2->v28, &b);
        energy2->flags |= 0x80;
    } else {
        accesser->modules->kinetic->unk5C(0, accesser);
    }

    if (work->isFlag(0x22000012)) {
        accesser->modules->visibility->set(1, 1);
    }
}
