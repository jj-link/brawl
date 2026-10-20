#pragma force_active on
extern "C" void* fn_41_28CE4(void* self, short flag);
extern "C" void* fn_41_2188(void* ptr, short size);
extern "C" void fn_27_7700(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_28D44(void* self, short flag) {
    if (self != 0) {
        fn_41_28CE4(static_cast<char*>(self) + 0x3c, -1);
        short v = 0;
        fn_41_2188(static_cast<char*>(self) + 0xc, v);
        if (self != 0) {
            fn_27_7700(self, v);
        }
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
