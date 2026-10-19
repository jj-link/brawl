#pragma force_active on
extern "C" {
void __dt__18soCollisionHitPartFv(void*, int);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
}

extern "C" void* fn_74_5EA4(void* self, int deleteFlag) {
    if (self != 0) {
        __destroy_arr(static_cast<char*>(self) + 0xC,
                      __dt__18soCollisionHitPartFv, 0x68, 1);
        if (deleteFlag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
