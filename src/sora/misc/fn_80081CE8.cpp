#pragma force_active on

extern "C" void fn_8027EABC(void*, void*, unsigned int, int);
extern void* lbl_805A0EC8;

struct Array {
    void* data;
    int size;
    unsigned int raw;

    bool isOwned() const {
        return !(raw & 0x80000000);
    }

    void dealloc() {
        fn_8027EABC(lbl_805A0EC8, data, raw * 4, 0x15);
    }

    void clear() {
        if (isOwned())
            dealloc();
        data = 0;
        size = 0;
        raw = (raw & 0x40000000) | 0x80000000;
    }

    ~Array() {
        if (!(raw & 0x80000000))
            fn_8027EABC(lbl_805A0EC8, data, raw * 4, 0x15);
    }
};

struct Ref {
    int count;
    ~Ref() {}
};

struct Object {
    char pad[0x1f8];
    Ref* ref;
    Array array;

    ~Object() {
        if (ref && ref->count == 0) {
            delete ref;
            ref = 0;
        }
        array.clear();
    }
};

extern "C" void* fn_80081CE8(Object* self, int flag) {
    if (self) {
        if (self->ref && self->ref->count == 0) {
            delete self->ref;
            self->ref = 0;
        }
        self->array.clear();
        self->array.~Array();
        if (flag > 0)
            operator delete(self);
    }
    return self;
}
