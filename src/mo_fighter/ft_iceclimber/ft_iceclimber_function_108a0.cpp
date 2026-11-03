#include <types.h>
#pragma force_active on

extern "C" {
s16* fn_105_10DB4(s16* destination, const s16* source);
s16* fn_105_12C6C(s16* dst, const s16* src);
void fn_105_12BD4(void* object, const s16* operation, void* argument);
void fn_105_127F8(void* object, const s16* operation, void* argument);
void fn_105_1241C(void* object, const s16* operation, void* argument);
void fn_105_12040(void* object, const s16* operation, void* argument);
void fn_105_11C64(void* object, const s16* operation, void* argument);
void fn_105_118A0(void* object, const s16* operation, void* argument);
void fn_105_114D4(void* object, const s16* operation, void* argument);
void fn_105_11104(void* object, const s16* operation, void* argument);
}

extern "C" void fn_105_108A0(unsigned char* object, void* argument, const s16* index) {
    s16 operation;
    s16 value = *index;
    s16 second;
    s16 fourth;
    s16 sixth;
    s16 eighth;
    s16 seventh;
    s16 fifth;
    s16 third;
    s16 first;

    fn_105_10DB4(&operation, &value);
    fn_105_12C6C(&first, &operation);
    fn_105_12BD4(object + 0x208, &first, argument);
    fn_105_12C6C(&second, &operation);
    fn_105_127F8(object + 0x1CC, &second, argument);
    fn_105_12C6C(&third, &operation);
    fn_105_1241C(object + 0x180, &third, argument);
    fn_105_12C6C(&fourth, &operation);
    fn_105_12040(object + 0x138, &fourth, argument);
    fn_105_12C6C(&fifth, &operation);
    fn_105_11C64(object + 0xF0, &fifth, argument);
    fn_105_12C6C(&sixth, &operation);
    fn_105_118A0(object + 0x98, &sixth, argument);
    fn_105_12C6C(&seventh, &operation);
    fn_105_114D4(object + 0x64, &seventh, argument);
    fn_105_12C6C(&eighth, &operation);
    fn_105_11104(object + 8, &eighth, argument);
}
