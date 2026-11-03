#pragma force_active on
class acCmdInterpreterStackData;

template <class T>
class soArrayNull {
public:
    int size() const;
};

template <>
int soArrayNull<acCmdInterpreterStackData>::size() const {
    return 0;
}
