#include <types.h>
#pragma force_active on

extern "C" bool fn_8018C0E8(void*, void*);

class Node {
public:
    virtual void f0() = 0;
    virtual void f1() = 0;
    virtual void f2() = 0;
    virtual void f3() = 0;
    virtual void f4() = 0;
    virtual void f5() = 0;
    virtual void f6() = 0;
    virtual void f7() = 0;
    virtual void f8() = 0;
    virtual void f9() = 0;
    virtual void f10() = 0;
    virtual void f11() = 0;
    virtual void f12() = 0;
    virtual void* f13(void*, s32);
};

struct Self {
    char padding[0x14];
    void* head;
};

extern "C" void* fn_80182B40(Self* self, void* arg1, s32 arg2) {
    if (fn_8018C0E8((char*)self + 0xB8, arg1)) {
        return self;
    }
    if (arg2 != 0) {
        void* cur = self->head;
        void* end = (void*)&self->head;
        while (cur != end) {
            Node* node = (Node*)((char*)cur - 4);
            void* result = node->f13(arg1, 1);
            if (result) return result;
            cur = *(void**)cur;
        }
    }
    return NULL;
}
