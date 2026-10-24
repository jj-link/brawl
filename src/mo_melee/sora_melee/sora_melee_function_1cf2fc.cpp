#pragma force_active on

struct Entry {
    int pad0;
    int value;
};

class EntryList {
public:
    virtual void v0();
    virtual void v1();
    virtual Entry* get(int index);
    virtual int size();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual unsigned int v14();
};

class Owner {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual unsigned int v5();
    int pad[3];
    EntryList list;
};

extern "C" int fn_27_1CF2FC(Owner* self) {
    if (self->list.v14() == 1)
        return 0x7FFF;
    if (self->v5() == 1)
        return 0;
    int idx = self->list.size() - 1;
    if (self->list.get(idx)->value < 0x7FFF) {
        idx = self->list.size() - 1;
        return self->list.get(idx)->value + 1;
    }
    int saved;
    int i = self->list.size() - 1;
    while (i >= 0) {
        if (i == 0) {
            if (self->list.get(i)->value == 0)
                return -1;
            return self->list.get(i)->value - 1;
        }
        saved = self->list.get(i - 1)->value;
        if (self->list.get(i)->value - 1 > saved)
            return self->list.get(i)->value - 1;
        i--;
    }
    return -1;
}
