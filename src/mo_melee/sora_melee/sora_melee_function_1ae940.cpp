#pragma force_active on
class soKineticEnergy;

template <class T, int N>
class soInstanceManagerFullPropertyVector {
public:
    struct Entry {
        int a;
        int b;
        int c;
    };

    void* atIndexFast(long idx);

    int m_00[6];
    int m_18;
    Entry m_1c[N];
};

template <class T, int N>
void* soInstanceManagerFullPropertyVector<T, N>::atIndexFast(long idx) {
    int i = (m_18 >> 28) + idx;
    if (i >= N) {
        i -= N;
    }
    return &m_1c[i];
}

template class soInstanceManagerFullPropertyVector<soKineticEnergy*, 4>;
