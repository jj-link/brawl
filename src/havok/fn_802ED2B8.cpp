#include <types.h>
#pragma force_active on

extern "C" {

class SoHeapAllocator {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void* vf4(u32 size, s32 align);
    virtual void free(void* ptr, u16 type, s32 align);
};

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11(void* a, void* b);
};

struct Self {
    char pad0[0x54];
    Object_vptr_0* obj54;
    char pad1[0x24];
    s32 f7C;
};

struct Entry {
    void* pad;
    u8* node;
};

extern SoHeapAllocator* lbl_805A0EB8;
extern void* lbl_805A0EC8;

void fn_802E1A54(void* self);
void fn_80281BBC(void* dst, void* src, u32 size);
void fn_802EFF2C(void* a, s8* b);
void fn_8027EABC(void* heap, void* p, u32 size, s32 align);

struct Array {
    Entry* data;
    s32 size;
    u32 capacity;
    bool isOwned() const { return (capacity & 0x80000000) == 0; }
    void dealloc() { fn_8027EABC(lbl_805A0EC8, data, capacity * 8, 0x15); }
};

struct Msg {
    s8 kind;
    void* ptr;
};

void fn_802ED2B8(Self* self, void* arg1) {
    if (self->f7C != 0) {
        Msg msg;
        msg.kind = 0x1F;
        msg.ptr = lbl_805A0EB8->vf4(0x20, 4);
        fn_80281BBC(msg.ptr, arg1, 0x20);
        fn_802EFF2C(self, (s8*)&msg);
        return;
    }
    Array arr;
    arr.data = 0;
    arr.size = 0;
    arr.capacity = 0x80000000;
    self->obj54->slot11(arg1, &arr);
    for (s32 i = 0; i < arr.size; i++) {
        u8* node = arr.data[i].node;
        u8* p = node + (s8)node[5];
        void* r;
        if ((s32)p[0x18] == 1) {
            r = p + *(s32*)(p + 0x10);
        } else {
            r = 0;
        }
        if (r != 0) {
            fn_802E1A54(r);
        }
    }
    if (arr.isOwned()) {
        arr.dealloc();
    }
}

}
