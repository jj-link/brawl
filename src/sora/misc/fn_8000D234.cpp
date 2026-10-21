#pragma force_active on

typedef unsigned char u8;

struct Entry {
    u8 pad[0x399];
    u8 f7 : 1;
    u8 rest : 7;
};

extern "C" void fn_8000D234(u8* base, int index, int flag) {
    Entry* e = (Entry*)(base + index * 0x18);
    e->f7 = flag;
}
