#pragma force_active on
extern "C" void fn_41_5EE64(void*, short);
extern "C" void fn_41_5ED64(void*, short);

extern "C" void* fn_41_5EEC4(void* self, short flag) {
    if (self != 0) {
        fn_41_5EE64((char*)self + 0x278, -1);
        fn_41_5ED64((char*)self + 4, -1);
        if (flag > 0) {
            operator delete(self);
        }
    }
    return self;
}
