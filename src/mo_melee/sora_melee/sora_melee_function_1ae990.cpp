#pragma force_active on

class soKineticEnergy;

struct Entry {
    int pad;
    int value;
};

class Array {
public:
    virtual void v0();
    virtual void v1();
    virtual Entry* at(int index) const;
    virtual int size() const;
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
    virtual unsigned int isFull() const;
};

class ManagerBase {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual bool isEmpty() const;
    char pad[12];
};

template <class T, int N>
class soInstanceManagerFullPropertyVector : public ManagerBase {
public:
    Array m_array;
    int getFreeId() const;
};

template <>
int soInstanceManagerFullPropertyVector<soKineticEnergy*, 4>::getFreeId() const {
    if (m_array.isFull() == 1)
        return 0x7FFF;
    if (isEmpty() == 1)
        return 0;

    int idx = m_array.size() - 1;
    if (m_array.at(idx)->value < 0x7FFF) {
        idx = m_array.size() - 1;
        return m_array.at(idx)->value + 1;
    }

    int i = m_array.size() - 1;
    while (i >= 0) {
        if (i == 0) {
            if (m_array.at(i)->value == 0)
                return -1;
            return m_array.at(i)->value - 1;
        }
        if (m_array.at(i)->value - 1 > m_array.at(i - 1)->value)
            return m_array.at(i)->value - 1;
        i--;
    }
    return -1;
}
