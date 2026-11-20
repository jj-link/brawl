#pragma force_active on

#include <types.h>

#define D(n) virtual void d##n();

struct Vec2 {
    float x;
    float y;
    float z;
    Vec2(const Vec2&);
};

struct Vec3 {
    float x;
    float y;
    float z;
};

struct Status {
    D(2) D(3) D(4) D(5) D(6) D(7) D(8) D(9) D(10) D(11) D(12) D(13) D(14) D(15) D(16) D(17)
    virtual int s18();
};

struct Work {
    D(2) D(3) D(4) D(5)
    virtual int get(int);
    virtual void set(int, int);
    D(8) D(9) D(10)
    virtual void add(int, int);
    D(12) D(13) D(14) D(15) D(16) D(17) D(18) D(19)
    virtual void on(int);
    virtual void s21(int);
};

struct Ctl54 {
    D(2) D(3) D(4) D(5)
    virtual void s6(int, int);
    D(7) D(8) D(9)
    virtual void s10(int);
    D(11) D(12) D(13) D(14) D(15) D(16) D(17) D(18) D(19) D(20) D(21) D(22) D(23) D(24) D(25) D(26) D(27) D(28) D(29) D(30) D(31) D(32) D(33) D(34) D(35) D(36) D(37)
    virtual Vec2 s38(int, bool, bool);
};

struct Target {
    D(2) D(3) D(4) D(5) D(6) D(7) D(8) D(9) D(10) D(11) D(12) D(13) D(14) D(15) D(16) D(17) D(18) D(19) D(20) D(21) D(22) D(23) D(24) D(25) D(26) D(27) D(28) D(29) D(30) D(31) D(32) D(33) D(34) D(35)
    virtual int test(int);
};

struct Pad8 { char pad[8]; };
struct X : Pad8 {
    D(2) D(3) D(4) D(5) D(6) D(7) D(8) D(9) D(10) D(11)
    virtual void* call(u32, int, int);
};

struct Pad3C { char pad[0x3C]; };
struct Obj8 : Pad3C {
    D(2) D(3) D(4) D(5) D(6) D(7) D(8) D(9) D(10) D(11) D(12) D(13) D(14) D(15) D(16) D(17) D(18) D(19) D(20) D(21) D(22) D(23) D(24) D(25) D(26) D(27) D(28) D(29) D(30) D(31) D(32) D(33) D(34) D(35) D(36) D(37) D(38) D(39) D(40) D(41)
    virtual u32 call();
};

struct Modules {
    X* unk0;
    char pad4[0x50];
    Ctl54* unk54;
    char pad58[0xC];
    Work* unk64;
    char pad68[0x8];
    Status* unk70;
};

struct Fighter {
    char pad0[8];
    Obj8* unk8;
    char pad1[0xCC];
    Modules* modules;
};

struct Actor {
    char pad[0x60];
    Fighter* fighter;
};

struct ModAcc {
    char pad[0xD8];
    Modules* modules;
};

struct Event {
    char pad[0xC];
    u32 id;
};

struct Task {
    char pad[0x2C];
    u32 w;
};

struct Obj28 {
    char pad[0x28];
    s32 unk28;
};

extern "C" {
void* getInstance__15gfTaskSchedulerFv();
void* getTaskById__15gfTaskSchedulerFQ26gfTask8CategoryUl(void* sched, int cat, u32 id);
void* getTask__15gfTaskSchedulerFUl(void* sched, u32 id);
void* __dynamic_cast(void*, long, const void*, const void*, short);
Target* fn_27_14D490(void*);
u32 fn_27_1456CC(void*, u32);
s32 randi__Fl(s32);
double sin(double);
double cos(double);
void fn_106_77F4(Vec3* out, float x, float y, float z);
Obj28* fn_106_D500(void* data, u32 heap, s32 priority);
void fn_106_D9E0(void* obj, s32 arg);
void fn_106_DAC0(void* obj, s32 arg);
void fn_106_DAA8(void* obj, Vec2* vec, float f);
float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(void* acc, u32 a, u32 b);
extern char g_ftCommonDataAccesser[];
extern const char lbl_106_data_10BC[];
extern const char lbl_106_data_18F0[];
extern const float lbl_106_rodata_8;
extern const float lbl_106_rodata_C;
}

extern "C" void fn_106_741C(Actor* arg0, Event* arg1, ModAcc* arg2) {
    float temp_f30;
    float temp_f29;
    float temp_f31;
    float temp_f1;
    Vec3 sp14;
    s32 count;
    Obj28* obj;

    if (arg0->fighter->modules->unk70->s18() == 0x11E) {
        void* task = getTaskById__15gfTaskSchedulerFQ26gfTask8CategoryUl(getInstance__15gfTaskSchedulerFv(), 0xA, arg1->id);
        if (task != 0) {
            void* p = __dynamic_cast(task, 0x3C, lbl_106_data_10BC, lbl_106_data_18F0, 1);
            if (fn_27_14D490(p)->test(0) != 3) {
                arg0->fighter->modules->unk64->on(0x22000011);
            }
        }
    } else if (arg0->fighter->modules->unk70->s18() == 0x120) {
        void* task = getTask__15gfTaskSchedulerFUl(getInstance__15gfTaskSchedulerFv(), arg1->id);
        if (((s32)((((Task*)task)->w << 17) & 0xFF800000) >> 24) == 0xA) {
            void* p = __dynamic_cast(task, 0x3C, lbl_106_data_10BC, lbl_106_data_18F0, 1);
            if (fn_27_14D490(p)->test(0) == 0) {
                count = arg0->fighter->modules->unk64->get(0x20000016);
                if (count < 6) {
                    arg2->modules->unk54->s6(6, arg1->id);
                    Obj8* o8 = arg0->fighter->unk8;
                    u32 idx = o8->call();
                    u32 res = fn_27_1456CC(g_ftCommonDataAccesser, idx);
                    obj = fn_106_D500(arg0->fighter->modules->unk0->call(res, 0, -1), 0x1F, count + 1);
                    if (getTaskById__15gfTaskSchedulerFQ26gfTask8CategoryUl(getInstance__15gfTaskSchedulerFv(), 0xA, arg1->id) != 0) {
                        temp_f29 = randi__Fl(0x168);
                        temp_f31 = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(arg2, 0xFBE, 0);
                        temp_f30 = (float)sin(temp_f29);
                        float cosine = (float)cos(temp_f29);
                        fn_106_77F4(&sp14, temp_f31 * cosine, temp_f31 * temp_f30, lbl_106_rodata_8);
                        Vec2 sp8 = arg2->modules->unk54->s38(6, 0, 0);
                        float old = sp8.y;
                        sp8.y = old + lbl_106_rodata_C;
                        fn_106_DAA8(obj, &sp8, old);
                    }
                    fn_106_D9E0(obj, 0);
                    fn_106_DAC0(obj, 0);
                    arg0->fighter->modules->unk64->set(obj->unk28, count + 0x20000004);
                    arg0->fighter->modules->unk64->s21(0x22000012);
                    arg0->fighter->modules->unk64->add(1, 0x20000016);
                    arg2->modules->unk54->s10(6);
                }
                arg0->fighter->modules->unk64->on(0x22000012);
            }
        }
    }
}
