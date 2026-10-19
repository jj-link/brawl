#pragma force_active on
extern "C" void fn_41_5EE64(void*, short);
extern "C" void fn_41_5EA04(void*, short);

extern "C" void* fn_41_5EA70(void* self, short flags) {
    if (self != 0) {
        fn_41_5EE64(static_cast<char*>(self) + 0xF8, -1);
        fn_41_5EA04(static_cast<char*>(self) + 4, -1);
        if (flags > 0) {
            operator delete(self);
        }
    }
    return self;
}
