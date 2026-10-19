#include <types.h>
#pragma force_active on

struct WordPair {
    u32 first;
    u32 second;
};

struct JungleData {
    float f00;
    float f04;
    float f08;
    float f0C;
    WordPair p10;
    u32 w18;
    u32 w1C;
    WordPair p20;
    u32 w28;
    u16 h2C;
    u16 h2E;
    u8 b30;
    u8 b31;
    u8 b32;
    u8 b33;
    u8 b34;
    u8 b35;
    u8 b36;
    u8 b37;
    u8 b38;
    u8 b39;
    u8 b3A;
    u32 w3C;
    WordPair p40;
    u32 w48;
    float f4C;
    u32 w50;
    u32 w54;
    u32 w58;
    u32 w5C;
    float f60;
    float f64;
    float f68;
    u32 w6C;
    u32 w70;
    u32 w74;
    u32 w78;
    float f7C;
    WordPair p80;
    u32 w88;
    WordPair p8C;
    float f94;
    u32 w98;
    u8 b9C;
};

struct JungleObject {
    virtual void slot00() = 0;
    virtual void slot01() = 0;
    virtual void slot02() = 0;
    virtual void slot03() = 0;
    virtual void slot04() = 0;
    virtual void slot05() = 0;
    virtual void slot06() = 0;
    virtual void slot07() = 0;
    virtual void slot08() = 0;
    virtual void slot09() = 0;
    virtual void slot10() = 0;
    virtual void slot11() = 0;
    virtual void slot12() = 0;
    virtual void slot13() = 0;
    virtual void slot14() = 0;
    virtual void slot15() = 0;
    virtual void slot16() = 0;
    virtual void slot17() = 0;
    virtual void slot18() = 0;
    virtual void slot19() = 0;
    virtual void slot20() = 0;
    virtual void slot21() = 0;
    virtual void slot22() = 0;
    virtual void slot23() = 0;
    virtual void slot24() = 0;
    virtual void slot25() = 0;
    virtual JungleData* lookup(void*) = 0;
};

extern "C" void fn_51_7574(JungleObject* self, void* first, void* second) {
    JungleData* source = self->lookup(first);
    JungleData* destination = self->lookup(second);
    *destination = *source;
}
