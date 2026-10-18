#pragma force_active on
void operator delete(void*);
extern "C" void fn_104_3C90(void*, short);

extern "C" void* fn_104_11D64(void* self, short deleting) {
    if (self != 0) {
        if (self != 0) {
            fn_104_3C90(self, 0);
        }
        if (deleting > 0) {
            operator delete(self);
        }
    }
    return self;
}
