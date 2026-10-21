#pragma force_active on
#pragma opt_propagation off

namespace {
class PitElement {
public:
    virtual void reserved00();
    virtual void update(void* argument);
};

class PitElementArray {
public:
    virtual void reserved00();
    virtual PitElement*** at(int index);
    virtual void reserved10();
    virtual int size();
};
}

extern "C" void fn_112_D23C(void*, PitElementArray* elements, void* argument) {
    for (int i = 0; i < elements->size(); ++i) {
        PitElement* element = **elements->at(i);
        unsigned int disabled =
            ((static_cast<unsigned int>(
                  reinterpret_cast<const unsigned char*>(element)[5]) &
              0x80) >>
             7) == 0;
        unsigned int enabled = disabled == 0;
        unsigned int suspension;

        if (enabled &&
            (suspension = reinterpret_cast<const unsigned char*>(element)[6]) != 1) {
            if (enabled == true && suspension == 0) {
                if (enabled == true && suspension == 0) {
                    element->update(argument);
                }
            }
        }
    }
}
