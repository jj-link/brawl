#pragma force_active on
struct Entry {
    unsigned char pad[8];
};

extern "C" void* fn_68_65C4(Entry* self, int index) {
    int flag = *(int*)((char*)self + 8);
    int i = (flag >> 28) + index;
    if (i >= 6) {
        i -= 6;
    }
    return (char*)self + i * 8 + 12;
}
