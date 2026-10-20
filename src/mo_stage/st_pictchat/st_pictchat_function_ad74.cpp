#pragma force_active on
typedef unsigned char u8;

struct Entry {
    unsigned int a;
    unsigned int b;
};

struct Table {
    unsigned int header[3];
    Entry entries[1];
};

extern "C" void* fn_73_AD74(void* base, int index) {
    u8* p = (u8*)base;
    return p + index * 8 + 0xC;
}
