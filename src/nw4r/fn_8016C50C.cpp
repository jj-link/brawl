#pragma force_active on
typedef unsigned short u16;
typedef unsigned int u32;

struct NodeBase {
    char pad0[0xc];
    int state;   // 0xc
    int flag;    // 0x10
    char pad1[0x1c - 0x14];
};

class Node : public NodeBase {
public:
    virtual void slot0();          // offset 0x8
    virtual void slot1(u16 n);     // offset 0xc
};

struct Owner {
    char pad0[0x38];
    Node* head;   // 0x38
    char pad1[0x42 - 0x3c];
    u16 linkOff;  // 0x42
    char pad2[0x50 - 0x44];
    u16 counter;  // 0x50
};

extern "C" int fn_8016C50C(Owner* self) {
    int count = 0;
    Node* node = self->head;
    while (node != 0) {
        Node* next = *(Node**)((char*)node + self->linkOff + 4);
        if (node->state == 1) {
            int inc;
            if (node->state != 1) {
                inc = 0;
            } else {
                u16 old = self->counter;
                self->counter = old - 1;
                node->slot1(old);
                node->state = 2;
                if (node->flag == 0) {
                    node->slot0();
                }
                inc = 1;
            }
            count += inc;
        }
        node = next;
    }
    return count;
}
