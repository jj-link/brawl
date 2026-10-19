#pragma force_active on
extern "C" void fn_41_37B18(void* self, short shouldDelete);
extern "C" void fn_41_378E4(void* ptr, short flag);

extern "C" void* fn_41_37944(char* self, short shouldDelete) {
    if (self != 0) {
        short m = -1;
        fn_41_37B18(self + 0x38, m);
        fn_41_378E4(self + 4, m);
        if (shouldDelete > 0) {
            operator delete(self);
        }
    }
    return self;
}
