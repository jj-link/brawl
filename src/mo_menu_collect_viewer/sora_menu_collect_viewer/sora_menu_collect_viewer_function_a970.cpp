#pragma force_active on

#include <types.h>
#include <gf/gf_heap_manager.h>
#include <string.h>

struct Obj {
    int type;
    int pad4;
    virtual void destroy(int);
    char* data;
};

struct Owner {
    char pad[0xE4];
    int value;
};

extern "C" {
void fn_80153488(void*);
void fn_80153498(void*, int);
void fn_80153504(void*, int);
void fn_80153E2C(void*, int);
void fn_80153E3C(void*, int);
void fn_80153EC4(void*, void*);
void fn_80154104(void*, int);
int fn_80154018(void*);
int fn_80153810(void*);
Obj* fn_80153818(void*, int);
u64 fn_80153D2C(void*);
void fn_80153610(void*, void*, u64, int, int, int);
}

extern "C" void* fn_6_A970(void* unused, int* out1, int* out2,
                            Owner* owner, void* arg4, void* arg5) {
    char writer[0xB4];
    char source[8];
    char target[8];
    Obj* obj;
    void* res;
    int size;

    fn_80153488(source);
    fn_80153488(target);
    fn_80153E2C(writer, 0x2B);
    fn_80153504(source, owner->value);
    obj = fn_80153818(source, 0x2B);

    switch (obj->type) {
    case 1:
        memcpy(obj->data, arg4, 0xA);
        memcpy(obj->data + 0xA, arg5, 0x28);
        arg5 = (void*)1;
        break;
    case 2:
        memcpy(obj->data, arg4, 0xA);
        memcpy(obj->data + 0xA, arg5, 0x28);
        arg5 = (void*)0;
        break;
    case 3:
        memcpy(obj->data, arg4, 0xA);
        memcpy(obj->data + 0xA, arg5, 0x28);
        arg5 = (void*)2;
        break;
    }

    fn_80153610(target, obj, fn_80153D2C(source), 0x2B, 2, 0);
    if (obj != 0) {
        obj->destroy(1);
    }
    fn_80154104(writer, fn_80153810(target));
    size = fn_80154018(writer);
    res = gfHeapManager::alloc((Heaps::HeapType)0x2B, size, 0x20);
    fn_80153EC4(writer, res);
    *out1 = size;
    *out2 = (int)arg5;
    fn_80153E3C(writer, -1);
    fn_80153498(target, -1);
    fn_80153498(source, -1);
    return res;
}
