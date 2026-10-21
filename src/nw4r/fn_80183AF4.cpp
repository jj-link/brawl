#pragma force_active on
extern "C" char lbl_80465700[];
extern "C" const float lbl_805A30D0;

struct Node {
    Node* next;
    Node* prev;

    Node() : next(0), prev(0) {}

    void init() {
        next = this;
        prev = this;
    }
};

struct Obj {
    void* vt;
    int count;
    Node node;
    int unk10;
    int unk14;
    float unk18;
    float unk1C;
    unsigned char unk20;
};

inline Node* initializeNode(Node* node) {
    node->next = 0;
    node->prev = 0;
    return node;
}

extern "C" void fn_80183AF4(Obj* self) {
    Node* p = initializeNode(&self->node);
    self->vt = lbl_80465700;
    self->count = 0;
    p->next = p;
    p->prev = p;
    self->unk10 = 0;
    self->unk14 = 0;
    self->unk18 = lbl_805A30D0;
    self->unk1C = lbl_805A30D0;
    self->unk20 = 0;
}
