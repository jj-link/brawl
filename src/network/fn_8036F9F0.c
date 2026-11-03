#pragma force_active on
typedef struct Node Node;
struct Node {
    int unk0, unk4, sock, unkC;
    int unk10, unk14, unk18;
    void *unk1C;
    int unk20, unk24, unk28;
    void *unk2C;
    int unk30, unk34, unk38;
    void *unk3C;
    Node *next;
};
typedef struct { char pad[0x450]; Node *head; } State;
typedef struct { int base, unk4, unk8, unkC, count, offset; } Entry;
extern int fn_8035A590(void *);
extern Entry *fn_8035A598(void *, int);
extern void fn_8035A918(void *, int);
extern void fn_80369C64(void *, int, int, int);
extern void fn_8035C2D8(int, int);
extern void closesocket(int);
extern void fn_8035E00C(void *);
extern void fn_8035A4FC(void *);

void fn_8036F9F0(State **self, Node *node) {
    State *state = *self;
    Node *cur = state->head;
    Entry *entry;
    if (cur == node) {
        state->head = node->next;
    } else {
        while (cur->next != node) {
            if (cur->next == 0)
                return;
            cur = cur->next;
        }
        cur->next = node->next;
    }
    while (fn_8035A590(node->unk3C) != 0) {
        entry = fn_8035A598(node->unk3C, 0);
        if (entry->count < 100)
            fn_80369C64(self, node->unkC, entry->count, entry->base + entry->offset);
        fn_8035A918(node->unk3C, 0);
    }
    fn_8035C2D8(node->sock, 2);
    closesocket(node->sock);
    fn_8035E00C(node->unk1C);
    node->unk1C = 0;
    fn_8035E00C(node->unk2C);
    node->unk2C = 0;
    if (node->unk3C != 0) {
        fn_8035A4FC(node->unk3C);
        node->unk3C = 0;
    }
    fn_8035E00C(node);
}