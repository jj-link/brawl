#pragma force_active on
class ftOwner {
public:
    void setMetal(bool metal);
};

struct ftOwnerData {
    unsigned char pad[0x1c];
    unsigned char metal : 1;
};

void ftOwner::setMetal(bool metal) {
    ftOwnerData* d = *reinterpret_cast<ftOwnerData**>(this);
    d->metal = metal;
}
