#pragma force_active on
typedef unsigned int u32;

struct PairMember {
    u32 storage[2];
};

struct PairArray {
    u32 header;
    PairMember members[2];
};

extern "C" void fn_27_57ED8(PairMember* member, void* argument);

extern "C" void fn_103_9F9C(PairArray* array, void* argument) {
    for (int index = 0; index < 2; ++index) {
        fn_27_57ED8(&array->members[index], argument);
    }
}
