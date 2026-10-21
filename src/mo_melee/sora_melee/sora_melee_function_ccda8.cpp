#include <types.h>
#pragma force_active on

extern "C" {
extern const float lbl_27_rodata_F00;
extern char lbl_27_data_3418[];
void __ct__8clTargetFv(void*);
void __dt__8clTargetFv(void*, int);
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
}

class soCollisionAttackPart {
public:
    soCollisionAttackPart();

    char pad00[0x28];
    float x, y, z;
    char pad34[8];
    u32 unused3c : 27;
    u32 flags3c : 5;
    u32 pad40;
    void* vt44;
    void* vt48;
    u32 flags4c : 13;
    u32 unused4c : 19;
    char targets[0x38];
};

soCollisionAttackPart::soCollisionAttackPart() {
    x = lbl_27_rodata_F00;
    y = lbl_27_rodata_F00;
    z = lbl_27_rodata_F00;
    flags3c = 0;
    vt44 = lbl_27_data_3418;
    vt48 = lbl_27_data_3418 + 0x48;
    flags4c = 0;
    __construct_array(targets, (void (*)(void*))__ct__8clTargetFv,
                      (void (*)(void*))__dt__8clTargetFv, 8, 7);
}
