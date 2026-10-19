#pragma force_active on
void operator delete(void*);
extern "C" void fn_27_689B0(void*, short);
extern "C" void fn_27_C9A14(void*, short);

extern "C" void* fn_105_1A980(void* self, short deleting) {
    if (self != 0) {
        fn_27_689B0(static_cast<unsigned char*>(self) + 0x28, -1);
        if (self != 0) {
            fn_27_C9A14(self, -1);
        }
        if (deleting > 0) {
            operator delete(self);
        }
    }
    return self;
}
