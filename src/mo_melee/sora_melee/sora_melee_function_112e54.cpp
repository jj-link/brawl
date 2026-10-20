#pragma force_active on
struct OwnerData {
    unsigned char _[0x838];
};

struct Owner {
    OwnerData* mData;
    unsigned char* mInput;
    short _8;
    unsigned char _10;
    unsigned char _11;
};

extern "C" void fn_27_112E54(Owner* owner, int value) {
    owner->mData->_[0x48f] = (unsigned char)value;
}
