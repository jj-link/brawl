#pragma force_active on
extern "C" {
void __dt__19soCollisionHitGroupFv(void*, int);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
void* fn_49_5F24(void* self, int flag);
}

void* fn_49_5F24(void* self, int flag) {
    if (self) {
        __destroy_arr((char*)self + 0xC, __dt__19soCollisionHitGroupFv, 0x38, 1);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
