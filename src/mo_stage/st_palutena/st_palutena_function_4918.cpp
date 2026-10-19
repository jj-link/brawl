#pragma force_active on
typedef void (*Destructor)(void*, int);

extern "C" void __dt__19soCollisionHitGroupFv(void*, int);
extern "C" void __destroy_arr(void*, Destructor, unsigned long, unsigned long);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_67_4918(void* self, int flag) {
    if (self != 0) {
        __destroy_arr(static_cast<char*>(self) + 0xC,
                      __dt__19soCollisionHitGroupFv, 0x38, 1);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
