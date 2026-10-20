#pragma force_active on
struct ftOwnerData {
    unsigned char pad[0x4D0];
    unsigned char slip : 1;
};

class ftOwner {
public:
    ftOwnerData* data;
    void setSlipInterval(bool value);
};

void ftOwner::setSlipInterval(bool value) {
    data->slip = value;
}
