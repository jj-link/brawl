#pragma force_active on
extern "C" int fn_800B61C0(void*);

extern "C" int fn_16_5940(void* self) {
    if (fn_800B61C0(*reinterpret_cast<void**>(
            reinterpret_cast<char*>(self) + 0x70))) {
        return 0x10;
    }
    return *reinterpret_cast<int*>(reinterpret_cast<char*>(self) + 0x9C);
}
