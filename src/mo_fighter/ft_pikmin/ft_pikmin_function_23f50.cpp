#pragma force_active on
#pragma scheduling off

class wnPikminPikmin;

struct ArrayBase {};

template <class T, int N>
class soArrayList : virtual public ArrayBase {
    char data[0x78];

public:
    soArrayList();
};

extern "C" void* fn_113_23F50(void* self)
{
    char* p = static_cast<char*>(self);
    reinterpret_cast<soArrayList<wnPikminPikmin*, 10>*>(p)->__ct(0);
    reinterpret_cast<soArrayList<wnPikminPikmin*, 10>*>(p + 0x80)->__ct(0);
    reinterpret_cast<soArrayList<wnPikminPikmin*, 10>*>(p + 0x100)->__ct(0);
    *reinterpret_cast<int*>(p + 0x180) = 4;
    return self;
}
