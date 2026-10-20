#pragma force_active on
class List {
public:
    virtual ~List();
    virtual void v1();
    virtual void v2();
    virtual int size();
};

class Owner {
public:
    virtual ~Owner();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void process(int index);
    unsigned char m_pad[0x30 - 0x04];
    List* m_list;
};

extern "C" {
void fn_27_39D10(Owner* self) {
    for (int i = 0; i < self->m_list->size(); i++) {
        self->process(i);
    }
}
}
