#pragma force_active on
struct SnakeFlags {
    unsigned char pad : 1;
    unsigned char flag : 1;
    unsigned char rest : 6;
};

extern "C" void fn_122_18B9C(void* object, int flag) {
    SnakeFlags* f = reinterpret_cast<SnakeFlags*>(static_cast<unsigned char*>(object) + 0xA4);
    f->flag = flag & 1;
}
