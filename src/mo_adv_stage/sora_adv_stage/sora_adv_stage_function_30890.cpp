#pragma force_active on
extern "C" {

typedef void (*DtorFn)(void*, int);

void __destroy_arr(void* object, DtorFn dtor, unsigned long elemSize, unsigned long count);
void __dl__FPv(void* ptr);
void __dt__18soCollisionHitPartFv(void* this_, int flag);

void* fn_40_30890(void* array, int count) {
    void* result = array;
    if (array != 0) {
        __destroy_arr((char*)array + 0xC, __dt__18soCollisionHitPartFv, 0x68, 13);
        if (count > 0) {
            __dl__FPv(array);
        }
    }
    return result;
}

}
