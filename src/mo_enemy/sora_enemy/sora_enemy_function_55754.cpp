#pragma force_active on
extern "C" void fn_41_556F4(void*, short);
extern "C" void fn_41_555F4(void*, short);

extern "C" {
char* fn_41_55754(char* self, short flag) {
    if (self != 0) {
        fn_41_556F4(self + 0xC8, -1);
        fn_41_555F4(self + 0x4, -1);
        if (flag > 0) {
            operator delete(self);
        }
    }
    return self;
}
}
