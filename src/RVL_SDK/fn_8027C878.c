#pragma force_active on
struct Obj {
    int pad0;
    struct Obj* next;
    char pad8[0x10];
    int base;
    int count;
};

int fn_8027C854(struct Obj* o);

int fn_8027C878(struct Obj* o, int index)
{
    struct Obj* node;
    int pos;

    pos = index - fn_8027C854(o);
    node = o;
    while (node != 0) {
        pos += node->count;
        if (pos >= 0) {
            return node->base + pos * 0x14;
        }
        node = node->next;
    }
    return o->base;
}
