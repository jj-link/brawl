#pragma force_active on
extern "C" {
void fn_54_2CB0(void*, int);
void* fn_54_349C(void* self, int flag);
}

extern "C" void* fn_54_349C(void* self, int flag) {
    if (self != 0) {
        fn_54_2CB0(self, 0);
        if (flag > 0) {
            operator delete(self);
        }
    }
    return self;
}
