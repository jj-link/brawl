#pragma force_active on
extern "C" void fn_27_1DA1F4(void*);
extern "C" void fn_27_1DB7B0(void*);

extern "C" void fn_123_170D4(void* self, int flag) {
    fn_27_1DA1F4(self);
    switch (flag) {
    case 0:
        fn_27_1DB7B0(self);
        break;
    }
}
