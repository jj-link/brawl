#pragma force_active on
extern "C" void* fn_120_3CA0(void*, short);
extern "C" void* fn_120_3D24(void*, short);
extern "C" void* fn_120_12BB4(void*, short);
extern "C" void* fn_120_12B3C(void*, short);
extern "C" void* fn_120_12A20(void*, short);
extern "C" void* fn_27_C74E8(void*, short);
extern void operator delete(void*);

extern "C" void* fn_120_12C10(void* self, short deleting) {
    if (self != 0) {
        unsigned char* storage = static_cast<unsigned char*>(self);
        fn_120_3CA0(storage + 0x130, -1);
        fn_120_3D24(storage + 0x11c, -1);
        fn_120_12BB4(storage + 0x104, -1);
        fn_120_12B3C(storage + 0x60, -1);
        fn_120_12A20(storage + 0x10, -1);
        fn_27_C74E8(self, -1);
        if (deleting > 0) {
            operator delete(self);
        }
    }
    return self;
}
