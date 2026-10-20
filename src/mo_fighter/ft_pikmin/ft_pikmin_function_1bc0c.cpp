#pragma force_active on
struct PikminFlags {
    unsigned char a : 1;
    unsigned char bit : 1;
    unsigned char rest : 6;
};

extern "C" void fn_113_1BC0C(void* object, bool flag) {
    PikminFlags* flags = reinterpret_cast<PikminFlags*>(static_cast<unsigned char*>(object) + 0xA4);
    flags->bit = flag;
}
