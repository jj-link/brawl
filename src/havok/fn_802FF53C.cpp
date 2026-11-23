#pragma force_active on
struct Pool {
    char** data;
    int size;
    unsigned int capacity;
    inline int getCapacity() const { return capacity & 0x3fffffff; }
    int padC;
    unsigned int offset;
    unsigned short stride;
    unsigned short blockSize;
};

extern void* lbl_805A0EC8;

extern "C" void fn_8027CEF4(Pool*, int, void*, int);
extern "C" void fn_8027EABC(void*, void*, unsigned int, int);
extern "C" void* fn_802FF684(Pool*, int);
extern "C" void fn_803004F4(Pool*, int, Pool*);

extern "C" void fn_802FF53C(Pool* self, Pool* other) {
    while (self->offset != self->blockSize && other->size != 0) {
        fn_802FF684(
            self,
            (int)(other->data[*(unsigned int*)((char*)other + 4) - 1] +
                  (other->offset - other->stride))
        );

        other->offset -= other->stride;
        if (other->offset == 0) {
            char* block = other->data[(unsigned int)other->size - 1];
            *(unsigned int*)((char*)other + 4) -= 1;

            if (!(other->capacity & 0x80000000)) {
                if (other->size + 1 < 1 ||
                    (int)((unsigned int)(other->size + 1) * 2) <
                        other->getCapacity()) {
                    fn_8027CEF4(other, 4, &other->padC, 1);
                }
            }

            fn_8027EABC(lbl_805A0EC8, block, other->blockSize, 0x25);
            other->offset = other->blockSize;
        }
    }

    if (other->size != 0) {
        fn_803004F4(self, self->size, other);
        self->offset = other->offset;
        other->size = 0;
        other->offset = self->blockSize;
    }
}
