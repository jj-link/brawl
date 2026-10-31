#include <types.h>
#pragma force_active on

struct InputHeader {
    u32 _0;
    u32 _4;
};

class Input : public InputHeader {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual u32 fetch(int*, unsigned int, void*);
};

struct ItemModuleHeader {
    u32 _0;
    u32 _4;
};

class ItemModule : public ItemModuleHeader {
public:
#define MODULE_SLOT(n) virtual void f##n();
    MODULE_SLOT(0) MODULE_SLOT(1) MODULE_SLOT(2) MODULE_SLOT(3)
    MODULE_SLOT(4) MODULE_SLOT(5) MODULE_SLOT(6) MODULE_SLOT(7)
    MODULE_SLOT(8) MODULE_SLOT(9) MODULE_SLOT(10) MODULE_SLOT(11)
    MODULE_SLOT(12) MODULE_SLOT(13) MODULE_SLOT(14) MODULE_SLOT(15)
    MODULE_SLOT(16) MODULE_SLOT(17) MODULE_SLOT(18) MODULE_SLOT(19)
    MODULE_SLOT(20) MODULE_SLOT(21) MODULE_SLOT(22) MODULE_SLOT(23)
    MODULE_SLOT(24) MODULE_SLOT(25) MODULE_SLOT(26) MODULE_SLOT(27)
    MODULE_SLOT(28) MODULE_SLOT(29) MODULE_SLOT(30) MODULE_SLOT(31)
    MODULE_SLOT(32) MODULE_SLOT(33) MODULE_SLOT(34) MODULE_SLOT(35)
    MODULE_SLOT(36) MODULE_SLOT(37) MODULE_SLOT(38) MODULE_SLOT(39)
    MODULE_SLOT(40) MODULE_SLOT(41) MODULE_SLOT(42) MODULE_SLOT(43)
    MODULE_SLOT(44) MODULE_SLOT(45) MODULE_SLOT(46) MODULE_SLOT(47)
    MODULE_SLOT(48) MODULE_SLOT(49) MODULE_SLOT(50) MODULE_SLOT(51)
    MODULE_SLOT(52) MODULE_SLOT(53) MODULE_SLOT(54) MODULE_SLOT(55)
    MODULE_SLOT(56) MODULE_SLOT(57) MODULE_SLOT(58) MODULE_SLOT(59)
    MODULE_SLOT(60) MODULE_SLOT(61) MODULE_SLOT(62) MODULE_SLOT(63)
    MODULE_SLOT(64) MODULE_SLOT(65) MODULE_SLOT(66) MODULE_SLOT(67)
    MODULE_SLOT(68) MODULE_SLOT(69) MODULE_SLOT(70) MODULE_SLOT(71)
    MODULE_SLOT(72) MODULE_SLOT(73) MODULE_SLOT(74) MODULE_SLOT(75)
    MODULE_SLOT(76) MODULE_SLOT(77) MODULE_SLOT(78) MODULE_SLOT(79)
    MODULE_SLOT(80) MODULE_SLOT(81) MODULE_SLOT(82) MODULE_SLOT(83)
    MODULE_SLOT(84) MODULE_SLOT(85) MODULE_SLOT(86) MODULE_SLOT(87)
    MODULE_SLOT(88) MODULE_SLOT(89) MODULE_SLOT(90) MODULE_SLOT(91)
    MODULE_SLOT(92) MODULE_SLOT(93) MODULE_SLOT(94) MODULE_SLOT(95)
    MODULE_SLOT(96) MODULE_SLOT(97) MODULE_SLOT(98) MODULE_SLOT(99)
    MODULE_SLOT(100) MODULE_SLOT(101) MODULE_SLOT(102) MODULE_SLOT(103)
    MODULE_SLOT(104) MODULE_SLOT(105) MODULE_SLOT(106) MODULE_SLOT(107)
    MODULE_SLOT(108) MODULE_SLOT(109) MODULE_SLOT(110) MODULE_SLOT(111)
    MODULE_SLOT(112) MODULE_SLOT(113) MODULE_SLOT(114) MODULE_SLOT(115)
    MODULE_SLOT(116) MODULE_SLOT(117) MODULE_SLOT(118) MODULE_SLOT(119)
#undef MODULE_SLOT
    virtual int test(void*, int);
};

struct Modules {
    char _pad[0x10];
    ItemModule* module;
    char _pad2[0x94];
    void* itemAction;
};

struct Context {
    char _pad[0xd8];
    Modules* modules;
};

class ItemAction {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual int f28(void*, int, int, int);
    virtual void f9();
    virtual int f30(void*);
    virtual int f34(void*, int);
};

extern "C" void* getInstance__9itManagerFv();
extern "C" void* fn_27_2A88C4(void*, u32);
extern "C" int getParam__8BaseItemFQ215itValueAccesser8ParamInt(void*, int);

extern "C" int fn_27_BE864(void*, Input* input, Context* context, int shift,
                            int mask, int selector, int extra) {
    int itemId;

    if (input->fetch(&itemId, 1u << shift, context) == 1u) {
        void* manager = getInstance__9itManagerFv();
        void* item = fn_27_2A88C4(manager, itemId);
        if (item != 0) {
            ItemModule* module = context->modules->module;
            if (module->test(item, 0) == 0) {
                int param = getParam__8BaseItemFQ215itValueAccesser8ParamInt(item, 0x5bce);
                if (param & mask) {
                    if (param & 0x20) {
                        switch (selector) {
                        case 0:
                            if (param & 0x2000)
                                return ((ItemAction*)context->modules->itemAction)->f28(item, extra, 0, 1);
                            return ((ItemAction*)context->modules->itemAction)->f30(item);
                        case 1:
                            return ((ItemAction*)context->modules->itemAction)->f30(item);
                        case 2:
                            return ((ItemAction*)context->modules->itemAction)->f28(item, extra, 0, 1);
                        }
                    } else {
                        if (param & 0x40)
                            return ((ItemAction*)context->modules->itemAction)->f34(item, 0);
                        return ((ItemAction*)context->modules->itemAction)->f28(item, extra, 0, 1);
                    }
                }
            }
        }
    }
    return 0;
}
