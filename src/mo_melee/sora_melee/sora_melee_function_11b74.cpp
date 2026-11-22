#pragma force_active on
struct List {
    void **items;
    int count;
    void setFirst(float value) {
        for (int i = 0; i < count; ++i)
            *(float *)((char *)items[i] + 0x1d4) = value;
    }
    void setSecond(float value) {
        for (int i = 0; i < count; ++i)
            *(float *)((char *)items[i] + 0x1e4) = value;
    }
    void setThird(float value) {
        for (int i = 0; i < count; ++i)
            *(float *)((char *)items[i] + 0x1e8) = value;
    }
};
struct Pair {
    List *a;
    List *b;
    void setFirst(float value) {
        a->setFirst(value);
        b->setFirst(value);
    }
    void setSecond(float value) {
        a->setSecond(value);
        b->setSecond(value);
    }
    void setThird(float value) {
        a->setThird(value);
        b->setThird(value);
    }
};
extern "C" void fn_27_11B74(char *arg0, float farg0, float farg1, float farg2) {
    List *l;
    Pair *p;
    l = *(List **)(arg0 + 0x28);
    if (l != 0) {
        int i;
        int off;
        l->setFirst(farg0);
        l = *(List **)(arg0 + 0x28);
        for (i = 0, off = 0; i < l->count; i++, off += 4)
            *(float *)((char *)*(void **)((char *)l->items + off) + 0x1e4) = farg1;
        l = *(List **)(arg0 + 0x28);
        for (i = 0, off = 0; i < l->count; i++, off += 4)
            *(float *)((char *)*(void **)((char *)l->items + off) + 0x1e8) = farg2;
        return;
    }
    p = *(Pair **)(arg0 + 0x2c);
    if (p == 0) return;
    p->setFirst(farg0);
    (*(Pair **)(arg0 + 0x2c))->setSecond(farg1);
    (*(Pair **)(arg0 + 0x2c))->setThird(farg2);
}