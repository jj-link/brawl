#pragma force_active on
class wnPikminPikmin;

template <class T, int N>
class soArrayList {
public:
    void* m_0;
    int m_4;
    bool isFull() const;
};

template <class T, int N>
bool soArrayList<T, N>::isFull() const {
    return (m_4 >> 27) < 0;
}

template bool soArrayList<wnPikminPikmin*, 10>::isFull() const;
