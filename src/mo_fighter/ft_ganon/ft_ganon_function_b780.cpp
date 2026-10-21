#pragma force_active on
extern "C" int __cntlzw(unsigned int);

namespace {
class Elem {
public:
    virtual void reserved00() = 0;
    virtual void update(void* arg) = 0;
};

struct Unit {
    Elem* energy;
};

class UnitArray {
public:
    virtual void reserved00() = 0;
    virtual Unit*& at(int index) = 0;
    virtual void reserved10() = 0;
    virtual int size() const = 0;
};
}

extern "C" void fn_109_B780(void*, UnitArray* units, void* arg) {
    for (int i = 0; i < units->size(); ++i) {
        Elem* energy = units->at(i)->energy;
        unsigned int disabled =
            static_cast<unsigned int>(__cntlzw(
                (reinterpret_cast<const unsigned char*>(energy)[5] >> 7) & 1)) >> 5;
        unsigned int enabled =
            static_cast<unsigned int>(__cntlzw(disabled)) >> 5;
        unsigned int suspension;

        if (enabled &&
            (suspension = reinterpret_cast<const unsigned char*>(energy)[6]) != 1) {
            if (enabled == true && suspension == 0) {
                if (enabled == true && suspension == 0) {
                    energy->update(arg);
                }
            }
        }
    }
}
