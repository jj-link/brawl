#pragma force_active on
extern "C" void fn_27_7700(void*, short);

extern "C" void* fn_104_1F30(void* self, short flags) {
    if (self != 0) {
        fn_27_7700(self, 0);
        if (flags > 0) {
            operator delete(self);
        }
    }
    return self;
}
