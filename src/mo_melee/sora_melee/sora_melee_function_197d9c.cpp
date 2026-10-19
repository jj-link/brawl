#pragma force_active on
class acCmdInterpreterStackData;

template <typename T>
class soArrayNull {
public:
    virtual ~soArrayNull() { }
};

template class soArrayNull<acCmdInterpreterStackData>;

namespace {
    soArrayNull<acCmdInterpreterStackData>* g_soArrayNullCmd;
    void disposeCmdArray(soArrayNull<acCmdInterpreterStackData>* p) {
        delete p;
    }
}
