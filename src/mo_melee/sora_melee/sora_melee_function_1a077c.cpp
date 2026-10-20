#pragma force_active on
struct acCmdInterpreterStackData;

template <class T, int N> class soArrayVector;

template <> class soArrayVector<acCmdInterpreterStackData, 1> {
public:
    int size() const;

private:
    unsigned int m_0;
    unsigned int m_4;
    unsigned int m_pad : 4;
    int m_count : 2;
    unsigned int m_rest : 26;
};

int soArrayVector<acCmdInterpreterStackData, 1>::size() const {
    return m_count;
}
