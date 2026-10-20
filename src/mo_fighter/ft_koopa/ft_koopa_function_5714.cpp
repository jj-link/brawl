#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_48BE8(void*, short);
extern "C" void* fn_27_4742C(void*, short);
extern "C" void* fn_27_4CAA0(void*, short);
extern "C" void* fn_27_CDDE8(void*, short);
extern "C" void* fn_27_CD78C(void*, short);

extern "C" void* fn_102_5714(void* self, short deleting) {
    if (self != 0) {
        fn_27_48BE8(static_cast<unsigned char*>(self) + 0x1C4, -1);
        fn_27_4742C(static_cast<unsigned char*>(self) + 0x1B4, -1);
        fn_27_4CAA0(static_cast<unsigned char*>(self) + 0x130, -1);
        fn_27_CDDE8(static_cast<unsigned char*>(self) + 0x6C, -1);
        fn_27_CD78C(self, -1);
        if (deleting > 0) {
            operator delete(self);
        }
    }
    return self;
}
