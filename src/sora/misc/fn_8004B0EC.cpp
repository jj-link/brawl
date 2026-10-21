#pragma force_active on
extern "C" int fn_8004B0EC(void* arg0) {
    return *reinterpret_cast<int*>((char*)arg0 + 0x24) + 0x18;
}
