#pragma force_active on
struct JungleMember {
    unsigned char storage[0x90];
};

extern "C" void* fn_51_6708(JungleMember* base, int index) {
    return base[index].storage + 0x0C;
}
