#pragma force_active on
class wnPikminPikmin;

template <class T, int N>
class soArrayVector {
public:
    int size() const;
    int unk0;
    int unk4;
    unsigned int unk8;
};

template <>
int soArrayVector<wnPikminPikmin*, 10>::size() const {
    unsigned int v = (unk8 << 10) | (unk8 >> 22);
    return (int)(v & 0xFC000000) >> 27;
}
