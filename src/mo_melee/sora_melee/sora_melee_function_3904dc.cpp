#pragma force_active on
struct Entry {
    int a;
    int b;
    int c;
};

extern "C" void* fn_27_3904DC(Entry* self, int idx)
{
    int x = (self->c >> 26) + idx;
    if (x >= 0x13) {
        x = x - 0x13;
    }
    return (char*)self + x * 12 + 12;
}
