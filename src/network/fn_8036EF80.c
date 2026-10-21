#pragma force_active on
typedef struct {
    int field0;
    char pad0[4];
    int field8;
    char pad8[0x14];
    int next;
} Node;

int fn_8036EF80(void** arg0) {
    Node* cur = *(Node**)((char*)(*arg0) + 0x440);
    while (cur != 0) {
        if (cur->field8 != 0 && cur->field0 != 3) {
            return 1;
        }
        cur = (Node*)cur->next;
    }
    return 0;
}
