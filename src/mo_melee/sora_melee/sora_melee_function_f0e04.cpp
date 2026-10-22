#pragma force_active on

struct Item {
    int unk0;
    int unk4;
};

class Inner {
public:
    virtual void s2();
    virtual void s3();
    virtual Item* get(int index);
    virtual int count();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual unsigned int full();
};

class Outer {
public:
    virtual void o2();
    virtual void o3();
    virtual void o4();
    virtual void o5();
    virtual void o6();
    virtual unsigned int done();
    char pad[0xC];
    Inner m_inner;
};

extern "C" int fn_27_F0E04(Outer* self) {
    int n;
    int prev;
    int i;
    if (self->m_inner.full() == 1) {
        return 0x7FFF;
    }
    if (self->done() == 1) {
        return 0;
    }
    n = self->m_inner.count() - 1;
    if (self->m_inner.get(n)->unk4 < 0x7FFF) {
        n = self->m_inner.count() - 1;
        return self->m_inner.get(n)->unk4 + 1;
    }
    i = self->m_inner.count() - 1;
    while (i >= 0) {
        if (i == 0) {
            if (self->m_inner.get(i)->unk4 == 0) {
                return -1;
            }
            return self->m_inner.get(i)->unk4 - 1;
        }
        prev = self->m_inner.get(i - 1)->unk4;
        if (self->m_inner.get(i)->unk4 - 1 > prev) {
            return self->m_inner.get(i)->unk4 - 1;
        }
        i--;
    }
    return -1;
}
