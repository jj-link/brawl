#pragma force_active on
void operator delete(void*);

template <class T, int N>
class soArrayList {
public:
    ~soArrayList();
};

class wnPikminPikmin;
typedef soArrayList<wnPikminPikmin*, 10> PikminList;

extern "C" void* fn_113_6300(void* object, short deleting) {
    if (object != 0) {
        reinterpret_cast<PikminList*>(static_cast<unsigned char*>(object) + 0x100)->~PikminList();
        reinterpret_cast<PikminList*>(static_cast<unsigned char*>(object) + 0x80)->~PikminList();
        reinterpret_cast<PikminList*>(object)->~PikminList();
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
