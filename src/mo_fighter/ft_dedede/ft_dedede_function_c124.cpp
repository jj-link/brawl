#pragma force_active on
class DededeChainedProvider {
public:
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
};

extern "C" void fn_117_C124(char* self) {
    reinterpret_cast<DededeChainedProvider*>(self + 0x471CC)->slot10();
}
