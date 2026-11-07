#pragma force_active on

class acCmdInterpreterStackData;

template <class T>
class soArrayNull {
public:
    bool isNull() const;
};

template <>
bool soArrayNull<acCmdInterpreterStackData>::isNull() const {
    return true;
}
