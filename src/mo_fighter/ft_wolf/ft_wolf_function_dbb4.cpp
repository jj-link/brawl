#include <types.h>
#pragma force_active on

extern "C" {
s16* fn_125_DDF0(s16* destination, const s16* source);
void fn_125_E53C(s16* dest, const s16* src);
void fn_125_E4A4(void* object, const s16* operation, void* argument);
void fn_125_E3BC(void* object, const s16* operation, void* argument);
void fn_125_E2D4(void* object, const s16* operation, void* argument);
void fn_125_E1EC(void* object, const s16* operation, void* argument);
void fn_125_E104(unsigned char* self, short* src, void* arg);
void fn_125_E01C(unsigned char* obj, s16* src, void* arg);
void fn_125_DF34(unsigned char* obj, const s16* src, void* arg);
void fn_125_DE4C(unsigned char* obj, s16* src, void* arg);
}

extern "C" void fn_125_DBB4(s16* object, s16* argument, const s16* index) {
    s16 operation;
    s16 value = *index;
    s16 second, fourth, sixth, eighth;
    s16 seventh, fifth, third, first;
    unsigned char* composite = reinterpret_cast<unsigned char*>(object);

    fn_125_DDF0(&operation, &value);
    fn_125_E53C(&first, &operation);
    fn_125_E4A4(composite + 0x208, &first, argument);
    fn_125_E53C(&second, &operation);
    fn_125_E3BC(composite + 0x1CC, &second, argument);
    fn_125_E53C(&third, &operation);
    fn_125_E2D4(composite + 0x180, &third, argument);
    fn_125_E53C(&fourth, &operation);
    fn_125_E1EC(composite + 0x138, &fourth, argument);
    fn_125_E53C(&fifth, &operation);
    fn_125_E104(composite + 0xF0, &fifth, argument);
    fn_125_E53C(&sixth, &operation);
    fn_125_E01C(composite + 0x98, &sixth, argument);
    fn_125_E53C(&seventh, &operation);
    fn_125_DF34(composite + 0x64, &seventh, argument);
    fn_125_E53C(&eighth, &operation);
    fn_125_DE4C(composite + 8, &eighth, argument);
}