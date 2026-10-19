#pragma force_active on
struct PairMember {
    unsigned int storage[2];
};

struct PairArray {
    unsigned int header;
    PairMember members[2];
};

extern "C" void fn_27_57ED8(PairMember* member, void* argument);

extern "C" void fn_110_96C0(PairArray* array, void* argument) {
    for (int index = 0; index < 2; ++index) {
        fn_27_57ED8(&array->members[index], argument);
    }
}
