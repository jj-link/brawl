#pragma force_active on
class soStatusData;

class soArrayInterface {
public:
    virtual ~soArrayInterface();
    virtual void slot1() = 0;
    virtual void slot2() = 0;
    virtual int size() const = 0;
};

template <class T>
class soArrayContractibleTable {
    void* m_vtable;
    soArrayInterface* m_next;
    T* m_data;
    int m_count;

public:
    int size() const;
};

template <>
int soArrayContractibleTable<const soStatusData>::size() const {
    int count = m_count;
    if (m_data == 0) {
        count = 0;
    }
    if (m_next != 0) {
        return count + m_next->size();
    }
    return count;
}
