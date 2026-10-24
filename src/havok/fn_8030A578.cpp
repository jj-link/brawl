#pragma force_active on

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern "C" void fn_8027EABC(void*, void*, unsigned int, int);
extern void* lbl_805A0EC8;
extern u8 lbl_804888F0[];

class SoHeapAllocator {
public:
    virtual void vf0();
    virtual void release(void*);
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void free(void*, unsigned short, int);
};

extern SoHeapAllocator* lbl_805A0EB8;

template <class T> struct Array {
    T* data;
    int size;
    u32 raw;

    bool isOwned() const {
        return (raw & 0x80000000) == 0;
    }

    void dealloc() {
        fn_8027EABC(lbl_805A0EC8, data,
                   (raw & 0x3FFFFFFF) * sizeof(T), 0x15);
    }

    void destroy() {
        if (this) {
            if (isOwned()) {
                dealloc();
            }
        }
    }
};

struct Entry {
    u32 unk0;
    Array<u16> array;

    void destroy() {
        if (this) {
            array.destroy();
        }
    }
};

struct Obj {
    void* vtable;
    u16 type;
    u8 pad06[0x6A];
    Array<Entry> array;
    u8 pad7C[0x24];
    int count;
    int unkA4;
    Entry* list;
};

extern "C" {
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dt__14Class_8030A51CFv(void*, int);
void __dt__14Class_80312FD8Fv(void*, int);

void* fn_8030A578(Obj* self, int deleting) {
    if (self) {
        self->vtable = lbl_804888F0;

        int off;
        int i = 0;
        off = 0;
        for (; i < self->count; off += 0x10, ++i) {
            Entry* e = (Entry*)((u8*)self->list + off);
            e->destroy();
        }

        lbl_805A0EB8->release(self->list);
        __destroy_arr((u8*)self + 0x7C,
                      __dt__14Class_8030A51CFv, 0xC, 3);
        self->array.destroy();
        __dt__14Class_80312FD8Fv(self, 0);

        if (deleting > 0) {
            lbl_805A0EB8->free(self, self->type, 0x1F);
        }
    }
    return self;
}
}
