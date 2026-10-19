#pragma force_active on
extern "C" void fn_96_6780(void* p, short n);
void operator delete(void* p);

extern "C" {
void* fn_96_23BD4(void* self, short flags) {
    if (self != 0) {
        short zero = 0;
        fn_96_6780(self, zero);
        if (flags > 0) {
            operator delete(self);
        }
    }
    return self;
}
}
