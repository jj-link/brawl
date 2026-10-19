#pragma force_active on
struct PairArray {
    unsigned int header;
    unsigned int members[2][2];
};

extern "C" void fn_27_57F78(void* member);

extern "C" void fn_121_B02C(PairArray* array) {
    for (int index = 0; index < 2; ++index) {
        fn_27_57F78(&array->members[index][0]);
    }
}
