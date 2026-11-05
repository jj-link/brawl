#pragma force_active on
extern "C" int fn_802D99B4(void*, int);

struct Node {
    unsigned short field_0;
    char pad[6];
    void* next;
};

extern "C" int fn_802D9A2C(void* arg0, int arg1) {
    int result = 0;
    Node* node = (Node*)arg0;
    while (1) {
        if ((int)node->field_0 < 0x17) break;
        result |= fn_802D99B4(node, arg1);
        node = (Node*)node->next;
    }
    return result;
}
