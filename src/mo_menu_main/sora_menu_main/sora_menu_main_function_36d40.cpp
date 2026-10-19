#pragma force_active on
struct Elem {
    unsigned char pad[0x8c];
    unsigned char* ptrs[0x41];
};

extern "C" bool fn_2_36D40(Elem* base, unsigned int a, unsigned int b) {
    unsigned char* p = base[a].ptrs[b];
    return *(int*)(p + 0x14) == 2;
}
