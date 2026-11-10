#pragma force_active on
extern "C" void fn_8027EABC(void*, void*, unsigned int, int);
extern "C" void __dl__FPv(void*);
extern "C" void fn_8008093C(void*);
extern "C" void fn_80080868(void*, int);
extern void* lbl_805A0EC8;
extern void* lbl_8049DEC8[3];

struct Array {
    void* data;
    int size;
    unsigned int raw;
    unsigned int rawValue() const { return raw; }
};
struct Child { char pad[0x114]; Array a; };
struct Object { void* unk; void* p; Array a; Array b; };
struct List { Object** data; int size; unsigned int raw; unsigned int rawValue() const { return raw; } int sizeValue() const { return size; } };
extern "C" List* fn_8009B32C(void*);
extern "C" Object* fn_80096774(Object* self, int flag) {
    if (self) {
        Child* child;
        int offset;
        int i = 0;
        offset = 0;
        for (; i < self->a.size; offset += 4, i++) {
            child = *(Child**)((char*)self->a.data + offset);
            if (child) {
                if ((unsigned int)child + 0x114 != 0 && !(child->a.raw & 0x80000000)) {
                    fn_8027EABC(lbl_805A0EC8, child->a.data, (child->a.rawValue() & 0x3fffffff) * 0x30, 0x15);
                }
                __dl__FPv(child);
            }
        }
        if (!(self->a.raw & 0x80000000)) {
            fn_8027EABC(lbl_805A0EC8, self->a.data, self->a.rawValue() << 2, 0x15);
        }
        self->a.data = 0;
        self->a.size = 0;
        self->a.raw = (self->a.raw & 0x40000000) | 0x80000000;
        if (!(self->b.raw & 0x80000000)) {
            fn_8027EABC(lbl_805A0EC8, self->b.data, self->b.rawValue() << 3, 0x15);
        }
        self->b.data = 0;
        self->b.size = 0;
        self->b.raw = (self->b.raw & 0x40000000) | 0x80000000;
        List* list = fn_8009B32C(lbl_8049DEC8[0]);
        int index;
        int byteOffset;
        index = 0;
        byteOffset = 0;
        for (int j = 0; j < list->size; byteOffset += 4, index++, j++) {
            if (*(Object**)((char*)list->data + byteOffset) == self) {
                if (list->sizeValue() == 1) {
                    if (!(list->raw & 0x80000000)) {
                        fn_8027EABC(lbl_805A0EC8, list->data, list->rawValue() << 2, 0x15);
                    }
                    list->data = 0;
                    list->size = 0;
                    list->raw = (list->raw & 0x40000000) | 0x80000000;
                } else {
                    list->size--;
                    list->data[index] = list->data[list->size];
                }
                break;
            }
        }
        fn_8008093C(self->p);
        fn_80080868(self->p, 1);
        if ((unsigned int)self + 0x14 != 0 && !(self->b.raw & 0x80000000)) {
            fn_8027EABC(lbl_805A0EC8, self->b.data, self->b.rawValue() << 3, 0x15);
        }
        if ((unsigned int)self + 8 != 0 && !(self->a.raw & 0x80000000)) {
            fn_8027EABC(lbl_805A0EC8, self->a.data, self->a.rawValue() << 2, 0x15);
        }
        if (flag > 0) __dl__FPv(self);
    }
    return self;
}