#pragma force_active on
extern "C" void set__40soArrayNull_25acCmdInterpreterStackData_FlRC25acCmdInterpreterStackDatal();

template <class T>
class soArrayNull {
public:
    void set(long, const T&, long);
};

class acCmdInterpreterStackData;

template <>
void soArrayNull<acCmdInterpreterStackData>::set(
    long, const acCmdInterpreterStackData&, long) {}
