#pragma force_active on
typedef struct Node {
    char padding[0x20];
    struct Node* next;
} Node;

extern Node* lbl_805A1150;
extern char lbl_80491A38[];
extern int fn_803F861C(const char*, ...);

void fn_803975B0(void) {
    Node* node = lbl_805A1150;
    if (node != 0) {
        int count = 0;
        while (node != 0) {
            node = node->next;
            count++;
        }
        if (count != 0) {
            fn_803F861C(lbl_80491A38, count);
        }
    }
    lbl_805A1150 = 0;
}
