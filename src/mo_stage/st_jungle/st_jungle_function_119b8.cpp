#pragma force_active on
extern "C" void fn_51_3C30(void*, short);

extern "C" {
void* fn_51_119B8(void* self, int del) {
    if (self != 0) {
        fn_51_3C30(self, 0);
        if (del > 0) {
            operator delete(self);
        }
    }
    return self;
}
}
