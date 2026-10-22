#pragma force_active on
typedef unsigned char u8;

extern "C" void fn_801EC158(void* p);
extern "C" void fn_801EC184(int v, void* p);

struct Entry {
    u8 pad[0xAB];
    u8 flags;
};

extern "C" int fn_80190F9C(int* arg0, unsigned int arg1, int arg2) {
    if (arg1 < 8) {
        Entry* e = (Entry*)(*arg0 + arg1 * 0x34);
        if (arg2 != 0) {
            fn_801EC184(arg2, (char*)e + 0xAC);
            e->flags = e->flags & 0xFE;
        } else {
            fn_801EC158((char*)e + 0xAC);
            e->flags = e->flags | 1;
        }
        return 1;
    }
    return 0;
}
