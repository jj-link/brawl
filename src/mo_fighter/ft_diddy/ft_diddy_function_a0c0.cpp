#include <stddef.h>
#pragma force_active on

typedef struct DiddyPairMember
{
    unsigned int storage[2];
} DiddyPairMember;

typedef struct DiddyPairArray
{
    unsigned int header;
    DiddyPairMember members[2];
} DiddyPairArray;

extern "C" DiddyPairMember* fn_115_A0C0(DiddyPairArray* array, int index)
{
    return &array->members[index];
}
