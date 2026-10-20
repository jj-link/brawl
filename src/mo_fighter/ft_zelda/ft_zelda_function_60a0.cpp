#pragma force_active on
void operator delete(void*);
extern "C" void fn_27_1A15B8(void*, short);
extern "C" void fn_104_6118(void*, short);

extern "C" void* fn_104_60A0(void* self, short deleting) {
    if (self != 0) {
        fn_27_1A15B8(static_cast<unsigned char*>(self) + 0x2FC, -1);
        if (self != 0) {
            fn_104_6118(self, 0);
        }
        if (deleting > 0) {
            operator delete(self);
        }
    }
    return self;
}
