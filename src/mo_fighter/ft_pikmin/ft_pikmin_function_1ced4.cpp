#pragma force_active on
namespace {
class Element {
public:
    virtual void reserved0();
    virtual void update(void* arg);
};
class Array {
public:
    virtual void reserved0();
    virtual Element*** at(int index);
    virtual void reserved10();
    virtual int size();
};
}

extern "C" void fn_113_1CED4(void*, Array* array, void* accesser) {
    for (int i = 0; i < array->size(); ++i) {
        Element* element = **array->at(i);
        enum EnableState { Disabled = 0, Enabled = 1 };
        EnableState disabled = static_cast<EnableState>(
            ((static_cast<unsigned int>(
                  reinterpret_cast<const unsigned char*>(element)[5]) &
              0x80) >>
             7) == 0);
        unsigned int enabled = disabled == 0;
        unsigned int s;
        if (enabled && (s = reinterpret_cast<const unsigned char*>(element)[6]) != 1) {
            if (enabled == true && s == 0) {
                if (enabled == true && s == 0) {
                    element->update(accesser);
                }
            }
        }
    }
}
