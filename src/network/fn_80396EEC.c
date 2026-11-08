#pragma force_active on
typedef struct Node {
    char pad[16];
    void *field10;
    void *field14;
    char pad18[8];
    struct Node *next;
} Node;
extern Node *lbl_805A1150;
extern void fn_8039094C(void);
extern void fn_80390950(int);

Node *fn_80396EEC(int arg0, Node *arg1, unsigned int arg2) {
    Node *node;
    Node **link;
    Node *result = 0;
    fn_8039094C();
    if (arg2 == 3) {
        result = arg1;
        arg1->next = lbl_805A1150;
        lbl_805A1150 = arg1;
    } else {
        link = &lbl_805A1150;
        while ((node = *link) != 0) {
            switch ((int)arg2) {
            case 0:
                if (node == arg1) result = node;
                break;
            case 1:
                if (node->field10 == arg1) result = node;
                break;
            case 2:
                if (node->field14 == arg1) result = node;
                break;
            case 4:
                if (node == arg1) {
                    result = node;
                    *link = node->next;
                }
                break;
            }
            if (result != 0) break;
            link = &(*link)->next;
        }
    }
    fn_80390950(arg0);
    return result;
}