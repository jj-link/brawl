#pragma force_active on
extern "C" void* fn_115_3D54(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_115_15784(void* self, short baseDeleting) {
    if (self) {
        fn_115_3D54(self, 0);
        if (baseDeleting > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
