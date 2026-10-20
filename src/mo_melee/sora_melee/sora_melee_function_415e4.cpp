#include <types.h>
#pragma force_active on

extern "C" void __dt__8clTargetFv(void*, int);
extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);

class soCollisionHitPart {
public:
    u8 m_pad[0x28];
    void* m_unk28;
    u8 m_pad2[0x34 - 0x2C];
    u8 m_targets[6 * 8];
    ~soCollisionHitPart();
};

soCollisionHitPart::~soCollisionHitPart() {
    if (&m_unk28 != 0) {
        __destroy_arr(m_targets, __dt__8clTargetFv, 8, 6);
    }
}
