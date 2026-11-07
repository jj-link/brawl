#pragma force_active on
class acCmdInterpreterStackData;

template <class T>
class soArrayNull {
public:
    void shift();
};

template <>
void soArrayNull<acCmdInterpreterStackData>::shift() {}
