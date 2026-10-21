#pragma force_active on
namespace {
enum EnableState { Disabled = 0, Enabled = 1 };

class Elem {
public:
    virtual void pad0();
    virtual void update(void* arg);

    unsigned char b4;
    unsigned char enabled : 1;
    unsigned char rest : 7;
    unsigned char suspended;
};

class ElemArray {
public:
    virtual void s0();
    virtual Elem*** at(int index);
    virtual void s2();
    virtual int size();
};
}

extern "C" void fn_91_D258(void*, ElemArray* arr, void* arg) {
    for (int i = 0; i < arr->size(); ++i) {
        Elem* e = **arr->at(i);
        EnableState disabled = static_cast<EnableState>(
            ((static_cast<unsigned int>(
                reinterpret_cast<const unsigned char*>(e)[5]) & 0x80) >> 7) == 0);
        unsigned int active = disabled == 0;
        unsigned int suspension;

        if (active && (suspension = reinterpret_cast<const unsigned char*>(e)[6]) != 1) {
            if (active == true && suspension == 0) {
                if (active == true && suspension == 0) {
                    e->update(arg);
                }
            }
        }
    }
}
