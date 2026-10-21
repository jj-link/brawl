#pragma force_active on
class Item {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s7(int arg);
};

class Container {
public:
    virtual void c0();
    virtual Item** c3(int idx);
    virtual void c4();
    virtual int c5();
};

class Owner {
public:
    char _00[0x30];
    Container* m_container;
    int m_index;
    char _38[0x7d - 0x38];
    unsigned char m_state;
};

extern "C" void fn_27_73EFC(Owner* self, int arg) {
    if (self->m_state == 1) {
        int idx = self->m_index;
        if (idx >= 0) {
            if (idx < self->m_container->c5()) {
                Item* item = *self->m_container->c3(idx);
                if (item) {
                    item->s7(arg);
                }
            }
        }
    }
}
