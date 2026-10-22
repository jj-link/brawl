#pragma force_active on
namespace {
class KoopaElement {
public:
    virtual void reserved0();
    virtual void update(void* arg);
    unsigned char pad;
    unsigned char flags;
    unsigned char suspended;
};

class KoopaContainer {
public:
    virtual void reserved0();
    virtual KoopaElement*** at(int index);
    virtual void reserved16();
    virtual int size();
};
}

extern "C" void fn_102_B628(void*, KoopaContainer* container, void* arg) {
    for (int i = 0; i < container->size(); ++i) {
        KoopaElement* element = **container->at(i);
        enum EnableState { Disabled = 0, Enabled = 1 };
        EnableState disabled = static_cast<EnableState>(
            ((static_cast<unsigned int>(
                  reinterpret_cast<const unsigned char*>(element)[5]) &
              0x80) >>
             7) == 0);
        unsigned int enabled = disabled == 0;
        unsigned int suspension;

        if (enabled &&
            (suspension = element->suspended) != 1) {
            if (enabled == true && suspension == 0) {
                if (enabled == true && suspension == 0) {
                    element->update(arg);
                }
            }
        }
    }
}
