#pragma force_active on
class wnPikminPikmin;

template <typename T, int N>
class soArrayList {
public:
    virtual ~soArrayList();
    virtual void vf1();
    virtual void vf2();
    virtual int size() const;
    int getArrayIndex(long) const;
    void eraseSub(long);
    void pop();
};

template <>
void soArrayList<wnPikminPikmin*, 10>::pop() {
    eraseSub(getArrayIndex(size() - 1));
}
