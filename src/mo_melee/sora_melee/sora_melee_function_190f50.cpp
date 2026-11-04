#include <gf/gf_task.h>
#pragma force_active on

struct Accesser;
struct MotionRequest {
    int kind;
    float start;
    float end;
    unsigned char a, b, c, d;
    MotionRequest(int k) : kind(k), start(lbl()), end(lbl()), a(0), b(0), c(0), d(0) {}
    static float lbl();
};

class soNullable {
public:
    virtual void isNull();
    virtual void slot1();
    virtual void slot2();
    virtual int slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7(bool);
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18(unsigned int);
    virtual void slot19(unsigned int);
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30(MotionRequest*);
    virtual void slot31();
    virtual void slot32();
    virtual void slot33(bool);
};
class Class_1250 {
public:
    virtual void fn_27_13C90();
    virtual void fn_27_14068();
    virtual void fn_27_140C0();
    virtual void fn_27_1412C(int, Accesser*);
    virtual void fn_27_14134();
    virtual void fn_27_14370();
    virtual void fn_27_14A28();
    virtual void fn_27_14A30();
    virtual void fn_27_14A38();
    virtual void fn_27_14A48();
    virtual void fn_27_14A68();
    virtual void fn_27_14AD8();
    virtual void fn_27_14A60();
    virtual void fn_27_14D08();
    virtual void fn_27_14EDC();
    virtual void fn_27_14D00();
    virtual int fn_27_14B80();
    virtual void fn_27_14B88();
    virtual void fn_27_16A70();
    virtual void fn_27_16AB8();
    virtual void fn_27_1CBB4();
    virtual void fn_27_14A20();
    virtual void fn_27_1CBAC();
    virtual void fn_27_1CBA4();
    virtual void fn_27_14B98();
    virtual void fn_27_14B90();
    virtual void fn_27_1CB88();
    virtual void fn_27_14CF8();
    virtual void fn_27_16778();
    virtual void fn_27_1688C();
    virtual void fn_27_1C2E4();
    virtual void fn_27_1BC08();
    virtual void fn_27_1BCF0();
    virtual void fn_27_16AE0();
};
struct Modules {
    unsigned char p0[8];
    soNullable* motion;
    unsigned char pC[8];
    soNullable* ground;
    unsigned char p18[0x40];
    soNullable* hit;
    unsigned char p5C[8];
    soNullable* work;
    unsigned char p68[8];
    Class_1250* status;
    unsigned char p74[0x14];
    soNullable* stop;
};
struct Accesser {
    unsigned char p0[8];
    void* owner;
    unsigned char pC[0xCC];
    Modules* modules;
};
struct Event {
    unsigned char p0[8];
    int kind;
};
extern const char lbl_27_data_69C0[];
extern const char lbl_27_data_248[];
extern float lbl_27_rodata_2658;
inline float MotionRequest::lbl() { return lbl_27_rodata_2658; }
extern "C" gfTask* __dynamic_cast(void*, long, const void*, const void*, long);
extern "C" void fn_27_190F50(Event* event, Accesser* accesser) {
    soNullable* work = accesser->modules->work;
    Class_1250* status = accesser->modules->status;
    int ground = accesser->modules->ground->slot3();
    soNullable* hit = accesser->modules->hit;
    gfTask* task = __dynamic_cast(accesser->owner, 0x3c, lbl_27_data_69C0, lbl_27_data_248, 1);
    switch (event->kind) {
    case 10:
        if (ground == 5) {
            task->setPaused(true);
            break;
        }
        switch (status->fn_27_14B80()) {
        case 0xD2:
        case 0xD3: {
            MotionRequest request(0xA1);
            accesser->modules->motion->slot30(&request);
            break;
        }
        }
        status->fn_27_1412C(0xFB, accesser);
        break;
    case 11:
        if (status->fn_27_14B80() == 0xFB) {
            accesser->modules->stop->slot33(false);
            hit->slot7(false);
            work->slot19(0x12000019);
            work->slot19(0x22000011);
        }
        break;
    case 12:
        if (status->fn_27_14B80() == 0xFB) {
            accesser->modules->stop->slot33(true);
            hit->slot7(true);
            work->slot18(0x12000019);
            work->slot18(0x22000011);
        }
        break;
    case 13:
        work->slot19(0x22000010);
        break;
    case 14:
        task->setPaused(false);
        break;
    }
}
