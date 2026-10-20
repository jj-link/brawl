#pragma force_active on
void operator delete(void*);
extern "C" void fn_27_48BE8(void*, short);
extern "C" void fn_27_47CCC(void*, short);
extern "C" void fn_27_CB800(void*, short);
extern "C" void fn_27_19FB24(void*, short);
extern "C" void fn_27_19E5E0(void*, short);

extern "C" void* fn_102_5684(void* self, short deleting) {
    if (self != 0) {
        unsigned char* storage = static_cast<unsigned char*>(self);
        fn_27_48BE8(storage + 0xa14, -1);
        fn_27_47CCC(storage + 0xa04, -1);
        fn_27_CB800(storage + 0x908, -1);
        fn_27_19FB24(storage + 0x78c, -1);
        fn_27_19E5E0(self, -1);
        if (deleting > 0) {
            operator delete(self);
        }
    }
    return self;
}
