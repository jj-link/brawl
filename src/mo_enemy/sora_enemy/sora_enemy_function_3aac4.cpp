#pragma force_active on
extern "C" void fn_41_2D244(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_3AAC4(void* self, short p2) {
    if (self != 0) {
        fn_41_2D244(static_cast<unsigned char*>(self) + 4, -1);
        if (p2 > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
