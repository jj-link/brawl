#include <types.h>
#pragma force_active on

extern "C" void fn_8027CE3C(void* self, int n);
extern "C" void fn_8027EABC(void* heap, void* data, unsigned int size, int tag);

extern void* lbl_805A0EC8;
extern void* lbl_805A0ED0;

class Object_vptr_0 {
public:
    virtual void slot0(int arg);
    unsigned short flag;
    short count;
};

struct Holder {
    Object_vptr_0* obj;
};

struct Node {
    int unk0;
    Node* next;
    Holder* holder;
};

struct Arr {
    void** data;
    int count;
    unsigned int raw;
    void* buf[0x80];

    bool isOwned() const {
        return (raw & 0x80000000) == 0;
    }

    void dealloc() {
        fn_8027EABC(lbl_805A0EC8, data, raw << 2, 0x15);
    }
};

extern "C" void fn_8027B75C(void) {
    Arr arr;
    arr.data = arr.buf;
    arr.count = 0;
    arr.raw = 0x80000080;

    Node* n = (Node*)lbl_805A0ED0;
    while (n != 0) {
        if (arr.count == (int)(arr.raw & 0x3FFFFFFF)) {
            fn_8027CE3C(&arr, 4);
        }
        arr.data[arr.count++] = n;
        n = n->next;
    }

    for (int i = arr.count - 1; i >= 0; i--) {
        Object_vptr_0* c = ((Node*)arr.data[i])->holder->obj;
        if (c->flag != 0) {
            if (--c->count == 0 && c != 0) {
                c->slot0(1);
            }
        }
        ((Node*)arr.data[i])->holder->obj = 0;
    }

    if (arr.isOwned()) {
        arr.dealloc();
    }
}
