#pragma force_active on
extern "C" void* fn_27_93100(void*, short);
extern "C" void* fn_115_3224(void*, short);
extern "C" void* fn_27_19EE64(void*, short);
extern "C" void* fn_27_1A509C(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_115_319C(void* self, short p2) {
    if (self) {
        short del = -1;
        char* c = (char*)self;
        fn_27_93100(c + 0x1E3C4, del);
        fn_115_3224(c + 0x144, del);
        fn_27_19EE64(c + 0x48, del);
        fn_27_1A509C(self, del);
        if (p2 > 0)
            __dl__FPv(self);
    }
    return self;
}
