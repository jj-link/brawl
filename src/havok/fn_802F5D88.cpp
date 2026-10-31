#pragma force_active on

extern "C" void fn_8027EABC(void*, void*, unsigned int, int);
extern void* lbl_805A0EC8;

struct Array {
    void* data;
    int size;
    unsigned int raw;

    bool isOwned() const {
        return (raw & 0x80000000) == 0;
    }

    void dealloc() {
        fn_8027EABC(lbl_805A0EC8, data, (raw & 0x3FFFFFFF) * 0x14, 0x15);
    }
};

struct Object {
    Array first;
    char padding[4];
    Array second;
};

extern "C" void* fn_802F5D88(Object* self, int flag) {
    if (self) {
        if ((char*)&self->second != 0 && self->second.isOwned()) {
            self->second.dealloc();
        }

        if (self != 0 && self->first.isOwned()) {
            self->first.dealloc();
        }

        if (flag > 0) {
            fn_8027EABC(lbl_805A0EC8, self, 0x20, 0x2D);
        }
    }

    return self;
}
