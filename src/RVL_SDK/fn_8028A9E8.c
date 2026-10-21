#pragma force_active on
// fn_8028A9E8
// Writes an allocation block marker (magic + kind byte) at the cursor tracked
// in the buffer header, then bumps the cursor past the marker.

typedef unsigned char u8;
typedef unsigned int u32;

struct Marker {
    u32 tag;
    u8 kind;
    u8 pad[3];
};

struct Buffer {
    u32 x0;
    u32 x4;
    struct Marker* cursor;
};

void fn_8028A9E8(signed char kind, struct Buffer* buf) {
    struct Marker* m = buf->cursor;
    m->tag = 0x13020008;
    m->kind = kind;
    buf->cursor = m + 1;
}
