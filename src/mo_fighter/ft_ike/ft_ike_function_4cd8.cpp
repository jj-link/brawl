#pragma force_active on
void operator delete(void*);
extern "C" void* fn_27_48BE8(void*, short);
extern "C" void* fn_27_4742C(void*, short);
extern "C" void* fn_27_CB800(void*, short);
extern "C" void* fn_27_19FB24(void*, short);
extern "C" void* fn_27_19E398(void*, short);

extern "C" void* fn_119_4CD8(void* self, short deleting) {
    if (self != 0) {
        unsigned char* storage = static_cast<unsigned char*>(self);
        fn_27_48BE8(storage + 0x354, -1);
        fn_27_4742C(storage + 0x344, -1);
        fn_27_CB800(storage + 0x248, -1);
        fn_27_19FB24(storage + 0xCC, -1);
        fn_27_19E398(self, -1);
        if (deleting > 0) {
            operator delete(self);
        }
    }
    return self;
}
