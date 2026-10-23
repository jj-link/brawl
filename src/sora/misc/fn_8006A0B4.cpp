#pragma force_active on

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

extern "C" void fn_8006A0B4(Object* obj, float value) {
    int v = (int)value;
    obj->buffer->write(14);
    obj->buffer->write(v);
}
