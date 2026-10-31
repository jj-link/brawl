#pragma force_active on
class DededeTraversalEntry {
public:
    virtual void slot08();
    virtual void invoke(void* argument);

    unsigned char padding;
    unsigned char enabled : 1;
    unsigned char otherFlags : 7;
    bool disabled;

    bool isEnabled() const { return enabled; }
};

extern "C" void fn_117_21BA0(DededeTraversalEntry* entry, void* argument) {
    if (entry->isEnabled() == true && entry->disabled == false) {
        entry->invoke(argument);
    }
}
