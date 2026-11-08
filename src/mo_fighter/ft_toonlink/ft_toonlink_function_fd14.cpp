#include <gf/gf_task_scheduler.h>
#include <so/model/so_model_module_simple.h>
#pragma force_active on

extern "C" {
extern const char lbl_121_data_3CF0[], lbl_121_data_3DF0[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_121_F12C(Vec3f*, const Vec3f*);
float fn_121_FEB4(const float*);
}

class Class_8E20 {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void fn_121_14828(unsigned long, unsigned long);
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual float fn_121_147F0(unsigned long);
    virtual void fn_121_147E8(float, unsigned long);
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void fn_121_147B0(unsigned long);
};

struct Pad8 { int a; int b; };
#define VS(n) virtual void s##n() = 0;
class Obj8 : public Pad8 {
public:
    VS(0) VS(1) VS(2) VS(3) VS(4) VS(5) VS(6) VS(7) VS(8) VS(9)
    VS(10) VS(11) VS(12) VS(13) VS(14) VS(15) VS(16) VS(17) VS(18) VS(19)
    VS(20) VS(21) VS(22) VS(23) VS(24) VS(25) VS(26) VS(27) VS(28) VS(29)
    VS(30) VS(31) VS(32) VS(33) VS(34) VS(35) VS(36) VS(37) VS(38) VS(39)
    VS(40) VS(41) VS(42) VS(43) VS(44) VS(45) VS(46) VS(47) VS(48) VS(49)
    VS(50) VS(51) VS(52) VS(53) VS(54) VS(55) VS(56) VS(57) VS(58) VS(59)
    VS(60) VS(61) VS(62) VS(63) VS(64) VS(65) VS(66) VS(67) VS(68) VS(69)
    VS(70) VS(71) VS(72) VS(73) VS(74) VS(75) VS(76) VS(77) VS(78) VS(79)
    VS(80) VS(81) VS(82) VS(83) VS(84) VS(85) VS(86) VS(87) VS(88) VS(89)
    VS(90) VS(91) VS(92) VS(93) VS(94) VS(95) VS(96) VS(97) VS(98) VS(99)
    VS(100) VS(101) VS(102) VS(103) VS(104) VS(105) VS(106) VS(107) VS(108) VS(109)
    VS(110) VS(111) VS(112) VS(113) VS(114) VS(115) VS(116) VS(117) VS(118) VS(119)
    virtual int s120(void*, int) = 0;
};

extern "C" void fn_121_FD14(char* sched, char* owner) {
    float sp8[2];
    float sp10[3];
    Class_8E20* obj30;
    soModelModule* obj31;
    void* cast;

    gfTask* task = gfTaskScheduler::getInstance()->getTaskById(
        (gfTask::Category)0xa, *(unsigned long*)(sched + 0xC));
    if (task == 0) {
        return;
    }
    cast = __dynamic_cast(task, 0x3c, lbl_121_data_3CF0, lbl_121_data_3DF0, 0);
    char* fdata = *(char**)(owner + 0xD8);
    obj30 = *(Class_8E20**)(fdata + 0x64);
    obj31 = *(soModelModule**)(fdata + 0x4);
    Vec3f sp1C = obj31->getNodeGlobalPosition(obj31->getCorrectNodeId(0x12c), false);
    fn_121_F12C((Vec3f*)sp10, &sp1C);
    sp8[0] = *(float*)(sched + 0x10) - sp10[0];
    float f1 = *(float*)(sched + 0x14);
    sp8[1] = f1 - sp10[1];
    float f31 = fn_121_FEB4(sp8);
    float limit = obj30->fn_121_147F0(0x21000004);
    if (f31 < limit) {
        Obj8* o = (Obj8*)*(void**)(*(char**)(owner + 0xD8) + 0x10);
        int r = o->s120(cast, 0);
        if (r == 0) {
            obj30->fn_121_14828(*(unsigned long*)(sched + 0xC), 0x20000003);
            obj30->fn_121_147E8(f31, 0x21000004);
            obj30->fn_121_147B0(0x22000019);
        }
    }
}
