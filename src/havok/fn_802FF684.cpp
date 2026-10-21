#pragma force_active on

struct Node;

struct Slot {
    Node* node;
    int value;
};

struct Owner {
    char pad[0x24];
    Slot* slots;
};

struct Node {
    char pad0[0xC];
    unsigned short index0;
    unsigned short index1;
    int pad10;
    Owner* owner0;
    Owner* owner1;
};

struct Pool {
    char** data;
    int size;
    unsigned int capacity;
    int padC;
    unsigned int offset;
    unsigned short stride;
    unsigned short blockSize;
};

extern void* lbl_805A0EC8;

extern "C" char* fn_8027EA20(void*, unsigned int, int);
extern "C" void fn_8027CE3C(Pool*, int);
extern "C" void fn_80281BBC(Node*, int, unsigned short, char*);

extern "C" Node* fn_802FF684(Pool* self, int arg) {
    if (self->offset == self->blockSize) {
        char* block = fn_8027EA20(lbl_805A0EC8, self->blockSize, 0x25);
        if (self->size == (int)(self->capacity & 0x3FFFFFFF)) {
            fn_8027CE3C(self, 4);
        }
        self->data[self->size++] = block;
        self->offset = 0;
    }

    unsigned short stride = self->stride;
    char* block = self->data[self->size - 1];
    Node* node = (Node*)(block + self->offset);
    self->offset += stride;
    fn_80281BBC(node, arg, stride, block);

    unsigned short index0 = node->index0;
    unsigned short index1 = node->index1;
    node->owner0->slots[index0].node = node;
    node->owner1->slots[index1].node = node;
    return node;
}
