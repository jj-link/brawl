#pragma force_active on

struct Slot;
struct Owner;

struct Node {
    char pad0[0xC];
    unsigned short index0;
    unsigned short index1;
    char pad10[0x14 - 0x10];
    Owner* owner0;
    Owner* owner1;
};

struct Slot {
    Node* node;
    int pad;
};

struct Owner {
    char pad[0x24];
    Slot* slots;
};

struct Pool {
    void** data;
    int size;
    unsigned int capacity;
    inline int getCapacity() const { return capacity & 0x3fffffff; }
    char embed[4];
    unsigned int offset;
    unsigned short stride;
    unsigned short blockSize;
};

extern void* lbl_805A0EC8;
extern "C" void fn_80281BBC(void*, void*);
extern "C" void fn_8027CEF4(void*, int, void*, int);
extern "C" void fn_8027EABC(void*, void*, unsigned int, int);

extern "C" void fn_802FF278(Pool* self, Node* node) {
    char* block = (char*)self->data[self->size - 1];
    char* last = block + (self->offset - self->stride);

    if ((char*)node != last) {
        fn_80281BBC(node, last);
        int i0 = node->index0;
        int i1 = node->index1;
        node->owner0->slots[i0].node = node;
        node->owner1->slots[i1].node = node;
    }

    self->offset -= self->stride;

    if (self->offset == 0) {
        Node* freed = (Node*)self->data[self->size - 1];
        self->size = self->size - 1;

        if ((self->capacity & 0x80000000) == 0) {
            int n = self->size + 1;
            if (n < 1 || n * 2 < self->getCapacity()) {
                fn_8027CEF4(self, 4, (char*)self + 0xC, 1);
            }
        }

        fn_8027EABC(lbl_805A0EC8, freed, self->blockSize, 0x25);
        self->offset = self->blockSize;
    }
}
