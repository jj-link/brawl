#pragma force_active on
class wnPikminPikmin;

template <class T, int N>
class soArrayList {
public:
    virtual void unused0();
    virtual void unused1();
    virtual void unused2();
    virtual int size();

    unsigned int flags;

    void set(long start, T const& value, long count);
};

template <class T, int N>
void soArrayList<T, N>::set(long start, T const& value, long count) {
    if (count != 0) {
        if (count + start >= size()) {
            count = size() - start;
        }

        int index = (int)((flags << 5) & 0xFC000000) >> 27;
        while (count > 0) {
            if (start > 0) {
                --start;
            } else {
                --count;
                *(T*)((char*)this + index * 12 + 0xc) = value;
            }

            index = *(signed char*)((char*)this + index * 12 + 0x11);
            if (index < 0) {
                break;
            }
        }
    }
}

template class soArrayList<wnPikminPikmin*, 10>;
