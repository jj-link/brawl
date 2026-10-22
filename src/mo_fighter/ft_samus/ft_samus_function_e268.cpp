#pragma force_active on
namespace {
class E {
public:
    virtual void reserved0();
    virtual void update(void* arg);
};
class C {
public:
    virtual void reserved0();
    virtual E*** at(int index);
    virtual void reserved10();
    virtual int size();
};
}

extern "C" void fn_94_E268(void*, C* container, void* arg) {
    for (int i = 0; i < container->size(); ++i) {
        E* element = **container->at(i);
        enum EnableState { Disabled = 0, Enabled = 1 };
        EnableState disabled = static_cast<EnableState>(
            ((static_cast<unsigned int>(
                  reinterpret_cast<const unsigned char*>(element)[5]) &
              0x80) >>
             7) == 0);
        unsigned int enabled = disabled == 0;
        unsigned int suspension;

        if (enabled &&
            (suspension = reinterpret_cast<const unsigned char*>(element)[6]) != 1) {
            if (enabled == true && suspension == 0) {
                if (enabled == true && suspension == 0) {
                    element->update(arg);
                }
            }
        }
    }
}
