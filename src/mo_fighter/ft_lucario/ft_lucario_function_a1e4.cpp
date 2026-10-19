#pragma force_active on
extern "C" void fn_27_57F78(void* member);

struct Pair8 {
    int header;
    int items[2][2];
};

extern "C" void fn_118_A1E4(Pair8* self) {
    for (int i = 0; i < 2; i++) {
        fn_27_57F78(&self->items[i]);
    }
}
