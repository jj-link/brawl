class Vec3f;
#include <types.h>
#include <snd/snd_3d_generator.h>
#include <ut/ut_list.h>
#pragma force_active on

extern "C" void fn_63_3488(void*);
extern "C" void __ct__14snd3DGeneratorFv(snd3DGenerator*);
extern "C" char lbl_63_data_1098[];
extern "C" const float lbl_63_rodata_50;
extern "C" const float lbl_63_rodata_54;

extern "C" void* fn_63_3B40(void* self) {
    char* p = (char*)self;
    s32 zero = 0;
    fn_63_3488(self);
    *(s32*)(p + 0x3c) = (s32)lbl_63_data_1098;
    __ct__14snd3DGeneratorFv((snd3DGenerator*)(p + 0x1c8));
    char* head = p + 0x1d4;
    f32 value2;
    f32 value1;
    value1 = lbl_63_rodata_50;
    value2 = lbl_63_rodata_54;
    utListNode* node = (utListNode*)(p + 0x1d4);
    node->m_next = 0;
    node->m_prev = 0;
    *(s32*)(p + 0x1d0) = zero;
    node->m_next = node;
    node->m_prev = node;
    *(float*)(p + 0x194) = value1;
    *(s32*)(p + 0x198) = zero;
    *(s32*)(p + 0x19c) = zero;
    *(s32*)(p + 0x1a0) = zero;
    *(s32*)(p + 0x1a4) = zero;
    *(char*)(p + 0x1a8) = zero;
    *(float*)(p + 0x1ac) = value2;
    *(s32*)(p + 0x1b0) = zero;
    *(s32*)(p + 0x1b4) = zero;
    *(char*)(p + 0x1b8) = zero;
    *(float*)(p + 0x1bc) = value2;
    *(s32*)(p + 0x1c0) = zero;
    *(s32*)(p + 0x1c4) = zero;
    return self;
}