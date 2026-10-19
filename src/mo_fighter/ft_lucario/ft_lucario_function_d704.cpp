#pragma force_active on
extern "C" int fn_118_D704(void* object, int bit) {
    int* flags = reinterpret_cast<int*>(static_cast<unsigned char*>(object) + 0x538);
    return (*flags & (1 << bit)) != 0;
}
