#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void* fn_800AD808(void*, int);
extern "C" void fn_800AD9E0(void*, u32, u32);

struct WatchEntry {
    int data[3];
    int id;
    u8 kind;
    u8 padding[3];
};

struct WatchEntries {
    WatchEntry entries[4];
};

struct WatchView {
    u8 padding[0x440];
    WatchEntry entries[4];
};

struct WatchText {
    u16 text[100];
};

extern "C" void fn_15_B1C(unsigned char* self, unsigned char* source) {
    *reinterpret_cast<int*>(self + 0x434) =
        *reinterpret_cast<int*>(source + 0xF4);
    *reinterpret_cast<int*>(self + 0x438) =
        *reinterpret_cast<int*>(source + 0xF8);
    self[0x43C] = source[0xFC];

    *reinterpret_cast<WatchEntries*>(self + 0x440) =
        *reinterpret_cast<WatchEntries*>(source + 0x100);

    if (*reinterpret_cast<int*>(self + 0x434) == 0) {
        int i;
        for (i = 0; i < self[0x43C]; ++i) {
            if (source[0x221] ==
                reinterpret_cast<WatchView*>(self)->entries[i].kind) {
                break;
            }
        }
        *reinterpret_cast<int*>(self + 0x514) = i + 1;
    } else {
        int i;
        for (i = 0; i < self[0x43C]; ++i) {
            if (*reinterpret_cast<int*>(source + 0x224) ==
                reinterpret_cast<WatchView*>(self)->entries[i].id) {
                break;
            }
        }
        *reinterpret_cast<int*>(self + 0x514) = i / 2 + 5;
    }

    *reinterpret_cast<int*>(self + 0x520) =
        *reinterpret_cast<int*>(source + 0x228) / 10;

    *reinterpret_cast<WatchText*>(self + 0x6E8) =
        *reinterpret_cast<WatchText*>(source + 0x234);
    *reinterpret_cast<u16*>(self + 0x7B0) =
        *reinterpret_cast<u16*>(source + 0x2FC);

    self[0xD58] = source[0x220];

    void* object = __nw__FUlQ25Heaps8HeapType(0x3EB4, 0x2A);
    if (object != 0) {
        object = fn_800AD808(object, 0);
    }
    *reinterpret_cast<void**>(self + 0x978) = object;

    u32 first = *reinterpret_cast<u32*>(source + 0x304);
    u32 second = *reinterpret_cast<u32*>(source + 0x308);
    fn_800AD9E0(object, first, second);
}
