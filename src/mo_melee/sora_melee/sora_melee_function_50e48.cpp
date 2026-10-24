#pragma force_active on

class Element {
public:
    int field0;
    int field4;
};

class SubObj {
public:
    virtual void v0();
    virtual void v1();
    virtual Element* get(int index);
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
    virtual unsigned check();
};

class Self {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual unsigned v5();
    int pad[3];
    SubObj m_sub;
};

extern "C" int fn_27_50E48(Self* self) {
    if (self->m_sub.check() == 1) {
        return 0x7FFF;
    }
    if (self->v5() == 1) {
        return 0;
    }
    int idx = self->m_sub.size() - 1;
    if (self->m_sub.get(idx)->field4 < 0x7FFF) {
        idx = self->m_sub.size() - 1;
        return self->m_sub.get(idx)->field4 + 1;
    }
    int saved;
    int i = self->m_sub.size() - 1;
    while (i >= 0) {
        if (i == 0) {
            if (self->m_sub.get(i)->field4 == 0) {
                return -1;
            }
            return self->m_sub.get(i)->field4 - 1;
        }
        int prev_idx = i - 1;
        saved = self->m_sub.get(prev_idx)->field4;
        if (self->m_sub.get(i)->field4 - 1 > saved) {
            return self->m_sub.get(i)->field4 - 1;
        }
        i--;
    }
    return -1;
}
