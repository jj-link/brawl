#pragma force_active on
class acCmdInterpreterStackData;

template <class T> class soArrayNull;

template <>
class soArrayNull<acCmdInterpreterStackData> {
public:
    soArrayNull();
    virtual ~soArrayNull();
};

soArrayNull<acCmdInterpreterStackData>::soArrayNull() {}
