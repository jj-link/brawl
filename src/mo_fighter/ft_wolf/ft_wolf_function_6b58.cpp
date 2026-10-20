#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_1A15B8(void*, short);
extern "C" void fn_125_6BD0(void*, short);

extern "C" void* fn_125_6B58(void* self, short deleting) {
    if (self != 0) {
        fn_27_1A15B8((unsigned char*)self + 0x1fc, -1);
        if (self != 0) {
            fn_125_6BD0(self, 0);
        }
        if (deleting > 0) {
            operator delete(self);
        }
    }
    return self;
}
