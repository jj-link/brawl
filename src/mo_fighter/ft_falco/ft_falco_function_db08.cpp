#include <types.h>
#pragma force_active on

extern "C" {
void fn_108_DD44(s16* destination, const s16* source);
void fn_108_E490(s16* destination, const s16* source);
void fn_108_E3F8(void* object, const s16* operation, void* argument);
void fn_108_E310(void* object, const s16* operation, void* argument);
void fn_108_E228(void* object, const s16* operation, void* argument);
void fn_108_E140(void* object, const s16* operation, void* argument);
void fn_108_E058(void* object, const s16* operation, void* argument);
void fn_108_DF70(void* object, const s16* operation, void* argument);
void fn_108_DE88(void* object, const s16* operation, void* argument);
void fn_108_DDA0(void* object, const s16* operation, void* argument);
}

extern "C" void fn_108_DB08(unsigned char* object, void* argument, const s16* index) {
    s16 operation;
    s16 value = *index;
    s16 second, fourth, sixth, eighth;
    s16 seventh, fifth, third, first;

    fn_108_DD44(&operation, &value);
    fn_108_E490(&first, &operation);
    fn_108_E3F8(object + 0x208, &first, argument);
    fn_108_E490(&second, &operation);
    fn_108_E310(object + 0x1CC, &second, argument);
    fn_108_E490(&third, &operation);
    fn_108_E228(object + 0x180, &third, argument);
    fn_108_E490(&fourth, &operation);
    fn_108_E140(object + 0x138, &fourth, argument);
    fn_108_E490(&fifth, &operation);
    fn_108_E058(object + 0xF0, &fifth, argument);
    fn_108_E490(&sixth, &operation);
    fn_108_DF70(object + 0x98, &sixth, argument);
    fn_108_E490(&seventh, &operation);
    fn_108_DE88(object + 0x64, &seventh, argument);
    fn_108_E490(&eighth, &operation);
    fn_108_DDA0(object + 0x8, &eighth, argument);
}
