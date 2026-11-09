#pragma force_active on
class acCmdInterpreterStackData;

template <class T>
class soArrayNull {
public:
    void insert(long, const T&);
};

template <>
void soArrayNull<acCmdInterpreterStackData>::insert(long, const acCmdInterpreterStackData&) {}
