#pragma force_active on
extern "C" void fn_80101384(void* self, int flag);
extern "C" void* fn_20_2D50(void* self, int flag);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_20_30E8(void* self, int flag) {
    if (self != 0) {
        fn_80101384((char*)self + 0x74, -1);
        fn_20_2D50(self, 0);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
