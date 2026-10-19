#pragma force_active on
void operator delete(void*);
extern "C" void* fn_116_F844(void*, short);
extern "C" void* fn_116_2164(void*, short);

extern "C" void* fn_116_F7D8(void* self, short deleting) {
    if (self != 0) {
        fn_116_F844((unsigned char*)self + 0x50, -1);
        fn_116_2164(self, -1);
        if (deleting > 0) {
            operator delete(self);
        }
    }
    return self;
}
