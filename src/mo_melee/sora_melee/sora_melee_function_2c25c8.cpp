#pragma force_active on
extern "C" int fn_27_2C20E8(void*, int, int);

extern "C" void fn_27_2C25C8(void* entries, const void* value) {
    int index = fn_27_2C20E8(entries, -1, -1);
    if (index >= 0) {
        *reinterpret_cast<unsigned int*>(
            reinterpret_cast<char*>(entries) + index * 12 + 12) =
            *reinterpret_cast<const unsigned int*>(value);
    }
}
