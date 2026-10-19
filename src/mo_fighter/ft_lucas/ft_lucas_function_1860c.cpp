#pragma force_active on
extern "C" void fn_114_57E0(void* object, short deleting);
extern "C" void fn_114_18678(void* object, short deleting);

extern "C" void* fn_114_1860C(char* self, short deleting) {
    if (self != 0) {
        fn_114_57E0(self + 0x7E18, -1);
        fn_114_18678(self + 4, -1);
        if (deleting > 0) {
            operator delete(self);
        }
    }
    return self;
}
