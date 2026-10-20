#pragma force_active on
struct _X {
    int _pad[0x148];
    int _520;
    char _pad2[4];
    int _528;
};

extern "C" void fn_51_16670(_X *this_, int a, int b) {
    this_->_520 = a;
    this_->_528 = b;
}
