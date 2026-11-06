#pragma force_active on
typedef unsigned char u8;
struct Buf {
    char pad[0x4c];
    int count;
    u8* data;
    void put(u8 value) { data[count++] = value; }
};
class Message {
public:
    char pad[0x1d0];
    Buf* buffer;
    void setCursorX(float);
};
extern "C" u8* fn_8006D3DC(u8*, float);
void Message::setCursorX(float value) {
    buffer->put(0x16);
    buffer->put(1);
    u8 bytes[4];
    u8* p = fn_8006D3DC(bytes, value);
    Buf* b = buffer;
    b->data[b->count++] = p[0];
    b->data[b->count++] = p[1];
    b->data[b->count++] = p[2];
    b->data[b->count++] = p[3];
}