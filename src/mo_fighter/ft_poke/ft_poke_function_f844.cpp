#pragma force_active on
typedef signed short s16;

struct acCmdInterpreterStackData;

template <class T, int N>
class soArrayVector {
public:
    ~soArrayVector();
};

extern "C" {
void* fn_116_F844(soArrayVector<acCmdInterpreterStackData, 1>* self, s16 flag) {
    if (self != 0) {
        self->~soArrayVector();
        if (flag > 0) {
            operator delete(self);
        }
    }
    return self;
}
}
