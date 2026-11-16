#include <types.h>
#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#include <ft/ft_manager.h>
#pragma force_active on

#define V(n) virtual void f##n();
struct Event {
    s32 kind;
    u8 pad04;
    u8 flag05;
    u8 pad06[2];
    union { float x; s32 value; };
    union { float y; struct { u8 flagC; u8 padD[3]; }; };
    u8 pad10[0x10];
};
class SlotBase3 {
public:
     V(1) V(2) V(3)
};
class SlotBase4 : public SlotBase3 {
public:
    V(4)
};
class SlotBase13 : public SlotBase4 {
public:
    V(5) V(6) V(7) V(8) V(9) V(10) V(11) V(12)
    virtual float f13();
};
struct ModelBase8 { char pad00[8]; };
class ModelModule : public ModelBase8 {
public:
     V(1) V(2) V(3) V(4) V(5) V(6) V(7) V(8) V(9)
    V(10) V(11) V(12) V(13) V(14) V(15) V(16) V(17) V(18) V(19)
    V(20) V(21) V(22) V(23) V(24) V(25) V(26) V(27) V(28) V(29)
    V(30) V(31) V(32) V(33) V(34) V(35) V(36)
    virtual Vec3f f37(int, int);
};
struct U64Ret { s32 a; u32 b; };
class StatusModule : public SlotBase4 {
public:
    virtual int f5(int, int);
    V(6) V(7) V(8) V(9)
    virtual unsigned int f10(int);
    V(11) V(12) V(13) V(14) V(15) V(16) V(17) V(18) V(19) V(20)
    V(21) V(22) V(23) V(24) V(25) V(26) V(27) V(28) V(29) V(30)
    V(31) V(32) V(33) V(34) V(35) V(36) V(37) V(38) V(39) V(40)
    V(41) V(42) V(43) V(44) V(45) V(46) V(47) V(48) V(49) V(50)
    V(51) V(52)
    virtual unsigned int f53(int);
    virtual U64Ret f54(int);
    V(55) V(56) V(57) V(58) V(59) V(60) V(61) V(62) V(63) V(64)
    V(65) V(66) V(67) V(68) V(69) V(70) V(71) V(72) V(73) V(74)
    V(75) V(76) V(77) V(78) V(79) V(80) V(81) V(82) V(83) V(84)
    V(85) V(86) V(87)
    virtual void f88(int);
    virtual unsigned int f89();
    V(90) V(91) V(92) V(93) V(94) V(95) V(96) V(97) V(98) V(99)
    virtual void f100(int, int, int);
};
class MotionModule : public SlotBase3 {
public:
    virtual void f4(int, void*);
    V(5) V(6) V(7) V(8) V(9) V(10) V(11) V(12) V(13)
    V(14) V(15) V(16)
    virtual int f17();
};
class WorkModule : public SlotBase13 {
public:
    virtual void f14(float, unsigned long);
    V(15) V(16) V(17)
    virtual unsigned int f18(unsigned long);
    virtual void f19(unsigned long);
    virtual void f20(unsigned long);
};
class ActionModule : public SlotBase13 {
public:
    virtual float f14();
    V(15) V(16) V(17) V(18) V(19) V(20) V(21)
    virtual int f22();
    V(23) V(24) V(25) V(26) V(27) V(28) V(29) V(30)
    virtual void f31(void*);
};
class GroundModule : public SlotBase4 {
public:
    V(5)
    virtual void f6(void*);
    V(7) V(8) V(9)
    virtual float f10();
    V(11) V(12) V(13) V(14) V(15) V(16) V(17) V(18) V(19) V(20)
    V(21) V(22)
    virtual float f23();
};
class MiscModule : public SlotBase4 {
public:
    V(5) V(6)
    virtual void f7(int, u8);
};
class SpecialModule : public SlotBase4 {
public:
    V(5) V(6) V(7) V(8) V(9)
    virtual int f10(int, int, int);
    V(11) V(12) V(13) V(14) V(15) V(16) V(17) V(18)
    virtual unsigned int f19(int);
};
struct AccesserBase3c { char pad00[0x3c]; };
class AccesserModule : public AccesserBase3c {
public:
     V(1) V(2) V(3) V(4) V(5) V(6) V(7) V(8) V(9)
    V(10) V(11) V(12) V(13) V(14) V(15) V(16) V(17) V(18) V(19)
    V(20) V(21) V(22) V(23) V(24) V(25) V(26) V(27) V(28) V(29)
    V(30) V(31) V(32) V(33) V(34) V(35) V(36) V(37) V(38) V(39)
    V(40) V(41) V(42) V(43)
    V(44)
};
struct TransitionBase8 { char pad00[8]; };
class TransitionModule : public TransitionBase8 {
public:
     V(1) V(2) V(3) V(4) V(5) V(6) V(7) V(8) V(9)
    V(10) V(11) V(12) V(13) V(14) V(15) V(16) V(17) V(18) V(19)
    V(20) V(21) V(22) V(23) V(24) V(25) V(26) V(27) V(28) V(29)
    V(30) V(31) V(32) V(33) V(34) V(35) V(36) V(37) V(38) V(39)
    V(40) V(41) V(42) V(43) V(44) V(45) V(46) V(47) V(48) V(49)
    V(50) V(51) V(52) V(53) V(54) V(55) V(56) V(57) V(58) V(59)
    V(60) V(61) V(62) V(63) V(64) V(65) V(66) V(67) V(68) V(69)
    V(70) V(71) V(72) V(73) V(74) V(75) V(76) V(77) V(78) V(79)
    V(80) V(81) V(82) V(83) V(84) V(85) V(86) V(87) V(88) V(89)
    V(90) V(91) V(92) V(93) V(94) V(95) V(96) V(97) V(98) V(99)
    V(100) V(101) V(102) V(103) V(104) V(105) V(106) V(107)
    virtual void f108(void*, int);
    V(109) V(110) V(111)
    virtual float f112();
    virtual int f113(int);
};
struct ModuleSet {
    char pad00[4];
    ModelModule* model;
    ActionModule* action;
    GroundModule* ground;
    TransitionModule* motion;
    MiscModule* misc;
    char pad18[0x54 - 0x18];
    StatusModule* status;
    char pad58[0x64 - 0x58];
    WorkModule* work;
    char pad68[8];
    MotionModule* state;
    char pad74[0x84 - 0x74];
    SpecialModule* special;
};
struct Accesser {
    char pad00[8];
    AccesserModule* model;
    char pad0c[0xd8 - 0x0c];
    ModuleSet* modules;
};
struct IceFighter {
    char pad00[0xd8];
    ModuleSet* modules;
};
struct SelfBase { char pad00[0x28]; s32 taskId; char pad2c[0x10]; };
struct Self : SelfBase {
     V(1) V(2) V(3) V(4) V(5) V(6) V(7) V(8) V(9)
    V(10) V(11) V(12) V(13) V(14) V(15) V(16) V(17) V(18) V(19)
    V(20) V(21) V(22) V(23) V(24) V(25) V(26) V(27) V(28) V(29)
    V(30) V(31) V(32) V(33) V(34) V(35) V(36) V(37) V(38) V(39)
    virtual int f40();
    virtual int f41();
    virtual unsigned int f42();
    V(43) V(44) V(45) V(46) V(47) V(48) V(49) V(50) V(51) V(52)
    V(53) V(54) V(55) V(56) V(57) V(58) V(59) V(60) V(61) V(62)
    V(63) V(64) V(65) V(66) V(67) V(68) V(69) V(70) V(71) V(72)
    V(73) V(74) V(75) V(76) V(77) V(78) V(79) V(80) V(81) V(82)
    V(83) V(84) V(85) V(86) V(87) V(88) V(89) V(90) V(91) V(92)
    V(93) V(94) V(95) V(96) V(97) V(98) V(99) V(100) V(101) V(102)
    V(103) V(104) V(105) V(106) V(107) V(108) V(109) V(110) V(111)
    V(112) V(113) V(114) V(115) V(116) V(117) V(118) V(119) V(120)
    V(121) V(122) V(123) V(124) V(125) V(126) V(127) V(128) V(129)
    V(130) V(131) V(132) V(133) V(134) V(135) V(136) V(137) V(138)
    V(139) V(140) V(141) V(142) V(143) V(144) V(145) V(146) V(147)
    V(148) V(149) V(150) V(151) V(152)
    virtual int f153();
    V(154) V(155) V(156) V(157) V(158) V(159) V(160) V(161)
    V(162)
    char pad40[0x20];
    IceFighter* fighter;
    char pad64[0x1fe4c - 0x64];
    u8 partnerFlag;
};
struct IceBase3c { char pad00[0x28]; s32 taskId; char pad2c[0x10]; };
struct IceStageObject : IceBase3c {
     V(1) V(2) V(3) V(4) V(5) V(6) V(7) V(8) V(9)
    V(10) V(11) V(12) V(13) V(14) V(15) V(16) V(17) V(18) V(19)
    V(20) V(21) V(22) V(23) V(24) V(25) V(26) V(27) V(28) V(29)
    V(30) V(31) V(32) V(33) V(34) V(35) V(36) V(37) V(38) V(39)
    virtual int f40();
    virtual int f41();
    V(42)
};
#undef V
extern "C" void fn_27_1324D4(Self*, Event*, Accesser*, IceStageObject*, s32);
extern "C" void fn_27_12CF78(Self*, u32);
extern "C" void fn_27_12D904(Self*, bool, bool, int);
extern "C" void fn_105_13CC4(IceFighter*);
extern "C" void fn_105_BD50(void*, int, float, float, unsigned char, unsigned char, int, unsigned char);
extern "C" void fn_105_BD70(float*, float, float);
extern "C" void fn_105_D0E4();
extern "C" const float lbl_105_rodata_8;
extern "C" const float lbl_105_rodata_10;
extern ftManager* g_ftManager;

inline int getSelfEntry(int otherTask, const s32& selfTask, int& entry,
                        int* taskCopy = 0) {
    if (taskCopy)
        *taskCopy = otherTask;
    ftManager* manager = g_ftManager;
    int ownTask = selfTask;
    entry = manager->getEntryIdFromTaskId(otherTask, 0);
    return manager->getEntryIdFromTaskId(ownTask, 0);
}

enum WorkFlagId {
    WorkFlag10 = 0x22000010,
    WorkFlag11 = 0x22000011,
    WorkFlag12 = 0x22000012,
    WorkFlag14 = 0x22000014,
    WorkFlag15 = 0x22000015
};

struct BD50Data {
    int value;
    float first;
    float second;
    unsigned char flags[4];
};

extern "C" void fn_105_B138(Self* self, Event* event, Accesser* accesser,
                            IceStageObject* other, s32 value) {
    ftManager* manager;
    int selfTask;
    int id;
    int motion;
    switch (event->kind) {
    case 0x455: {
        U64Ret result;
        motion = event->value;
        if (accesser->modules->state->f17() == 0x10e) {
            if (accesser->modules->status->f89() == 1U) {
                Vec3f position = accesser->modules->model->f37(2, 0);
                accesser->modules->status->f88(1);
                accesser->model->f44();
                position.m_z = accesser->modules->motion->f112();
                accesser->modules->ground->f6(&position);
                accesser->modules->status->f100(6, 0xd, 1);
            }
            if (motion == 0) {
                if (accesser->modules->motion->f113(0) == 0) {
                    accesser->modules->misc->f7(2, 0);
                    motion = 0xe;
                }
            }
            if (self->f153() != 0) {
                if (accesser->modules->status->f10(6) == 1U) {
                    if (self->fighter->modules->status->f53(6) == 1U) {
                        result = self->fighter->modules->status->f54(6);
                        self->fighter->modules->motion->f108(&result, 0);
                    }
                }
            }
        }
        if (motion == 0x10b) {
            fn_27_12CF78(self, 1);
        } else {
            self->fighter->modules->state->f4(motion, self->fighter);
        }
        break;
    }
    case 0x456: {
        if (self->fighter->modules->work->f18(0x1200003e) == 0)
            return;
        float frame = lbl_105_rodata_10;
        if (event->flagC == 1)
            frame = self->fighter->modules->action->f13();
        BD50Data data;
        fn_105_BD50(&data, event->value, frame, lbl_105_rodata_8, 0, 0,
                    event->flagC, 0);
        self->fighter->modules->action->f31(&data);
        break;
    }
    case 0x457: {
        if (self->fighter->modules->work->f18(0x1200003e) == 0)
            return;
        if (self->fighter->modules->state->f17() == 0x117) {
            id = 0x1d6;
            if (event->value != 0)
                id = 0x1d7;
            float frame = self->fighter->modules->action->f13();
            BD50Data data;
            fn_105_BD50(&data, id, frame, lbl_105_rodata_8, 0, 0, 1, 0);
            self->fighter->modules->action->f31(&data);
        } else {
            self->fighter->modules->misc->f7(event->value, event->flagC);
        }
        break;
    }
    case 0x458: {
        if (self->fighter->modules->state->f17() == 0x117 ||
            self->fighter->modules->state->f17() == 0x113) {
            if (self->fighter->modules->work->f18(0x1200003e) == 1U)
                fn_105_13CC4(self->fighter);
            if ((self->fighter->modules->action->f22() == 0x1d3 ||
                 self->fighter->modules->action->f22() == 0x1d6) &&
                self->fighter->modules->motion->f113(0) == 1U) {
                int zero = 0;
                self->fighter->modules->misc->f7(zero, zero);
                self->fighter->modules->state->f4(0, self->fighter);
            } else {
                self->fighter->modules->misc->f7(2, 0);
                self->fighter->modules->state->f4(0x10, self->fighter);
            }
        }
        break;
    }
    case 0x459: {
        int sign = self->fighter->modules->ground->f10() < lbl_105_rodata_10 ? -1 : 1;
        float vertical;
        float direction = (float)sign;
        vertical = soValueAccesser::getConstantFloat(
            reinterpret_cast<soModuleAccesser*>(accesser), 0xfcd, 0);
        float horizontal = soValueAccesser::getConstantFloat(
            reinterpret_cast<soModuleAccesser*>(accesser), 0xfcc, 0);
        horizontal *= direction;
        float velocity[2];
        fn_105_BD70(velocity, horizontal, vertical);
        float scale = self->fighter->modules->ground->f23();
        if (scale < lbl_105_rodata_8) {
            velocity[0] *= scale;
            velocity[1] *= scale;
        }
        if (self->fighter->modules->work->f18(0x1200003e) == 1U &&
            self->fighter->modules->state->f17() == 0x11d) {
            self->fighter->modules->work->f14(velocity[0] + event->x, 0x21000004);
            self->fighter->modules->work->f14(velocity[1] + event->y, 0x21000005);
        } else if (self->fighter->modules->work->f18(0x1200003e) == 0 &&
                   self->fighter->modules->state->f17() == 0x11f) {
            self->fighter->modules->work->f14(velocity[0] + event->x, 0x21000004);
            self->fighter->modules->work->f14(velocity[1] + event->y, 0x21000005);
        }
        break;
    }
    case 0x3b: {
        if (value != 6 || other->f40() != 0 || other->f41() != 0xf ||
            self->partnerFlag != 0)
            break;
        int entry;
        int selfEntry = getSelfEntry(other->taskId, self->taskId, entry);
        if (selfEntry == entry &&
            self->fighter->modules->status->f5(6, other->taskId) == 0)
            return;
        break;
    }
    case 0x45a:
        if (self->partnerFlag == 0 &&
            self->fighter->modules->state->f17() == 0x119)
            self->fighter->modules->work->f19(0x22000012);
        break;
    case 0x45b:
        if (self->partnerFlag == 1 &&
            self->fighter->modules->state->f17() == 0x120)
            self->fighter->modules->work->f19(0x22000010);
        break;
    case 0x45c:
        self->fighter->modules->work->f20(0x1200003f);
        fn_27_12D904(self, true, true, 0);
        break;
    case 0x45d:
        if (self->fighter->modules->special->f19(3) == 1)
            self->fighter->modules->special->f10(3, 3, 0);
        break;
    case 0x45e:
        fn_105_D0E4();
        fn_27_12CF78(self, 1);
        break;
    case 0x462: {
        if (self->fighter->modules->work->f18(0x1200003e) == 0)
            return;
        switch (self->fighter->modules->state->f17()) {
        case 0x117: {
            WorkFlagId flag = event->flag05 ? WorkFlag10 : WorkFlag11;
            self->fighter->modules->work->f19(flag);
            break;
        }
        case 0x120: {
            WorkFlagId flag = event->flag05 ? WorkFlag11 : WorkFlag12;
            self->fighter->modules->work->f19(flag);
            break;
        }
        case 0x11a: {
            WorkFlagId flag = event->flag05 ? WorkFlag14 : WorkFlag15;
            self->fighter->modules->work->f19(flag);
            break;
        }
        }
        break;
    }
    case 0x461:
        if (self->fighter->modules->work->f18(0x1200003e) == 1U &&
            self->f42() == 1U &&
            self->fighter->modules->work->f18(0x12000018) == 0)
            self->f162();
        break;
    }
    fn_27_1324D4(self, event, accesser, other, value);
}
