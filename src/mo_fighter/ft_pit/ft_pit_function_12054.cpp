#include <types.h>
#pragma force_active on

extern "C" {
void fn_112_12210(s16* destination, const s16* source);
void fn_112_125BC(s16* destination, const s16* source);
void fn_112_12524(void* object, const s16* index, void* argument);
void fn_112_1243C(void* object, const s16* index, void* argument);
void fn_112_12354(void* object, const s16* index, void* argument);
void fn_112_1226C(void* object, const s16* index, void* argument);
}

extern "C" void fn_112_12054(void* object, void* argument, const s16* index) {
    unsigned char* composite = static_cast<unsigned char*>(object);
    s16 operation;
    s16 value = *index;
    s16 second;
    s16 fourth;
    s16 third;
    s16 first;

    fn_112_12210(&operation, &value);
    fn_112_125BC(&first, &operation);
    fn_112_12524(composite + 0xF0, &first, argument);
    fn_112_125BC(&second, &operation);
    fn_112_1243C(composite + 0xAC, &second, argument);
    fn_112_125BC(&third, &operation);
    fn_112_12354(composite + 0x5C, &third, argument);
    fn_112_125BC(&fourth, &operation);
    fn_112_1226C(composite + 8, &fourth, argument);
}
