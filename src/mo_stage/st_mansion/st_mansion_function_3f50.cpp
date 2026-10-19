#pragma force_active on
extern "C" {

typedef void (*DtorFunc)(void*, int);

void __destroy_arr(void* ptr, DtorFunc dtor, unsigned long elemSize, unsigned long count);
void __dl__FPv(void* ptr);
void __dt__19soCollisionHitGroupFv(void* thisPtr, int flag);

void* fn_47_3F50(void* ptr, int count) {
    void* result = ptr;
    if (ptr != 0) {
        __destroy_arr((char*)ptr + 0xC, &__dt__19soCollisionHitGroupFv, 0x38, 1);
        if (count > 0) {
            __dl__FPv(ptr);
        }
    }
    return result;
}

}
