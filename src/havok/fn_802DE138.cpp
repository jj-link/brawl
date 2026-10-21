#pragma force_active on
#pragma use_lmw_stmw on

struct Node {
    unsigned short type;
    char pad[6];
    Node* next;
};

struct List {
    char pad[0x10];
    Node* first;
};

struct Object {
    char pad[0x28];
    List* list;
};

extern "C" void fn_802D9664(Node*, int, int, int, int, int, float);
extern "C" void fn_802D96F4(Node*, int, int, int, int, int, float);
extern "C" void fn_802D9900(Node*, int, int, int, int, int, float);

extern "C" void fn_802DE138(Object* self, int a, int b, int c, int d, int e, float f) {
    Node* node = self->list->first;
    if (node) {
        while ((int)node->type >= 23) {
            switch (node->type) {
            case 24:
                fn_802D9664(node, a, b, c, d, e, f);
                break;
            case 23:
                fn_802D96F4(node, a, b, c, d, e, f);
                break;
            case 26:
                fn_802D9900(node, a, b, c, d, e, f);
                break;
            }
            node = node->next;
        }
    }
}
