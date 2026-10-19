#pragma force_active on
extern "C" void* __dt__16soHeapModuleImplFv(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_41_2EDD4(void* self, short flag) {
    if (self != 0) {
        __dt__16soHeapModuleImplFv(self, -1);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
