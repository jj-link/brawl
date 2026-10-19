#pragma force_active on
extern "C" void fn_27_57F78(void* member);

struct CaptainSlot {
    int header;
    int payload;
};

extern "C" void fn_100_9688(char* object) {
    for (int i = 0; i < 2; ++i) {
        fn_27_57F78(object + i * 8 + 4);
    }
}
