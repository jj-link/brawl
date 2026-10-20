#pragma force_active on
extern "C" void fn_27_42758(void* self, int value, unsigned int mode) {
    int* fields = (int*)self;

    if (mode == 1) {
        fields[10] = value;
    } else if (fields[10] < value) {
        fields[10] = value;
    }

    unsigned char* bytes = (unsigned char*)self;
    if (bytes[0x31] == 1 || fields[9] != 0) {
        fields[8] = 2;
        return;
    }

    if (bytes[0x32] == 1 || fields[10] != 0) {
        fields[8] = 1;
        return;
    }

    fields[8] = 0;
}
