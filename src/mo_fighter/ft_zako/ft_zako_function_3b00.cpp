#pragma force_active on
extern "C" void* fn_27_1A15B8(void*, short);
extern "C" void fn_126_3B78(void*, short);
void operator delete(void*);

extern "C" void* fn_126_3B00(void* self, short deleting) {
    if (self != 0) {
        fn_27_1A15B8(static_cast<unsigned char*>(self) + 0x11C, -1);
        if (self != 0) {
            fn_126_3B78(self, 0);
        }
        if (deleting > 0) {
            operator delete(self);
        }
    }
    return self;
}
