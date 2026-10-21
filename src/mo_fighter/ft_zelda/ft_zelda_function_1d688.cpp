#pragma force_active on
namespace {
class FtUpdatable {
public:
    virtual void reserved0();
    virtual void update(void* argument);

    unsigned char reserved;
    unsigned char enabled : 1;
    unsigned char otherFlags : 7;
    bool suspended;

    bool isDisabled() const { return enabled == 0; }
};

class FtElementArray {
public:
    virtual void reserved0();
    virtual FtUpdatable*** at(int index);
    virtual void reserved8();
    virtual int size();
};
}

extern "C" void fn_104_1D688(void*, FtElementArray* elements, void* argument) {
    for (int i = 0; i < elements->size(); ++i) {
        FtUpdatable* element = **elements->at(i);
        bool disabled = element->isDisabled();
        bool active = disabled == false;
        unsigned int suspension;

        if (active && (suspension = reinterpret_cast<const unsigned char*>(element)[6]) != 1) {
            if (active == true && suspension == 0) {
                if (active == true && suspension == 0) {
                    element->update(argument);
                }
            }
        }
    }
}
