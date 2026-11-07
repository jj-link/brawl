#pragma force_active on
extern const float lbl_805A19F0;
extern const float lbl_805A19F4;
extern const float lbl_805A19F8;
extern const float lbl_805A19FC;
struct Buffer {
    unsigned char pad[0x4c];
    int index;
    unsigned char* data;
    void write(unsigned char value) { data[index++] = value; }
};
struct Object {
    unsigned char pad[0x1d0];
    Buffer* buffer;
};
extern "C" void fn_8006A3A8(Object* obj, float value, float scale) {
    if (scale > lbl_805A19F4) scale = lbl_805A19F0;
    int a = (int)(lbl_805A19F8 * scale);
    int b = (int)(lbl_805A19FC * value);
    obj->buffer->write(0x1d);
    obj->buffer->write(a);
    obj->buffer->write(0x1c);
    obj->buffer->write((unsigned int)b >> 8);
    obj->buffer->write(b);
}