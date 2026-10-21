#pragma force_active on
struct FnNode {
    unsigned char pad[0x50];
    FnNode* next;
};

struct FnOwner {
    unsigned char pad[0x88];
    FnNode* head;
};

extern "C" void fn_27_261B94(FnNode* node);

extern "C" void fn_27_224B90(FnOwner* self) {
    unsigned int count = 0;
    unsigned int i = 0;
    FnNode* node = self->head;
    while (node != 0) {
        node = node->next;
        count++;
    }
    for (; i != count; i++) {
        FnNode* p = self->head;
        for (unsigned int j = i; j != 0 && p != 0; j--) {
            p = p->next;
        }
        if (p != 0) {
            fn_27_261B94(p);
        }
    }
}
