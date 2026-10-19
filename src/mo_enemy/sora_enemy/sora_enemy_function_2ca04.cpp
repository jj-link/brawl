#pragma force_active on
typedef unsigned char u8;
typedef int s32;

struct utListNode;

struct utList {
    void* head;
    void* tail;
    s32 count;

    s32 isExistNode(utListNode* node) const;
    void remove(utListNode* node);
    void addTail(utListNode* node);
};

struct emNodeOwner {
    u8 pad00[0x08];
    utList listA;
    utList listB;
    u8 flag;
};

extern "C" void fn_41_2CA04(emNodeOwner* self, utListNode* node) {
    if (self->flag == 0) {
        if (self->listB.isExistNode(node) != -1) {
            self->listB.remove(node);
            self->listA.addTail(node);
        }
    }
}
