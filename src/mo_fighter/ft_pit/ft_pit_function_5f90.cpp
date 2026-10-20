#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_1A15B8(void*, short);
extern "C" void fn_112_6008(void*, short);

extern "C" void* fn_112_5F90(void* self, short flag) {
    if (self != 0) {
        fn_27_1A15B8(static_cast<unsigned char*>(self) + 0x2FC, -1);
        if (self != 0) {
            fn_112_6008(self, 0);
        }
        if (flag > 0) {
            operator delete(self);
        }
    }
    return self;
}
