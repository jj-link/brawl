#pragma force_active on
extern "C" {
void fn_100_15040(void*, short);
void* fn_100_15300(void*, short);
}

extern "C" void* fn_100_14FD0(char* self, short deleting) {
    if (self != 0) {
        fn_100_15040(self + 0x1800, -1);
        fn_100_15300(self, 0);
        if (deleting > 0) {
            operator delete(self);
        }
    }
    return self;
}
