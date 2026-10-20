#include <types.h>
#pragma force_active on

extern "C" {
void __ct__8clTargetFv(void*);
void __dt__8clTargetFv(void*, int);
extern char lbl_27_data_3AD8[];
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
}

class soCollisionHitPart {
public:
    soCollisionHitPart();
    char m_pad[0x28];
    void* m_vt0;
    void* m_vt1;
    u32 m_flags;
    char m_targets[0x30];
};

soCollisionHitPart::soCollisionHitPart() {
    m_vt0 = lbl_27_data_3AD8;
    m_vt1 = lbl_27_data_3AD8 + 0x48;
    m_flags &= 0x7FFFF;
    __construct_array(m_targets, (void (*)(void*))__ct__8clTargetFv, (void (*)(void*))__dt__8clTargetFv, 8, 6);
}
