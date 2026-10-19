#pragma force_active on
extern "C" {
typedef void (*Destructor)(void*, int);
void __dt__18soCollisionHitPartFv(void*, int);
void __destroy_arr(void*, Destructor, unsigned long, unsigned long);
void __dl__FPv(void*);

void* fn_62_9FC8(void* self, int shouldDelete) {
    if (self != 0) {
        __destroy_arr((char*)self + 0xC, __dt__18soCollisionHitPartFv, 0x68, 1);
        if (shouldDelete > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
