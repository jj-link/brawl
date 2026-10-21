#pragma force_active on

struct Item {
    void* unk0;
    int key;
};

class WorkArray {
public:
    virtual void v0();
    virtual void v1();
    virtual Item* get(int);
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void set(int);
};

class Owner {
public:
    virtual void y0();
    virtual void y1();
    virtual void y2();
    virtual void y3();
    virtual int size();

    void* pad0;
    void* pad1;
    void* pad2;
    WorkArray m_array;

    int find(int id) {
        if (id <= -1)
            return -1;

        int n = size();
        for (int i = 0; i < n; ++i) {
            if (id == m_array.get(i)->key)
                return i;
        }
        return -1;
    }
};

extern "C" void fn_27_1C9D7C(Owner* self, int id) {
    int index = self->find(id);
    if (index >= 0)
        self->m_array.set(index);
}
