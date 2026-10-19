#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#pragma force_active on

extern "C" float randf__Fv();

struct CaptainFinalPacket {
    int power;
    int value;
    int reactionEffect;
    int reactionFix;
    int reactionAdd;
    float slipChance;
    float hitStopFrame;
    float hitStopDelay;
    union {
        unsigned int raw;
        struct {
            unsigned int category : 5;
            unsigned int attributeHi : 2;
            unsigned int attributeLo : 5;
            unsigned int fixedBits : 3;
            unsigned int optionBit7 : 1;
            unsigned int optionBit6 : 1;
            unsigned int optionLo : 5;
            unsigned int : 10;
        } bits;
    };
};

struct CaptainFinalAttackDataView {
    int power;
    unsigned int offsetPosition[3];
    float size;
    int vector;
    int reactionEffect;
    int reactionFix;
    int reactionAdd;
    float slipChance;
    float hitStopFrame;
    float hitStopDelay;
    unsigned int category;
    unsigned int attribute;
    unsigned int options;
    unsigned int region;
};

class CaptainPostureVtbl {
public:
    virtual void slot00() = 0;
    virtual void slot04() = 0;
    virtual void slot08() = 0;
    virtual void slot0C() = 0;
    virtual void slot10() = 0;
    virtual void slot14() = 0;
    virtual void slot18() = 0;
    virtual void slot1C() = 0;
    virtual void slot20() = 0;
    virtual void slot2C() = 0;
};

class CaptainAttackVtbl {
public:
    virtual void slot00() = 0;
    virtual void slot04() = 0;
    virtual void slot08() = 0;
    virtual void slot0C() = 0;
    virtual void slot18() = 0;
    virtual void slot1C() = 0;
    virtual void slot20() = 0;
    virtual void slot24() = 0;
    virtual void slot28() = 0;
    virtual void slot2C(int, int, CaptainFinalPacket* packet) = 0;
};

extern "C" {
extern CaptainFinalAttackDataView lbl_100_bss_278;
extern const float lbl_100_rodata_74;
}

extern "C" void fn_100_1084C(soModuleAccesser* accesser) {
    CaptainAttackVtbl* attack = reinterpret_cast<CaptainAttackVtbl*>(
        accesser->m_enumerationStart->m_collisionAttackModule);
    CaptainFinalPacket packet;
    packet.slipChance = lbl_100_rodata_74;
    packet.hitStopFrame = lbl_100_rodata_74;
    packet.hitStopDelay = lbl_100_rodata_74;
    packet.raw &= 0xFFFF81FFu;
    reinterpret_cast<CaptainPostureVtbl*>(accesser->m_enumerationStart->m_postureModule)->slot2C();
    float low = soValueAccesser::getConstantFloat(accesser, 0xfba, 0);
    float high = soValueAccesser::getConstantFloat(accesser, 0xfbb, 0);
    float value = low + (high - low) * randf__Fv();
    packet.power = lbl_100_bss_278.power;
    packet.value = static_cast<int>(value);
    packet.reactionEffect = lbl_100_bss_278.reactionEffect;
    packet.reactionFix = lbl_100_bss_278.reactionFix;
    packet.reactionAdd = lbl_100_bss_278.reactionAdd;
    packet.slipChance = lbl_100_bss_278.slipChance;
    packet.hitStopFrame = lbl_100_bss_278.hitStopFrame;
    packet.hitStopDelay = lbl_100_bss_278.hitStopDelay;
    packet.bits.category = lbl_100_bss_278.category;
    packet.bits.attributeHi = lbl_100_bss_278.attribute >> 30;
    packet.bits.attributeLo = lbl_100_bss_278.attribute >> 25;
    packet.bits.fixedBits = 3;
    packet.bits.optionBit7 = lbl_100_bss_278.options >> 7;
    packet.bits.optionBit6 = lbl_100_bss_278.options >> 6;
    packet.bits.optionLo = lbl_100_bss_278.options;
    attack->slot18();
    attack->slot2C(0, 0, &packet);
}
