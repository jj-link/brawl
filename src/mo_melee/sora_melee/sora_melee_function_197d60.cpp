#pragma force_active on
class acCmdInterpreterStackData;

template <class T>
class soArrayNull {
public:
    void unshift(const T&);
};

template <>
void soArrayNull<acCmdInterpreterStackData>::unshift(const acCmdInterpreterStackData&) {}
