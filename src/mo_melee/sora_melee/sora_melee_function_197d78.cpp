#pragma force_active on

class acCmdInterpreterStackData;

template <class T>
class soArrayNull {
public:
    bool isFull() const;
};

template <>
bool soArrayNull<acCmdInterpreterStackData>::isFull() const {
    return true;
}
