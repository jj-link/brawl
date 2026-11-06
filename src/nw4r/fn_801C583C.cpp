#pragma force_active on

typedef unsigned char u8;

struct Node {
    u8 pad[0x32];
    u8 active;
    u8 pad2[0xAD];
    Node* next;
};

struct Object {
    u8 pad[0x5C];
    u8 flag;
    u8 pad2[0x5F];
    Node* head;
};

extern "C" u8* fn_801CC2E4();
extern "C" void OSLockMutex(void*);
extern "C" void OSUnlockMutex(void*);
extern "C" void fn_801C51F4(Object*);
extern "C" void fn_801BE2D4(Node*);
extern "C" void fn_801BE7A4(Node*);
extern "C" void fn_801BE33C(Node*);

extern "C" void fn_801C583C(Object* self, int arg1) {
    OSLockMutex(fn_801CC2E4() + 0x354);
    switch (arg1) {
    case 0:
        self->flag = 0;
        break;
    case 3: {
        OSLockMutex(fn_801CC2E4() + 0x354);
        for (Node* node = self->head; node != 0; node = node->next) {
            fn_801BE7A4(node);
            fn_801BE33C(node);
        }
        self->head = 0;
        OSUnlockMutex(fn_801CC2E4() + 0x354);
        self->flag = 1;
        break;
    }
    case 2: {
        OSLockMutex(fn_801CC2E4() + 0x354);
        fn_801C51F4(self);
        for (Node* node = self->head; node != 0; node = node->next) {
            if (node->active != 0) {
                fn_801BE2D4(node);
            }
        }
        OSUnlockMutex(fn_801CC2E4() + 0x354);
        OSLockMutex(fn_801CC2E4() + 0x354);
        for (Node* node = self->head; node != 0; node = node->next) {
            fn_801BE7A4(node);
        }
        self->head = 0;
        OSUnlockMutex(fn_801CC2E4() + 0x354);
        self->flag = 1;
        break;
    }
    case 1:
        self->flag = 1;
        break;
    }
    OSUnlockMutex(fn_801CC2E4() + 0x354);
}