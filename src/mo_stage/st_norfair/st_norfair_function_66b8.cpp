#include <types.h>
#pragma force_active on

struct NorfairElement {
    u32 data[26];
};

struct NorfairArray {
    u32 header[3];
    NorfairElement members[1];
};

extern "C" NorfairElement* fn_54_66B8(NorfairArray* array, int index) {
    return &array->members[index];
}
