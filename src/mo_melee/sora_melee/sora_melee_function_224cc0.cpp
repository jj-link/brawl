#pragma force_active on
typedef unsigned char u8;

struct Color {
    u8 r, g, b, a;
};

struct Node {
    u8 pad[0x50];
    Node* next;
    u8 pad2[0x44];
    Color color;
};

struct Obj {
    u8 pad[0x88];
    Node* head;
};

extern "C" void fn_27_224CC0(Obj* obj, const Color* src) {
    Node* target;
    int index = 0;
    unsigned count = 0;
    Node* node = obj->head;

    while (node) {
        node = node->next;
        ++count;
    }

    for (; index != count; ++index) {
        target = obj->head;
        int remaining = index;

        while (remaining != 0 && target != 0) {
            target = target->next;
            --remaining;
        }

        if (target) {
            Color tmp = *src;
            target->color = tmp;
        }
    }
}
