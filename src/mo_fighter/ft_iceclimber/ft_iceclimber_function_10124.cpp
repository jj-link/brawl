#pragma force_active on
extern "C" {
void* fn_105_3710(void*, short);
void __dl__FPv(void*);

void* fn_105_10124(void* self, short deleteFlag) {
    if (self != 0) {
        fn_105_3710(self, 0);
        if (deleteFlag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
