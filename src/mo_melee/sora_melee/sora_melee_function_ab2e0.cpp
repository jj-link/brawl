#pragma force_active on
struct Node {
    char pad[0xc];
    void *field0c;
};

extern "C" {
void fn_27_AB2E0(Node *dst, Node *src)
{
    if (dst != src) {
        dst->field0c = src->field0c;
    }
}
}
