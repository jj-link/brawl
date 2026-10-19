#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_5CC1C(void*, short);
extern "C" void* fn_27_D3080(void*, short);

extern "C" void* fn_109_10C98(void* self, short deleting) {
    if (self != 0) {
        fn_27_5CC1C(static_cast<unsigned char*>(self) + 0xAC, -1);
        if (self != 0) {
            fn_27_D3080(self, -1);
        }
        if (deleting > 0) {
            operator delete(self);
        }
    }
    return self;
}
