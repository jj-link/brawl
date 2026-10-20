#pragma force_active on
struct acCmdInterpreterStackData;

template <typename T, int N>
class soArrayVector {
public:
    void onFull();
    unsigned int m_0;
    unsigned int m_4;
    unsigned int m_8;
};

template <>
void soArrayVector<acCmdInterpreterStackData, 1>::onFull() {
    m_8 |= 0x02000000;
}
