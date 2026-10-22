#pragma force_active on
extern float lbl_805A19FC;

struct Buffer {
    unsigned char pad[0x4c];
    int index;
    unsigned char* data;

    void write(unsigned char value) {
        data[index++] = value;
    }
};

struct Object {
    unsigned char pad[0x1d0];
    Buffer* buffer;
};

extern "C" void fn_8006A100(Object* obj, float value) {
    int v = (int)(lbl_805A19FC * value);
    obj->buffer->write(3);
    obj->buffer->write((unsigned int)v >> 8);
    obj->buffer->write(v);
}
