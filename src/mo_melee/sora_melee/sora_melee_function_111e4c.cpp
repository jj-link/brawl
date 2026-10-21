#pragma force_active on
struct ftOwnerData {
    unsigned char pad[0x1C];
    unsigned char : 2;
    unsigned char curry : 1;
    unsigned char : 5;
};

class ftOwner {
public:
    ftOwnerData* data;
    void setCurry(bool curry);
};

void ftOwner::setCurry(bool curry) {
    data->curry = curry;
}
