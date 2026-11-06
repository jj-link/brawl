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

extern "C" {

void fn_802D95F8(Node* node, int a, int b, int c, int d, int e);
void fn_802D9668(Node* node, int a, int b, int c, int d, int e);
void fn_802D984C(Node* node, int a, int b, int c, int d, int e);

void fn_802DE058(Object* self, int a, int b, int c, int d, int e) {
    Node* node = self->list->first;
    if (node) {
        while ((int)node->type >= 0x17) {
            switch (node->type) {
            case 0x18:
                fn_802D95F8(node, a, b, c, d, e);
                break;
            case 0x17:
                fn_802D9668(node, a, b, c, d, e);
                break;
            case 0x19:
                break;
            case 0x1A:
                fn_802D984C(node, a, b, c, d, e);
                break;
            default:
                break;
            }
            node = node->next;
        }
    }
}

}