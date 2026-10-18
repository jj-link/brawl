#pragma force_active on
extern "C" void* fn_115_3D54(void* self, short flags);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_115_5E0C(void* self, short baseDeleting) {
    if (self != 0) {
        fn_115_3D54(self, 0);
        if (baseDeleting > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
