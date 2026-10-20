#pragma force_active on
typedef unsigned int u32;

struct Vec2 {
    float x;
    float y;
};

struct Data {
    u32 a;
    float x;
    float y;
    u32 pad;
    u32 key;
};

struct Node {
    void* unk0;
    Node* next;
    Data* data;
};

struct List {
    void* unk0;
    Node* head;
    void* unk8;
    Node* cur;
    u32 count;
};

extern "C" void fn_27_2723D0(List* list, const Vec2* v, u32 key) {
    list->cur = list->head;
    u32 n = list->count;
    for (u32 i = 0; i < n; i++) {
        Node* node = list->cur;
        Data* d = node->data;
        if (key == d->key) {
            d->x = v->x;
            d->y = v->y;
            return;
        }
        list->cur = node->next;
    }
}
