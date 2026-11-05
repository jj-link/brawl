#pragma force_active on
typedef struct Node {
    char pad[12];
    unsigned int list[3];
    unsigned int start;
    unsigned int end;
} Node;

extern Node *fn_80204FA8(void *, Node *);

#pragma dont_inline on
Node *fn_80203D0C(void *list, unsigned int addr)
{
    Node *b, *c, *a = 0, *result;

    while ((a = fn_80204FA8(list, a)) != 0) {
        if (a->start <= addr && addr < a->end) {
            b = 0;
            while ((b = fn_80204FA8(a->list, b)) != 0) {
                if (b->start <= addr && addr < b->end) {
                    Node *inner;
                    c = 0;
                    while ((c = fn_80204FA8(b->list, c)) != 0) {
                        if (c->start <= addr && addr < c->end) {
                            Node *child = fn_80203D0C(c->list, addr);
                            if (child != 0)
                                inner = child;
                            else
                                inner = c;
                            goto found_c;
                        }
                    }
                    inner = 0;
found_c:
                    if (inner != 0)
                        result = inner;
                    else
                        result = b;
                    goto found_b;
                }
            }
            result = 0;
found_b:
            if (result != 0)
                return result;
            return a;
        }
    }
    return 0;
}
