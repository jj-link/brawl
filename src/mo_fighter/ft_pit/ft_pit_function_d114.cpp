#include <types.h>
#pragma force_active on
extern "C" {
void fn_112_D350(s16*, const s16*);
void fn_112_DA64(s16*, const s16*);
void fn_112_D9CC(void*, const s16*, void*);
void fn_112_D8E4(void*, const s16*, void*);
void fn_112_D7FC(void*, const s16*, void*);
void fn_112_D714(void*, const s16*, void*);
void fn_112_D62C(void*, const s16*, void*);
void fn_112_D544(void*, const s16*, void*);
void fn_112_D494(void*, const s16*, void*);
void fn_112_D3AC(void*, const s16*, void*);
}
extern "C" void fn_112_D114(unsigned char* object, void* argument, const s16* index) {
    s16 operation;
    s16 value = *index;
    s16 second, fourth, sixth, eighth;
    s16 seventh, fifth, third, first;
    fn_112_D350(&operation, &value);
    fn_112_DA64(&first, &operation);
    fn_112_D9CC(object + 0x208, &first, argument);
    fn_112_DA64(&second, &operation);
    fn_112_D8E4(object + 0x1CC, &second, argument);
    fn_112_DA64(&third, &operation);
    fn_112_D7FC(object + 0x180, &third, argument);
    fn_112_DA64(&fourth, &operation);
    fn_112_D714(object + 0x138, &fourth, argument);
    fn_112_DA64(&fifth, &operation);
    fn_112_D62C(object + 0xF0, &fifth, argument);
    fn_112_DA64(&sixth, &operation);
    fn_112_D544(object + 0x98, &sixth, argument);
    fn_112_DA64(&seventh, &operation);
    fn_112_D494(object + 0x64, &seventh, argument);
    fn_112_DA64(&eighth, &operation);
    fn_112_D3AC(object + 8, &eighth, argument);
}