#pragma force_active on
#include <types.h>

extern "C" void OSLockMutex(void*);
extern "C" void OSUnlockMutex(void*);
extern "C" char* fn_801CC2E4();
extern "C" void fn_801D1210(void*, unsigned char);

struct FnListNode {
    unsigned char pad[0x31];
    unsigned char unk31;
    unsigned char unk32;
    unsigned char pad2[0xA9];
    void* unkDC;
    FnListNode* unkE0;
};

extern "C" void fn_801C5160(void* arg0, u8 arg1) {
    FnListNode* node;

    OSLockMutex(fn_801CC2E4() + 0x354);
    node = *(FnListNode**)((char*)arg0 + 0xBC);
    while (node != NULL) {
        if (node->unk32 != 0 && arg1 != (node->unk31 != 0)) {
            node->unk31 = arg1;
            fn_801D1210(node->unkDC, arg1);
        }
        node = node->unkE0;
    }
    OSUnlockMutex(fn_801CC2E4() + 0x354);
}
