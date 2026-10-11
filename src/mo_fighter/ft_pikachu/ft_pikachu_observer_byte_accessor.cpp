struct PikachuObserverByteView {
    unsigned char prefix[0x44];
    unsigned char value;
};

extern "C" unsigned char fn_98_9C28(const PikachuObserverByteView* observer) {
    return observer->value;
}
