#pragma force_active on
class acCmdInterpreterStackData;

template <class T>
class soArrayNull {
public:
    void pop();
};

template <>
void soArrayNull<acCmdInterpreterStackData>::pop() {}
