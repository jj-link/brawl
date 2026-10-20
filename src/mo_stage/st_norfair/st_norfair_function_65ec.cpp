#pragma force_active on
typedef struct Node {
    int pad[2];
    unsigned int v;
} Node;

extern "C" {
int fn_54_65EC(Node *p)
{
    return (int)(((p->v << 2)) & 0xE0000000u) >> 30;
}
}
