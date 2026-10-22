#pragma force_active on
struct Obj {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual int find(int index);
};

extern "C" bool fn_801B5138(Obj* self, unsigned int value) {
    unsigned int* cur;
    unsigned int* base = *(unsigned int**)((unsigned char*)self + 0xDC);
    unsigned int* end = base + *(unsigned int*)((unsigned char*)self + 0xE4);
    cur = base;
    while (cur != end && *cur != value) {
        cur++;
    }
    if (cur == end) {
        return 0;
    }
    return self->find(cur - base) != 0;
}
