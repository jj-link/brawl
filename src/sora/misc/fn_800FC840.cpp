#pragma force_active on
typedef unsigned char u8;

struct Flags {
    unsigned char b0 : 1;
    unsigned char b1 : 1;
    unsigned char b2 : 1;
    unsigned char b3 : 1;
    unsigned char b4 : 1;
    unsigned char b5 : 1;
    unsigned char b6 : 1;
    unsigned char b7 : 1;
};

extern "C" {
void cancelRequest__14gfFileIOHandleFv(void*);
void free__13gfHeapManagerFPv(void*);

void fn_800FC840(void* self)
{
    u8* p = reinterpret_cast<u8*>(self);
    if (*reinterpret_cast<void**>(p + 0x8)) {
        free__13gfHeapManagerFPv(*reinterpret_cast<void**>(p + 0x8));
        *reinterpret_cast<void**>(p + 0x8) = 0;
    }
    if (*reinterpret_cast<void**>(p + 0xC)) {
        free__13gfHeapManagerFPv(*reinterpret_cast<void**>(p + 0xC));
        *reinterpret_cast<void**>(p + 0xC) = 0;
    }
    if (*reinterpret_cast<void**>(p + 0x10)) {
        free__13gfHeapManagerFPv(*reinterpret_cast<void**>(p + 0x10));
        *reinterpret_cast<void**>(p + 0x10) = 0;
    }
    if (*reinterpret_cast<void**>(p + 0x48)) {
        free__13gfHeapManagerFPv(*reinterpret_cast<void**>(p + 0x48));
        *reinterpret_cast<void**>(p + 0x48) = 0;
    }
    if (*reinterpret_cast<void**>(p + 0x4C)) {
        free__13gfHeapManagerFPv(*reinterpret_cast<void**>(p + 0x4C));
        *reinterpret_cast<void**>(p + 0x4C) = 0;
    }
    u8* cursor = p + 0x54;
    for (int i = 0; i < 5; ++i, cursor += 4) {
        cancelRequest__14gfFileIOHandleFv(cursor);
    }
    reinterpret_cast<Flags*>(p)->b0 = 0;
}
}
