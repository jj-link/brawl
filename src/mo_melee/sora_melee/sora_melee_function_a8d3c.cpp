#pragma force_active on

struct Ids {
    int values[4];
};

struct Object {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual unsigned int disabled();
    virtual void v9();
    virtual void v10();
    virtual unsigned int test(int);

    char pad04[0x35];
    unsigned char enabled;
    char pad3A[6];
    Ids ids;

    bool selected(unsigned int mask, int id) {
        bool result;
        if (enabled == 0) {
            result = false;
        } else {
            result = ((1 << id) & mask) != 0;
        }
        return result;
    }
};

extern "C" bool fn_27_A8D3C(Object* self, unsigned int mask) {
    Ids ids = self->ids;
    if (self->disabled() == 1U)
        return false;

    for (int i = 0; i < 4; ++i) {
        int id = ids.values[i];
        if (id != -1 && self->selected(mask, id) && self->test(id) == 1U)
            return true;
    }
    return false;
}
