#pragma force_active on
typedef unsigned int u32;
typedef unsigned long long u64;

struct Vec3 {
    float x, y, z;
};

struct Vec2 {
    union {
        u64 bits;
        float values[2];
    };

    Vec2(u64 value) {
        union {
            u64 bits;
            u32 words[2];
        } temporary;
        temporary.bits = value;
        reinterpret_cast<u32*>(this)[0] = temporary.words[0];
        reinterpret_cast<u32*>(this)[1] = temporary.words[1];
    }
};

#define SLOT(n) virtual void slot##n() = 0

struct Accesser;

class StatusModule {
public:
    SLOT(08);
    SLOT(0C);
    SLOT(10);
    virtual void changeStatusRequest(int, Accesser*) = 0;
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
    virtual int getStatusKind() = 0;
};

struct PositionPrefix {
    u32 fields[2];
};

class PositionModule : public PositionPrefix {
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
    SLOT(78);
    SLOT(7C);
    SLOT(80);
    SLOT(84);
    SLOT(88);
    SLOT(8C);
    SLOT(90);
    SLOT(94);
    virtual Vec3 getPosition(int, int) = 0;
};

struct StatePrefix {
    u32 fields[2];
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
    SLOT(30);
    SLOT(34);
    SLOT(38);
    SLOT(3C);
    SLOT(40);
    virtual unsigned int testPosition(const Vec3&, int*) = 0;
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
    virtual bool isFlag(int) = 0;
    virtual void onFlag(int) = 0;
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
    virtual u64 getSpeed(short*) = 0;
};

class SituationModule {
public:
    SLOT(08);
    SLOT(0C);
    SLOT(10);
    virtual int getKind() = 0;
};

#undef SLOT

struct Modules {
    unsigned char pad00[4];
    PositionModule* position;
    unsigned char pad08[0xC];
    SituationModule* situation;
    unsigned char pad18[0x4C];
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

extern "C" {
extern void* lbl_27_bss_F0;
extern const float lbl_107_rodata_C;

void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* fn_27_5BCD0(void*);
unsigned int fn_27_5BE80(void*);
void fn_27_12F9C8(void*);
}

extern "C" void fn_107_AB50(void* object) {
    Accesser* accesser =
        *reinterpret_cast<Accesser**>(static_cast<unsigned char*>(object) + 0x60);

    if (lbl_27_bss_F0 == 0) {
        void* singleton = __nw__FUlQ25Heaps8HeapType(0x4C, 2);
        if (singleton != 0) {
            singleton = fn_27_5BCD0(singleton);
        }
        lbl_27_bss_F0 = singleton;
    }

    if (fn_27_5BE80(lbl_27_bss_F0) == 1) {
        int status = accesser->modules->status->getStatusKind();
        if (status >= 0x11D && status < 0x138) {
            const Vec3& position = accesser->modules->position->getPosition(14, 0);
            int result;

            if (accesser->modules->state->getState()->testPosition(position, &result) == 1) {
                if (!accesser->modules->work->isFlag(0x12000041)) {
                    short index = -1;
                    Vec2 speed(accesser->modules->kinetic->getSpeed(&index));

                    if (accesser->modules->situation->getKind() == 0) {
                        accesser->modules->status->changeStatusRequest(0x12F, accesser);
                        accesser->modules->work->onFlag(0x12000041);
                    } else if (speed.values[1] < lbl_107_rodata_C) {
                        accesser->modules->status->changeStatusRequest(0x12D, accesser);
                        accesser->modules->work->onFlag(0x12000041);
                    }
                }
            }
        }
    }

    fn_27_12F9C8(object);
}
