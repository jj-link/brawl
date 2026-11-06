#pragma force_active on

class acCmdInterpreterStackData;

template <class T>
class soArrayNull {
public:
    void clear();
};

template <>
void soArrayNull<acCmdInterpreterStackData>::clear() {}
