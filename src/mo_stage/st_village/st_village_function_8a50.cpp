#pragma force_active on
extern "C" {
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dt__18soCollisionHitPartFv(void*, int);
void __dl__FPv(void*);
void* fn_70_8A50(void* self, int flag);
}

extern "C" void* fn_70_8A50(void* self, int flag) {
    if (self) {
        __destroy_arr((unsigned char*)self + 0xc, __dt__18soCollisionHitPartFv, 0x68, 1);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
