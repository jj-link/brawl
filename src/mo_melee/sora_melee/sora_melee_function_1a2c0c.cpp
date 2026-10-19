#pragma force_active on
extern "C" void __dl__FPv(void*);

template <class T, int N>
class soArrayVector {
public:
    ~soArrayVector();
};

class wnPikminPikmin;

template <>
soArrayVector<wnPikminPikmin*, 10>::~soArrayVector() {
    if (this != 0) {
        // The deleting-destructor flag is the second argument in the ABI.
        // This destructor body is intentionally empty.
    }
}
