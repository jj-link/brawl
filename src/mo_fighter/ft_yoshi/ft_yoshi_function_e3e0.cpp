#include <types.h>
#pragma force_active on

namespace {
struct YoshiTraversalIndex {
    s16 value;
};
}

extern "C" {
void fn_95_E61C(s16* destination, const s16* source);
void fn_95_ED68(YoshiTraversalIndex* destination, const YoshiTraversalIndex* source);
void fn_95_ECD0(void* object, const YoshiTraversalIndex* operation, void* argument);
void fn_95_EBE8(void* object, const YoshiTraversalIndex* operation, void* argument);
void fn_95_EB00(void* object, const YoshiTraversalIndex* operation, void* argument);
void fn_95_EA18(void* object, const YoshiTraversalIndex* operation, void* argument);
void fn_95_E930(void* object, const YoshiTraversalIndex* operation, void* argument);
void fn_95_E848(void* object, const YoshiTraversalIndex* operation, void* argument);
void fn_95_E760(void* object, const YoshiTraversalIndex* operation, void* argument);
void fn_95_E678(void* object, const YoshiTraversalIndex* operation, void* argument);
}

extern "C" void fn_95_E3E0(void* object, void* argument, const s16* index) {
    YoshiTraversalIndex operation;
    s16 value = *index;
    YoshiTraversalIndex third, fourth, sixth, second;
    YoshiTraversalIndex eighth, seventh, fifth, first;

    fn_95_E61C(&operation.value, &value);
    fn_95_ED68(&first, &operation);
    fn_95_ECD0(static_cast<unsigned char*>(object) + 0x208, &first, argument);
    fn_95_ED68(&third, &operation);
    fn_95_EBE8(static_cast<unsigned char*>(object) + 0x1CC, &third, argument);
    fn_95_ED68(&fifth, &operation);
    fn_95_EB00(static_cast<unsigned char*>(object) + 0x180, &fifth, argument);
    fn_95_ED68(&fourth, &operation);
    fn_95_EA18(static_cast<unsigned char*>(object) + 0x138, &fourth, argument);
    fn_95_ED68(&seventh, &operation);
    fn_95_E930(static_cast<unsigned char*>(object) + 0xF0, &seventh, argument);
    fn_95_ED68(&sixth, &operation);
    fn_95_E848(static_cast<unsigned char*>(object) + 0x98, &sixth, argument);
    fn_95_ED68(&eighth, &operation);
    fn_95_E760(static_cast<unsigned char*>(object) + 0x64, &eighth, argument);
    fn_95_ED68(&second, &operation);
    fn_95_E678(static_cast<unsigned char*>(object) + 0x8, &second, argument);
}
