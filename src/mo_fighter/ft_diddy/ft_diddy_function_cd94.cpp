#pragma force_active on
#include "types.h"

namespace {
struct DiddyTraversalIndex {
    s16 value;
};
}

extern "C" {
void fn_115_CFD0(s16* destination, const s16* source);
void fn_115_D71C(DiddyTraversalIndex* destination, const DiddyTraversalIndex* source);
void fn_115_D684(void* object, const DiddyTraversalIndex* source, void* argument);
void fn_115_D59C(void* object, const DiddyTraversalIndex* source, void* argument);
void fn_115_D4B4(void* object, const DiddyTraversalIndex* source, void* argument);
void fn_115_D3CC(void* object, const DiddyTraversalIndex* source, void* argument);
void fn_115_D2E4(void* object, const DiddyTraversalIndex* source, void* argument);
void fn_115_D1FC(void* object, const DiddyTraversalIndex* source, void* argument);
void fn_115_D114(void* object, const DiddyTraversalIndex* source, void* argument);
void fn_115_D02C(void* object, const DiddyTraversalIndex* source, void* argument);
}

extern "C" void fn_115_CD94(void* object, void* argument, const s16* index) {
    unsigned char* composite = static_cast<unsigned char*>(object);
    DiddyTraversalIndex operation;
    s16 value = *index;
    DiddyTraversalIndex second;
    DiddyTraversalIndex fourth;
    DiddyTraversalIndex sixth;
    DiddyTraversalIndex eighth;
    DiddyTraversalIndex seventh;
    DiddyTraversalIndex fifth;
    DiddyTraversalIndex third;
    DiddyTraversalIndex first;

    fn_115_CFD0(reinterpret_cast<s16*>(&operation), &value);
    fn_115_D71C(&first, &operation);
    fn_115_D684(composite + 0x208, &first, argument);
    fn_115_D71C(&second, &operation);
    fn_115_D59C(composite + 0x1CC, &second, argument);
    fn_115_D71C(&third, &operation);
    fn_115_D4B4(composite + 0x180, &third, argument);
    fn_115_D71C(&fourth, &operation);
    fn_115_D3CC(composite + 0x138, &fourth, argument);
    fn_115_D71C(&fifth, &operation);
    fn_115_D2E4(composite + 0xF0, &fifth, argument);
    fn_115_D71C(&sixth, &operation);
    fn_115_D1FC(composite + 0x98, &sixth, argument);
    fn_115_D71C(&seventh, &operation);
    fn_115_D114(composite + 0x64, &seventh, argument);
    fn_115_D71C(&eighth, &operation);
    fn_115_D02C(composite + 8, &eighth, argument);
}
