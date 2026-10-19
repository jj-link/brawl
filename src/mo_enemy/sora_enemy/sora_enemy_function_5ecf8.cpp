#pragma force_active on
extern "C" void fn_41_5EE64(void*, short);
extern "C" void fn_41_5EC8C(void*, short);

extern "C" void* fn_41_5ECF8(void* self, short shouldDelete) {
    if (self) {
        fn_41_5EE64((char*)self + 0x218, -1);
        fn_41_5EC8C((char*)self + 4, -1);
        if (shouldDelete > 0) {
            operator delete(self);
        }
    }
    return self;
}
