#include <StaticAssert.h>
#include <types.h>

struct LucasPairMember {
    u32 storage[2];
};

struct LucasPairArray {
    u32 header;
    LucasPairMember members[2];
};
static_assert(sizeof(LucasPairMember) == 8, "Member stride mismatch");
static_assert(sizeof(LucasPairArray) == 0x14, "Member array layout mismatch");

extern "C" void fn_27_57F78(LucasPairMember* member);
extern "C" void fn_27_57ED8(LucasPairMember* member, void* argument);

extern "C" LucasPairMember* fn_114_CBBC(LucasPairArray* array, int index) {
    return &array->members[index];
}

extern "C" void fn_114_CBCC(LucasPairArray* array) {
    for (int index = 0; index < 2; ++index) {
        fn_27_57F78(&array->members[index]);
    }
}

extern "C" void fn_114_CC20(LucasPairArray* array, void* argument) {
    for (int index = 0; index < 2; ++index) {
        fn_27_57ED8(&array->members[index], argument);
    }
}
