#pragma force_active on
typedef unsigned short u16;
struct Node {
    char pad0[0xC];
    int state;
    char pad10[0xC8];
    int status;
    char padDC[6];
    u16 count;
};
struct System {
    char pad0[0x38];
    Node* first;
    char pad3C[6];
    u16 offset;
    char pad44[0x10];
    int value;
};
extern "C" void fn_8016DF20(System* self, int flag) {
    Node* node = self->first;
    self->value = 0;
    while (node) {
        if (!flag || node->count) {
            if (node->count)
                --node->count;
            if (node->state == 1 && node->status == 1)
                node->status = 0;
        }
        node = *(Node**)((char*)node + self->offset + 4);
    }
}