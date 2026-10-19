#include <types.h>
#pragma force_active on

extern "C" {
extern const float lbl_10_rodata_6A8;
void fn_10_1C97C(void*, u32, u32, void*);
}

struct CharSelectLocalVec {
    float m_x;
    float m_y;
    float m_z;
};

struct CharSelectObject {
    u8 data[0x1c8];
    u32 fieldA;
    u8 pad[0x30];
    void* fieldB;
};

extern "C" void fn_10_18A7C(CharSelectObject* object) {
    CharSelectLocalVec v;
    CharSelectLocalVec* p = &v;
    u32 a = object->fieldA;
    void* b = &object->fieldB;
    v.m_z = lbl_10_rodata_6A8;
    v.m_y = lbl_10_rodata_6A8;
    v.m_x = lbl_10_rodata_6A8;
    fn_10_1C97C(b, 0, a, p);
}
