#pragma force_active on
#include <nt/nt_offline.h>
#include <gf/gf_heap_manager.h>
#include <string.h>

struct SwitchObject {
    int type;
    int pad4;
    virtual void destroy(int);
    void* data;
};

extern "C" {
void fn_80153488(void*);
void fn_80153498(void*, int);
int fn_80153504(void*, int);
void fn_80153610(void*, void*, u64, int, int, int);
int fn_80153810(void*);
SwitchObject* fn_80153818(void*, int);
int fn_80153D10(void*);
u64 fn_80153D2C(void*);
void* fn_80153D50(void*);
void fn_80153E2C(void*, int);
void fn_80153E3C(void*, int);
void fn_80153EC4(void*, void*);
int fn_80154018(void*);
int fn_80154104(void*, int);
s16 fn_8014E708(void*);
}

extern "C" void* fn_6_8870(void*, s16* outId, int* outSize, void** outType, void* input) {
    char source[8];
    char target[8];
    char writer[0xC4];
    SwitchObject* object;
    s16 id;
    int size;

    fn_80153488(source);
    fn_80153488(target);
    fn_80153E2C(writer, 0x2B);
    if (fn_80153504(source, *(int*)((char*)input + 0xE4)) == 0) {
        fn_80153E3C(writer, -1);
        fn_80153498(target, -1);
        fn_80153498(source, -1);
        return 0;
    }
    if (fn_80153D10(source) != 0 && fn_80153D10(source) != 1) {
        fn_80153E3C(writer, -1);
        fn_80153498(target, -1);
        fn_80153498(source, -1);
        return 0;
    }
    object = fn_80153818(source, 0x2B);
    switch (object->type) {
    case 1:
        {
            ntFriendInfo* info = ntFriendInfo::getInstance();
            void* destination = object->data;
            void* name = *(void**)info;
            memcpy(destination, (char*)name + 0x4F0, 0xA);
        }
        input = (void*)1;
        break;
    case 2:
        {
            ntFriendInfo* info = ntFriendInfo::getInstance();
            void* destination = object->data;
            void* name = *(void**)info;
            memcpy(destination, (char*)name + 0x4F0, 0xA);
        }
        input = (void*)2;
        break;
    case 3:
        {
            ntFriendInfo* info = ntFriendInfo::getInstance();
            void* destination = object->data;
            void* name = *(void**)info;
            memcpy(destination, (char*)name + 0x4F0, 0xA);
        }
        input = (void*)3;
        break;
    }
    fn_80153610(target, object, fn_80153D2C(source), 0x2B, 1, 0);
    id = fn_8014E708(fn_80153D50(target));
    if (object != 0) {
        object->destroy(1);
    }
    fn_80154104(writer, fn_80153810(target));
    size = fn_80154018(writer);
    object = (SwitchObject*)gfHeapManager::alloc((Heaps::HeapType)0x2B, size, 0x20);
    fn_80153EC4(writer, object);
    *outId = id;
    *outSize = size;
    *outType = input;
    fn_80153E3C(writer, -1);
    fn_80153498(target, -1);
    fn_80153498(source, -1);
    return object;
}
