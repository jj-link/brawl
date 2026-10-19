#pragma force_active on
struct PairMember {
    unsigned int storage[2];
};

struct PairArray {
    unsigned int header;
    PairMember members[2];
};

extern "C" void fn_27_57F78(PairMember* member);

extern "C" void fn_110_966C(PairArray* array) {
    for (int index = 0; index < 2; ++index) {
        fn_27_57F78(&array->members[index]);
    }
}
