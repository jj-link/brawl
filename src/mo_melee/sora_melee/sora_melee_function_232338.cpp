#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;

struct Node {
    Node* next;
    u8 pad[8];
    s32 id;
    u8 sub;
};

struct Owner {
    u8 pad[0x40];
    Node* head;
};

struct Key {
    u16 id;
    u8 pad;
    u8 sub;
};

extern "C" Node* fn_27_232338(Owner* self, const Key* key) {
    Node* n = self->head;
    while (n != 0) {
        if (n->id == key->id && n->sub == key->sub) {
            return n;
        }
        n = n->next;
    }
    return 0;
}
