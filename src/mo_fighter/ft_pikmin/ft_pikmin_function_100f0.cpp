#include <types.h>
#include <nw4r/math.h>
#pragma force_active on

class Object_vptr_0 {
public:
    virtual void fn_113_80F4();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual int fn_113_1BD80();
};
class Object_vptr_14 {
public:
    virtual void fn_113_80F4();
    virtual void slot_0xc();
    virtual void slot_0x10();
    virtual int slot_0x14();
};
extern f32 lbl_113_rodata_18;
enum Result { ZERO = 0, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN };
extern "C" Result fn_113_100F0(void* a, f32 farg0) {
    Object_vptr_0* status = *(Object_vptr_0**)((char*)*(void**)((char*)a + 0xd8) + 0x70);
    int kind = status->fn_113_1BD80();
    switch (kind) {
    case 0x27: case 0x29: case 0xa1:
        return TWO;
    case 0x7: case 0x8: case 0x2c: case 0x2f: case 0x32:
        return THREE;
    case 0x1: case 0x3: case 0x4: case 0x5: case 0xa: case 0x1f:
    case 0x20: case 0x26: case 0x52: case 0x8c: case 0x90:
    case 0x91: case 0xc5:
        return ONE;
    case 0xb: case 0xc: case 0xe: case 0xf: case 0x10: case 0x33:
    case 0x79: case 0x7a: case 0xac: case 0xc3: case 0xc4:
        return FOUR;
    case 0xb3: case 0xb4: case 0xbb: case 0xbc:
        return SIX;
    case 0xb6:
        return FIVE;
    case 0xb5: case 0xb7: case 0xb8: case 0xb9: case 0xba:
        return SEVEN;
    case 0x116: case 0x117: case 0x118: case 0x119: case 0x11a:
    case 0xdc: case 0xdd: case 0xde: case 0xed: case 0xef:
    case 0xf7: case 0xf8: case 0xf9: case 0x100: case 0x101:
        return TEN;
    case 0x45: case 0x49:
        return EIGHT;
    case 0x2: case 0x6: case 0xd: case 0x28:
    default: {
        unsigned int r0;
        switch (kind) {
        case 0x73: case 0x74: case 0x75: case 0x80: case 0x81:
        case 0x92: case 0x93: case 0x94: case 0xc0: case 0xc2:
            r0 = 1;
            break;
        default:
            r0 = 0;
            break;
        }
        if (r0 == 1) {
            return NINE;
        }
        break;
    }
    }
    Object_vptr_14* other = *(Object_vptr_14**)((char*)*(void**)((char*)a + 0xd8) + 0x14);
    if (other->slot_0x14() != 0) {
        return FOUR;
    }
    if ((float)(double)nw4r::math::FAbs(farg0) > lbl_113_rodata_18) {
        return ONE;
    }
    return ZERO;
}