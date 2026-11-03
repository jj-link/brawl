#pragma force_active on
#define SLOT(n) virtual void slot##n() = 0
#define V(n) virtual void v##n() = 0;
#define V10(p) V(p##0) V(p##1) V(p##2) V(p##3) V(p##4) V(p##5) V(p##6) V(p##7) V(p##8) V(p##9)

struct Accesser;

struct Vec3 {
    float x, y, z;
};

struct Vec2 {
    union {
        unsigned long long bits;
        float values[2];
    };

    Vec2(unsigned long long value) {
        union {
            unsigned long long bits;
            unsigned int words[2];
        } temporary;
        temporary.bits = value;
        reinterpret_cast<unsigned int*>(this)[0] = temporary.words[0];
        reinterpret_cast<unsigned int*>(this)[1] = temporary.words[1];
    }
};

struct StatePrefix {
    unsigned int fields[2];
};

class State : public StatePrefix {
public:
    SLOT(08);
    SLOT(0C);
    SLOT(10);
    SLOT(14);
    SLOT(18);
    SLOT(1C);
    SLOT(20);
    SLOT(24);
    SLOT(28);
    SLOT(2C);
    virtual unsigned int slot30() = 0;
    SLOT(34);
    SLOT(38);
    virtual float slot3C() = 0;
};

class StateModule {
public:
    SLOT(08);
    SLOT(0C);
    SLOT(10);
    SLOT(14);
    SLOT(18);
    SLOT(1C);
    SLOT(20);
    SLOT(24);
    SLOT(28);
    SLOT(2C);
    SLOT(30);
    SLOT(34);
    SLOT(38);
    SLOT(3C);
    SLOT(40);
    SLOT(44);
    SLOT(48);
    SLOT(4C);
    SLOT(50);
    SLOT(54);
    SLOT(58);
    SLOT(5C);
    SLOT(60);
    SLOT(64);
    SLOT(68);
    SLOT(6C);
    SLOT(70);
    SLOT(74);
    virtual State* getState() = 0;
};

class WorkModule {
public:
    SLOT(08);
    SLOT(0C);
    SLOT(10);
    SLOT(14);
    virtual int slot18(int) = 0;
    virtual void slot1C(int, int) = 0;
    SLOT(20);
    virtual void slot24(int) = 0;
    SLOT(28);
    SLOT(2C);
    SLOT(30);
    SLOT(34);
    SLOT(38);
    SLOT(3C);
    SLOT(40);
    SLOT(44);
    SLOT(48);
    virtual unsigned int isFlag(int) = 0;
    virtual void onFlag(int) = 0;
    virtual void offFlag(int) = 0;
};

class KineticModule {
public:
    SLOT(08);
    SLOT(0C);
    SLOT(10);
    SLOT(14);
    SLOT(18);
    SLOT(1C);
    SLOT(20);
    SLOT(24);
    SLOT(28);
    SLOT(2C);
    SLOT(30);
    SLOT(34);
    SLOT(38);
    virtual unsigned long long getSpeed(short*) = 0;
};

class SituationModule {
public:
    SLOT(08);
    SLOT(0C);
    SLOT(10);
    virtual int getKind() = 0;
};

class StatusModule {
public:
    SLOT(08);
    SLOT(0C);
    SLOT(10);
    virtual void changeStatusRequest(int, Accesser*) = 0;
};

class PostureModule {
public:
    SLOT(08);
    SLOT(0C);
    SLOT(10);
    SLOT(14);
    virtual Vec3 slot18() = 0;
    SLOT(1C);
    SLOT(20);
    SLOT(24);
    SLOT(28);
    SLOT(2C);
    SLOT(30);
    SLOT(34);
    SLOT(38);
    SLOT(3C);
    SLOT(40);
    SLOT(44);
    SLOT(48);
    SLOT(4C);
    SLOT(50);
    SLOT(54);
    SLOT(58);
    SLOT(5C);
    virtual float slot60() = 0;
};

class Unk40Module {
public:
    SLOT(08);
    SLOT(0C);
    SLOT(10);
    SLOT(14);
    SLOT(18);
    virtual int slot1C() = 0;
};

struct Unk38Prefix {
    unsigned int fields[2];
};

class Unk38Module : public Unk38Prefix {
public:
    SLOT(08);
    SLOT(0C);
    SLOT(10);
    SLOT(14);
    SLOT(18);
    SLOT(1C);
    SLOT(20);
    SLOT(24);
    SLOT(28);
    SLOT(2C);
    SLOT(30);
    SLOT(34);
    SLOT(38);
    SLOT(3C);
    SLOT(40);
    SLOT(44);
    SLOT(48);
    SLOT(4C);
    SLOT(50);
    SLOT(54);
    SLOT(58);
    SLOT(5C);
    SLOT(60);
    SLOT(64);
    SLOT(68);
    virtual void slot6C(int) = 0;
};

class Unk60Module {
public:
    V10() V10(1) V10(2) V10(3) V(40) V(41) V(42)
    virtual int slot43(int) = 0;
};

struct Modules {
    unsigned char pad00[0x0C];
    PostureModule* unkC;
    unsigned char pad10[4];
    SituationModule* situation;
    unsigned char pad18[0x20];
    Unk38Module* unk38;
    unsigned char pad3C[4];
    Unk40Module* unk40;
    unsigned char pad44[0x1C];
    Unk60Module* unk60;
    WorkModule* work;
    unsigned char pad68[8];
    StatusModule* status;
    unsigned char pad74[8];
    KineticModule* kinetic;
    unsigned char pad80[0x10];
    StateModule* state;
};

struct Accesser {
    unsigned char pad00[0xD8];
    Modules* modules;
};

struct FtPrefix {
    unsigned int fields[15];
};

class FtObject : public FtPrefix {
public:
    V10() V10(1) V10(2) V10(3) V10(4) V10(5) V10(6) V10(7) V10(8) V10(9)
    V10(10) V10(11) V10(12) V10(13) V10(14) V10(15) V(160)
    unsigned char pad[0x20];
    Accesser* acc;
};

struct FtManager {
    unsigned char pad[0x70];
    int unk70;
};

extern "C" {
extern void* lbl_27_bss_F0;
extern const float lbl_27_rodata_1048;
extern FtManager* g_ftManager;
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* fn_27_5BCD0(void*);
unsigned int fn_27_5BEA8(void*);
void fn_27_5CA4(void*);
float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(void*, unsigned long, unsigned long);
}

extern "C" void fn_27_12F9C8(FtObject* object) {
    Accesser* acc = object->acc;

    fn_27_5CA4(object);

    if (lbl_27_bss_F0 == 0) {
        void* singleton = __nw__FUlQ25Heaps8HeapType(0x4C, 2);
        if (singleton != 0) {
            singleton = fn_27_5BCD0(singleton);
        }
        lbl_27_bss_F0 = singleton;
    }

    if (fn_27_5BEA8(lbl_27_bss_F0) == 1U) {
        if (acc->modules->work->isFlag(0x12000000) == 1U) {
            acc->modules->work->offFlag(0x12000000);
            object->v160();
        } else {
            short idx = -1;
            Vec2 speed(acc->modules->kinetic->getSpeed(&idx));

            if (speed.values[1] <= -getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(acc, 0xBD0, 0)) {
                acc->modules->work->slot24(0x1000000D);
            } else {
                acc->modules->work->slot1C(0, 0x1000000D);
            }

            if (acc->modules->state->getState()->slot30() == 1U) {
                if (acc->modules->situation->getKind() != 3) {
                    if (acc->modules->work->slot18(0x10000027) <= 0) {
                        if (acc->modules->work->isFlag(0x1200000B) == 0) {
                            if (acc->modules->work->isFlag(0x1200002F) == 0) {
                                if (acc->modules->work->isFlag(0x12000031) == 0) {
                                    if (acc->modules->unk40->slot1C() == 0) {
                                        const Vec3& pos = acc->modules->unkC->slot18();
                                        float f30 = acc->modules->state->getState()->slot3C();
                                        float f31 = acc->modules->unkC->slot60();
                                        float scale = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(acc, 0xBE4, 0);
                                        f31 = scale * f31;
                                        if (acc->modules->situation->getKind() == 0) {
                                            if (f30 >= pos.y + f31) {
                                                acc->modules->status->changeStatusRequest(0xB6, acc);
                                            }
                                        } else if (speed.values[1] < lbl_27_rodata_1048) {
                                            object->acc->modules->status->changeStatusRequest(0xB3, object->acc);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

        switch (g_ftManager->unk70) {
        case 0:
            if (object->acc->modules->unk60->slot43(1) == 0) {
                acc->modules->unk38->slot6C(1);
                acc->modules->work->onFlag(0x12000010);
            } else {
                acc->modules->unk38->slot6C(0);
                acc->modules->work->offFlag(0x12000010);
            }
            break;
        case -1: {
            unsigned int flag = 0x12000010;
            if (acc->modules->work->isFlag(flag) == 1U) {
                acc->modules->work->offFlag(flag);
                acc->modules->unk38->slot6C(0);
            }
            break;
        }
        default:
            break;
        }
    }
}
