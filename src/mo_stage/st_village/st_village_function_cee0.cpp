#pragma force_active on
extern "C" {
void fn_70_20FC(void* self, int flag);
void __dl__FPv(void* p);
}

extern "C" void* fn_70_CEE0(void* self, int flag) {
    if (self != 0) {
        fn_70_20FC(self, 0);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
