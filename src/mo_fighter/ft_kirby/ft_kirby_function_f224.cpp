#pragma force_active on
struct Pair {
    unsigned int header;
    unsigned int members[2][2];
};

extern "C" void fn_27_57F78(void* member);

extern "C" void fn_96_F224(Pair* pair) {
    for (int index = 0; index < 2; ++index) {
        fn_27_57F78(&pair->members[index][0]);
    }
}
