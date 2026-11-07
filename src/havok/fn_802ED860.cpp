#pragma force_active on

extern void* lbl_805A0EC8;
extern "C" void fn_8027CE3C(void*, int);
extern "C" void fn_8027EABC(void*, void*, unsigned int, int);

struct Array {
    void** data;
    int size;
    unsigned int capacity;
    void* storage[4];

    bool isOwned() const { return (capacity & 0x80000000) == 0; }
    void dealloc() {
        fn_8027EABC(lbl_805A0EC8, data, (capacity & 0x3fffffff) * 4, 0x15);
    }
};

class Obj {
public:
    virtual void slot0(int);
    virtual void slot1();
    virtual void slot2();
    virtual void slot3(Array*);
    unsigned short unk4;
    short unk6;
    int unk8;
    void* unkC;
};

struct ObjArray {
    Obj** items;
    int count;

    int find(Obj* o) {
        for (int j = 0; j < count; j++) {
            if (items[j] == o)
                return j;
        }
        return -1;
    }
    void removeAt(int idx) {
        count--;
        items[idx] = items[count];
    }
};

struct Holder {
    char pad[0x1d8];
    ObjArray arr;
};

struct Pool {
    char pad[0x40];
    void** data;
    int size;
    unsigned int capacity;
};

struct Node {
    char pad[0x18];
    Pool* pool;
    char pad2[0x6];
    unsigned short idx;
};

struct Ctx {
    char pad[0x78];
    int unk78;
    int unk7C;
    char pad2[4];
    signed char unk84;
};

extern "C" void fn_802EA268(Node*, Obj*);
extern "C" void fn_802EFE70(Ctx*);
extern "C" void fn_802F3A98(Ctx*, Obj*);

extern "C" void fn_802ED860(Ctx* self, Obj* obj) {
    if (obj->unk4 != 0) {
        obj->unk6++;
    }
    self->unk7C++;
    fn_802F3A98(self, obj);
    Array arr;
    arr.data = arr.storage;
    arr.size = 0;
    arr.capacity = 0x80000004;
    obj->slot3(&arr);
    for (int i = 0; i < arr.size; i++) {
        ObjArray& a = ((Holder*)arr.data[i])->arr;
        a.removeAt(a.find(obj));
    }
    Node* node = (Node*)obj->unkC;
    fn_802EA268(node, obj);
    obj->unk8 = 0;
    if (obj->unk4 != 0) {
        if (--obj->unk6 == 0 && obj != 0)
            obj->slot0(1);
    }
    Pool* pool = node->pool;
    if (node->idx == 0xffff) {
        node->idx = pool->size;
        if (pool->size == (int)(pool->capacity & 0x3fffffff))
            fn_8027CE3C(&pool->data, 4);
        pool->data[pool->size++] = node;
    }
    if (arr.isOwned())
        arr.dealloc();
    if (--self->unk7C == 0 && self->unk78 != 0 && self->unk84 == 0)
        fn_802EFE70(self);
    if (obj->unk4 != 0) {
        if (--obj->unk6 == 0 && obj != 0)
            obj->slot0(1);
    }
}
