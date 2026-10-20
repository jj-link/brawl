#pragma force_active on
class wnPikminPikmin;

struct Unit {
    unsigned char inUse;
    unsigned char pad[3];
    wnPikminPikmin* element;
    signed char prev;
    signed char next;
    unsigned char pad2[2];
};

template <class T, long N>
class soArrayList {
public:
    virtual void vf();
    long insertSub(long, long);
    void insert(long, T const&);
private:
    int _data;
    Unit _units[N];
};

void soArrayList<wnPikminPikmin*, 10>::insert(long pos, wnPikminPikmin* const& elm) {
    long idx = insertSub(pos - 1, -1);
    if (idx >= 0)
        _units[idx].element = elm;
}