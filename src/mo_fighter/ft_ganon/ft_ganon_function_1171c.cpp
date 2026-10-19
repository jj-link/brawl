#pragma force_active on
extern "C" void fn_109_4A24(void* ptr, short count);

extern "C" void* fn_109_1171C(void* self, short flags) {
    if (self != 0) {
        fn_109_4A24(self, 0);
        if (flags > 0) {
            operator delete(self);
        }
    }
    return self;
}
