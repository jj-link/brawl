#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_1A15B8(void*, short);
extern "C" void fn_96_5338(void*, short);

extern "C" void* fn_96_53B0(void* self, short deleting) {
    if (self != 0) {
        fn_27_1A15B8((unsigned char*)self + 0x1fc, -1);
        if (self != 0) {
            fn_96_5338(self, 0);
        }
        if (deleting > 0) {
            operator delete(self);
        }
    }
    return self;
}
