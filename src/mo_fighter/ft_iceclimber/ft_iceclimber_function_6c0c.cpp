#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_1A15B8(void*, short);
extern "C" void fn_105_6C84(void*, short);

extern "C" void* fn_105_6C0C(void* self, short deleting) {
    if (self != 0) {
        fn_27_1A15B8(static_cast<unsigned char*>(self) + 0x138, -1);
        if (self != 0) {
            fn_105_6C84(self, 0);
        }
        if (deleting > 0) {
            operator delete(self);
        }
    }
    return self;
}
