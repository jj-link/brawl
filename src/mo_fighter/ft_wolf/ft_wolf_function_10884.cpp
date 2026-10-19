#pragma force_active on
struct Ft_wolfFlags {
    unsigned char high : 1;
    unsigned char selected : 1;
    unsigned char low : 6;
};

extern "C" void fn_125_10884(void* object, int value) {
    Ft_wolfFlags* flags = reinterpret_cast<Ft_wolfFlags*>(static_cast<unsigned char*>(object) + 0xA4);
    flags->selected = value;
}
