#pragma force_active on

typedef unsigned char u8;

struct Node {
    int type;
    u8 pad4[0x34 - 4];
    u8 active;
    u8 pad35[0xC8 - 0x35];
    int refCount;
    u8 padCC[0xE0 - 0xCC];
    Node* next;
};

struct Obj {
    u8 pad0[5];
    u8 flag;
    u8 pad6[0x60 - 6];
    u8 flag60;
    u8 pad61[0xBC - 0x61];
    Node* head;
};

extern "C" {
    char* fn_801CC2E4();
    void OSLockMutex(void* m);
    void OSUnlockMutex(void* m);
    void fn_801BE2D4(Node* n);
    void fn_801BE444(Node* n, int x);
}

extern "C" void fn_801C4EBC(Obj* self) {
    Node* node;
    OSLockMutex(fn_801CC2E4() + 0x354);
    if (self->flag == 0) {
        OSUnlockMutex(fn_801CC2E4() + 0x354);
        return;
    }
    for (node = self->head; node != 0; node = node->next) {
        if (node->refCount > 0) {
            node->refCount--;
        }
        OSLockMutex(fn_801CC2E4() + 0x354);
        if (node->refCount == 0 && node->type != 3 && self->flag60 == 0) {
            fn_801BE2D4(node);
        }
        OSUnlockMutex(fn_801CC2E4() + 0x354);
        if (node->active == 0) {
            fn_801BE444(node, 1);
        }
    }
    OSUnlockMutex(fn_801CC2E4() + 0x354);
}
