#pragma force_active on
struct Pair {
    int x;
    int y;
};
struct Entry {
    Pair p0;
    int c;
    Pair p1;
    int f;
};
struct Object {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual int method(int, int);
    unsigned char padding[0x9C - 4];
    Entry slots[2];
};
extern "C" int fn_801AB0E0(Object* self, int index, Entry* src)
{
    if (src != 0) {
        if (index < 2) {
            self->slots[index] = *src;
            return self->method(9, 1);
        } else {
            return 0;
        }
    }
    return self->method(9, 0);
}