#pragma force_active on
struct Entry {
    float a[3];
    float b[3];
};

extern "C" void fn_27_231020(void* p, float* a, float* b, unsigned int i) {
    unsigned char n = *(unsigned char*)((char*)p + 0x1e5);
    if (i >= n)
        return;

    Entry* data = *(Entry**)((char*)p + 0x1f0);
    if (data == 0)
        return;

    Entry* row = data + i;
    a[0] = row->a[0];
    a[1] = row->a[1];
    a[2] = row->a[2];
    b[0] = row->b[0];
    b[1] = row->b[1];
    b[2] = row->b[2];
}
