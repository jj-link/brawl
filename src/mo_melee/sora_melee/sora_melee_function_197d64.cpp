#pragma force_active on
class acCmdInterpreterStackData;

template <class T>
class soArrayNull {
public:
    void push(const T&);
};

template <>
void soArrayNull<acCmdInterpreterStackData>::push(const acCmdInterpreterStackData&) {}
