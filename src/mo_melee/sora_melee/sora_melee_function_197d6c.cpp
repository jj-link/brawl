#pragma force_active on
class acCmdInterpreterStackData;

template <class T>
class soArrayNull {
public:
    void erase(long);
};

template <>
void soArrayNull<acCmdInterpreterStackData>::erase(long) {}
