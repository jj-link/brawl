#pragma force_active on
class acCmdInterpreterStackData;

template <class T>
class soArrayVectorAbstract {
public:
    bool isNull() const;
};

template <>
bool soArrayVectorAbstract<acCmdInterpreterStackData>::isNull() const {
    return false;
}
