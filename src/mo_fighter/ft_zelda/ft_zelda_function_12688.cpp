#pragma force_active on
struct Flags {
    unsigned char high : 1;
    unsigned char selected : 1;
    unsigned char low : 6;
};

extern "C" void fn_104_12688(void* object, bool selected) {
    reinterpret_cast<Flags*>(static_cast<unsigned char*>(object) + 0xA4)->selected = selected;
}
