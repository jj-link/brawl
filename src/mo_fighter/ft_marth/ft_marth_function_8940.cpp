#pragma force_active on
extern "C" {
void fn_106_8880(void* object, short shouldDelete);
void __dl__FPv(void* p);

void* fn_106_8940(void* self, short shouldDelete) {
    if (self != 0) {
        if (self != 0) {
            fn_106_8880((char*)self + 4, -1);
        }
        if (shouldDelete > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
