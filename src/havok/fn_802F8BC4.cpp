#pragma force_active on
#include <types.h>

extern "C" int __cntlzw(unsigned int);
extern "C" void fn_8027EABC(void*, void*, u32, s32);
extern "C" void fn_802EA1F8(void*, void*);
extern "C" void fn_802F9A04(void*, void*, void*);
extern "C" void* lbl_805A0EC8;

class Object_vptr_0 {
public:
    virtual ~Object_vptr_0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3(void* arr);

    u16 flag;
    s16 refs;
};

struct Body {
    char pad0[8];
    void* field8;
    char pad1[0x4c];
    void* field58;
    char pad2[0x4c];
    u8 type;
};

struct Array {
    Body** data;
    s32 size;
    u32 capacity;
    Body* inl[16];

    bool isOwned() const { return (capacity & 0x80000000) == 0; }
    void dealloc() {
        fn_8027EABC(lbl_805A0EC8, data, capacity * 4, 0x15);
    }
};

struct Input {
    Object_vptr_0** data;
    s32 size;
};

struct Self {
    char pad[0x20];
    void* field20;
};

static inline void release(Object_vptr_0* p) {
    if (p->flag != 0 && --p->refs == 0)
        delete p;
}

static inline Body* item(Body** p, s32 i) { return p[i]; }
extern "C" void fn_802F8BC4(Self* self, Body* body, Input* input) {
    Array arr;
    void* target;
    s32 i;
    Object_vptr_0* obj;

    target = body->field58;
    arr.data = arr.inl;
    arr.size = 0;
    arr.capacity = 0x80000010;

    for (i = 0; i < input->size; i++) {
        obj = input->data[i];
        if (target != self->field20) {
            fn_802EA1F8(target, obj);
            release(obj);
            arr.size = 0;
            obj->slot3(&arr);

            for (s32 j = 0; j < arr.size; j++) {
                Body** p = arr.data;
                Body* x = item(p, j);
                s32 c1 = 0;
                if (!(s8)((u32)__cntlzw(x->type - 7) >> 5) && x != body)
                    c1 = 1;
                if (c1) {
                    Body* other = p[j];
                    s32 diff = 0;
                    s32 valid = 0;
                    if (!(s8)((u32)__cntlzw(other->type - 7) >> 5) &&
                        !(s8)((u32)__cntlzw(body->type - 7) >> 5))
                        valid = 1;
                    if (valid && other->field58 != body->field58)
                        diff = 1;
                    if (diff)
                        fn_802F9A04(other->field8, other, body);
                }
            }
        } else {
            fn_802EA1F8(self->field20, obj);
            release(obj);
        }
    }

    if (arr.isOwned())
        arr.dealloc();
}
