#include <types.h>
#include <revolution/OS/OSMutex.h>
#include <nw4r/ut/ut_LinkList.h>
#pragma force_active on

using namespace nw4r::ut;

class ListAccess : public detail::LinkListImpl {
public:
    using detail::LinkListImpl::Insert;
};

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4(int);
};
class ParamCallback {
public:
    virtual void slot0(void*, s32, s32, void*, s32);
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
};
class AllocCallback {
public:
    virtual void* slot0(s32);
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
};
struct AmbientInfo {
    ParamCallback* callback;
    void* callback2;
    AllocCallback* allocator;
    void* data;
    s32 size;
};

extern "C" bool fn_801CBD0C(char* self, s32 priority, void* list);
extern "C" void* fn_801C0A0C(void* p);
extern "C" void* fn_801C427C(void* p, void* arg1);
extern "C" void fn_8015C2BC(void* list, void* out);
extern "C" void fn_801CA970(void* obj);
extern "C" void fn_801BD5C0(void* p, void* a, void* b, void* c, void* d);
extern "C" void fn_801BF5B8(void* self, void* obj);
extern "C" void* memcpy(void* dst, const void* src, unsigned long n);

inline char* create(char* obj) {
    char* p = (char*)fn_801C0A0C(obj);
    if (p) {
        if (p) p = (char*)fn_801C427C(p, obj);
    }
    return p;
}

inline void initAmbient(char* sound, AmbientInfo* src) {
    if (src != NULL) {
        void* ret = src->allocator->slot0(src->size);
        if (ret != NULL) {
            memcpy(ret, src->data, src->size);
            fn_801BD5C0(sound, src->callback, src->callback2, src->allocator, ret);
        }
    }
}

inline void addPriority(char* self, char* obj) {
    OSMutex* mutex = (OSMutex*)(self + 0x48);
    OSLockMutex(mutex);
    detail::LinkListImpl::Iterator it(*(LinkListNode**)(self + 0x10));
    while (!(it == detail::LinkListImpl::Iterator((LinkListNode*)(self + 0x10)))) {
        int a = *(unsigned char*)((char*)it.operator->() - 0x54) + *(int*)((char*)it.operator->() - 0x88);
        int x = a > 127 ? 127 : (a < 0 ? 0 : a);
        int b = *(unsigned char*)(obj + 0x74) + *(int*)(obj + 0x40);
        int y = b > 127 ? 127 : (b < 0 ? 0 : b);
        if (y < x) break;
        ++it;
    }
    ((ListAccess*)(self + 0xc))->Insert(it, (LinkListNode*)(obj + 0xc8));
    OSUnlockMutex(mutex);
}

inline void bindSound(char* self, char* sound, s32& p) {
    OSMutex* mutex = (OSMutex*)(self + 0x48);
    OSLockMutex(mutex);
    if (*(s32*)(self + 0x18) == 0) {
        OSUnlockMutex(mutex);
    } else {
        s32 node = *(s32*)(self + 0x1C);
        p = node - 0x2C;
        fn_8015C2BC(self + 0x18, &node);
        *(void**)((char*)p + 0x34) = sound;
        *(char**)(sound + 4) = (char*)p;
        fn_801CA970((char*)p);
        OSUnlockMutex(mutex);
    }
}

inline void linkSound(char* self, char* sound) {
    detail::LinkListImpl::Iterator it((LinkListNode*)(self + 4));
    ((ListAccess*)self)->Insert(it, (LinkListNode*)(sound + 0xC0));
    *(char**)(sound + 0x10) = self;
}

extern "C" void* fn_801CB13C(char* self, u8 prio, s32 arg2, AmbientInfo* src, void* arg4, s32 arg5, char* obj) {
    OSMutex* m1;
    OSMutex* m0 = (OSMutex*)(self + 0x48);
    s32 buf[8];
    s32 var29;
    s32 var28;
    char* var27;
    OSMutex* m2;
    char* r21;
    char* cur;
    s32 sum;
    s32 x;
    s32 y;
    s32 a;
    s32 b;
    char* sentinel;

    OSLockMutex(m0);
    if (obj == NULL) {
        OSUnlockMutex(m0);
        return NULL;
    }
    var29 = 0;
    if (src != NULL) {
        src->callback->slot0(buf, arg5, 0, src->data, 8);
        var29 = buf[6];
    }
    sum = arg2 + var29;
    if (sum > 127) var28 = 127;
    else var28 = sum < 0 ? 0 : sum;
    if (!fn_801CBD0C(self, var28, arg4)) {
        OSUnlockMutex(m0);
        return NULL;
    }
    m1 = (OSMutex*)(obj + 0x10);
    OSLockMutex(m1);
    var27 = NULL;
    while (var27 == NULL) {
        char* p = (char*)fn_801C0A0C(obj);
        if (p != NULL) {
            var27 = p;
            if (var27 != NULL) var27 = (char*)fn_801C427C(var27, obj);
        } else {
            if (*(s32*)(obj + 4) == 0) {
                r21 = NULL;
            } else {
                r21 = *(char**)(obj + 8) - 0xB8;
            }
            if (r21 == NULL) {
                OSUnlockMutex(m1);
                var27 = NULL;
                goto failed;
            }
            sum = *(u8*)(r21 + 0x74) + *(s32*)(r21 + 0x40);
            x = sum > 127 ? 127 : (sum < 0 ? 0 : sum);
            if (var28 < x) {
                OSUnlockMutex(m1);
                var27 = NULL;
                goto failed;
            }
            OSUnlockMutex((OSMutex*)(obj + 0x10));
            ((Object_vptr_0*)r21)->slot4(0);
            OSLockMutex((OSMutex*)(obj + 0x10));
        }
    }
    {
        detail::LinkListImpl::Iterator it(*(LinkListNode**)(obj + 8));
        while (!(it == detail::LinkListImpl::Iterator((LinkListNode*)(obj + 8)))) {
            a = *(u8*)((char*)it.operator->() - 0x44) + *(s32*)((char*)it.operator->() - 0x78);
            b = a > 127 ? 127 : (a < 0 ? 0 : a);
            if (var28 < b) break;
            ++it;
        }
        ((ListAccess*)(obj + 4))->Insert(it, (LinkListNode*)(var27 + 0xB8));
        OSUnlockMutex(m1);
    }
failed:
    if (var27 == NULL) {
        OSUnlockMutex(m0);
        return NULL;
    }
    bindSound(self, var27, arg5);
    if (src != NULL) {
        if (src != NULL) {
            void* ret = src->allocator->slot0(src->size);
            if (ret != NULL) {
                memcpy(ret, src->data, src->size);
                fn_801BD5C0(var27, src->callback, src->callback2, src->allocator, ret);
            }
        }
    }
    *(u8*)(var27 + 0x74) = prio;
    *(s32*)(var27 + 0x40) = var29;
    linkSound(self, var27);
    if (arg4 != NULL) {
        fn_801BF5B8(arg4, var27);
    }
    addPriority(self, var27);
    OSUnlockMutex(m0);
    return var27;
}
