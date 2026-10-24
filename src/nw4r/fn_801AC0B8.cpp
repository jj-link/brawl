#pragma force_active on

struct Something {
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
    virtual int query(int index);
    unsigned char padding[0xD8];
    unsigned* array;
    int unknown;
    int count;
};

extern "C" bool fn_801AC0B8(Something* obj, unsigned value) {
    unsigned* i;
    unsigned* base;
    unsigned* end;
    base = obj->array;
    i = base;
    end = base + obj->count;
    while (i != end && *i != value) {
        i++;
    }
    if (i != end) {
        return obj->query(i - base) != 0;
    }
    return false;
}
