#pragma force_active on
struct Node {
    Node* next;
    unsigned char padding[0x20 - sizeof(Node*)];
    unsigned int value20;
    unsigned int value24;
    unsigned int value28;
    unsigned char padding2[2];
    unsigned char flag;
};

extern "C" void fn_27_2323A0(void* object, unsigned int value)
{
    Node* node = *reinterpret_cast<Node**>(
        reinterpret_cast<unsigned char*>(object) + 0x40);

    while (node != 0) {
        if (node->value20 == value)
            node->flag = 1;
        if (node->value24 == value)
            node->flag = 1;
        if (node->value28 == value)
            node->flag = 1;
        node = node->next;
    }
}
