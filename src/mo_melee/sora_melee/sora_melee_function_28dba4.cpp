#pragma force_active on
class BaseItemCtrl {
public:
    virtual void c0();
    virtual void c1();
    virtual void c2();
    virtual void c3();
    virtual void c4();
    virtual void c5();
    virtual void c6();
    virtual void c7();
    virtual void c8();
    virtual bool c9(int arg);
};

class BaseItemSub {
public:
    virtual int s0();
    virtual int s1();
    virtual int s2();
    virtual int s3();
    virtual int s4();
    virtual int s5();
    virtual int s6();
    virtual int s7();
    virtual int s8();
    virtual int s9();
    virtual int s10();
    virtual int s11();
    virtual int s12();
    virtual int s13();
    virtual int s14();
    virtual int s15();
    virtual int s16();
    virtual int s17();
    virtual int s18();
};

class BaseItemOwner {
public:
    char m_pad[0x70];
    BaseItemSub* m_sub;
};

class BaseItem {
public:
    bool isHaved();

    char m_pad1[0x1a4];
    BaseItemOwner* m_owner;
    char m_pad2[0x27a8 - 0x1a8];
    BaseItemCtrl m_ctrl;
};

bool BaseItem::isHaved() {
    if (m_owner->m_sub->s16() == 2) {
        return true;
    }
    return m_ctrl.c9(3);
}
