#pragma force_active on
namespace {
class Energy {
public:
    virtual void reserved0();
    virtual void update(void* arg);
};

class EnergyContainer {
public:
    virtual void reserved0();
    virtual Energy*** at(int index);
    virtual void reserved10();
    virtual int size();
};
}

extern "C" void fn_92_C010(void*, EnergyContainer* container, void* arg) {
    for (int i = 0; i < container->size(); ++i) {
        Energy* energy = **container->at(i);
        enum EnableState { Disabled = 0, Enabled = 1 };
        EnableState disabled = static_cast<EnableState>(
            ((static_cast<unsigned int>(
                  reinterpret_cast<const unsigned char*>(energy)[5]) &
              0x80) >>
             7) == 0);
        unsigned int enabled = disabled == 0;
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
