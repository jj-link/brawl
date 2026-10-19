#pragma force_active on
void operator delete(void*);
extern "C" void* fn_116_38F0(void*, short);
extern "C" void* fn_116_2164(void*, short);

extern "C" void* fn_116_3884(void* self, short deleting) {
    if (self != 0) {
        unsigned char* storage = static_cast<unsigned char*>(self);
        fn_116_38F0(storage + 0x50, -1);
        fn_116_2164(self, -1);
        if (deleting > 0) {
            operator delete(self);
        }
    }
    return self;
}
