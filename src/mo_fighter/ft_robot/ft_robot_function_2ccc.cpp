#pragma force_active on
extern "C" {
void fn_27_C21DC(void*, short);
void operator delete(void* p);

void* fn_120_2CCC(void* self, short flags) {
    if (self != 0) {
        fn_27_C21DC(self, -1);
        if (flags > 0) {
            operator delete(self);
        }
    }
    return self;
}
}
