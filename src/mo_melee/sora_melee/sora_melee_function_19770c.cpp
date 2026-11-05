#pragma force_active on
class wnPikminPikmin;
struct Entry { signed char a, b; char pad[10]; };
template <class T, int N>
class soArrayList {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int size() const;
    int : 5;
    int first : 5;
    int last : 5;
    char pad[10];
    Entry e[1];
    int getArrayIndex(long idx) const;
};
template <class T, int N>
int soArrayList<T, N>::getArrayIndex(long idx) const {
    if (idx < 0 || idx >= size()) return -1;
    if (idx == 0) return first;
    if (idx == size() - 1) return last;
    int n = idx;
    int cur = first;
    if (idx > size() / 2) {
        n = size() - idx - 1;
        cur = last;
    }
    for (int i = 0; i < size(); i++) {
        if (i == n) return cur;
        if (idx > size() / 2) cur = e[cur].a;
        else cur = e[cur].b;
        if (cur < 0) break;
    }
    return -1;
}
template class soArrayList<wnPikminPikmin*, 10>;
