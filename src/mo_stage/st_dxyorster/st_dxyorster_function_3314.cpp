#pragma force_active on
extern "C" {

typedef void (*Destructor)(void*, int);

void __destroy_arr(void*, Destructor, unsigned long, unsigned long);
void __dl__FPv(void*);
void __dt__18soCollisionHitPartFv(void*, int);

void* fn_76_3314(void* ptr, int flag) {
    if (ptr != 0) {
        __destroy_arr((char*)ptr + 0xC, __dt__18soCollisionHitPartFv, 0x68, 9);
        if (flag > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}

}
