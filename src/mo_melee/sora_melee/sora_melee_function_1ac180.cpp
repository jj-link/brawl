#pragma force_active on

struct Entry {
    int pad[2];
    int val;
};

class Arr {
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
    virtual unsigned full();
};

class Owner {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual unsigned check();
    char pad[12];
    Arr m_arr;
};

extern "C" int fn_27_1AC180(Owner* self) {
    if (self->m_arr.full() == 1)
        return 0x7FFF;
    if (self->check() == 1)
        return 0;
    int idx = self->m_arr.size() - 1;
    if (self->m_arr.get(idx)->val < 0x7FFF) {
        idx = self->m_arr.size() - 1;
        return self->m_arr.get(idx)->val + 1;
    }
    int prev;
    int i = self->m_arr.size() - 1;
    while (i >= 0) {
        if (i == 0) {
            if (self->m_arr.get(i)->val == 0)
                return -1;
            return self->m_arr.get(i)->val - 1;
        }
        prev = self->m_arr.get(i - 1)->val;
        if (self->m_arr.get(i)->val - 1 > prev)
            return self->m_arr.get(i)->val - 1;
        i--;
    }
    return -1;
}
