#pragma force_active on
void operator delete(void*);
extern "C" void fn_27_1A18A0(void*, short);
extern "C" void fn_119_3D6C(void*, short);

extern "C" void* fn_119_3CF4(void* self, short deleting) {
    if (self != 0) {
        fn_27_1A18A0(static_cast<unsigned char*>(self) + 0x354, -1);
        if (self != 0) {
            fn_119_3D6C(self, 0);
        }
        if (deleting > 0) {
            operator delete(self);
        }
    }
    return self;
}
