#pragma force_active on

struct Buffer {
    int value;
    unsigned char data[0x1EC];
};

extern "C" void fn_802E1184(Buffer*, int*);

extern "C" int fn_802E0E88() {
    __declspec(align(16)) Buffer buffer;
    int zero = 0;
    if (&buffer != 0) {
        int value = zero;
        fn_802E1184(&buffer, &value);
    }
    return buffer.value;
}
