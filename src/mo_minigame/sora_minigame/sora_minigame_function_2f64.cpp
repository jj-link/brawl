#pragma force_active on
extern "C" void fn_20_2D50(void*, int);
void operator delete(void*);

extern "C" void* fn_20_2F64(void* self, int flag) {
    if (self != 0) {
        fn_20_2D50(self, 0);
        if (flag > 0) {
            operator delete(self);
        }
    }
    return self;
}
