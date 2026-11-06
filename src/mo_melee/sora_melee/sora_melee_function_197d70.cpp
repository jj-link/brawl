#pragma force_active on

class acCmdInterpreterStackData;

template <class T>
class soArrayNull {
public:
    int capacity() const;
};

template <>
int soArrayNull<acCmdInterpreterStackData>::capacity() const {
    return 0;
}
