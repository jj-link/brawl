#pragma force_active on
extern "C" {
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dt__18soCollisionHitPartFv(void*, int);
}

void operator delete(void* p);

extern "C" void* fn_72_BDB4(char* self, int flags) {
    if (self != 0) {
        __destroy_arr(self + 0xc, __dt__18soCollisionHitPartFv, 0x68, 3);
        if (flags > 0) {
            operator delete(self);
        }
    }
    return self;
}
