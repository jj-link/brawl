#pragma force_active on
#pragma opt_propagation off

namespace {
class FtPitElement {
public:
    virtual void reserved00();
    virtual void update(void* argument);
};

class FtPitContainer {
public:
    virtual void reserved00();
    virtual FtPitElement*** at(int index);
    virtual void reserved10();
    virtual int size();
};
}

extern "C" void fn_112_1210C(void*, FtPitContainer* container, void* argument) {
    for (int i = 0; i < container->size(); ++i) {
        FtPitElement* element = **container->at(i);
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
