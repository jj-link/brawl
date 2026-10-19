#pragma force_active on
extern "C" void fn_77_F54(void* self, int flag);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_77_1204(void* self, int flag) {
    if (self) {
        fn_77_F54(self, 0);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
