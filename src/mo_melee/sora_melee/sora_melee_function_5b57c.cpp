#pragma force_active on
typedef struct Entry {
    signed char a;
    signed char b;
    signed char c;
} Entry;

extern "C" void fn_27_5B57C(unsigned char* self, int idx, int val) {
    Entry* arr = *(Entry**)(self + 0x24);
    Entry* e = &arr[idx];
    if (val == e->b) {
        return;
    }
    e->b = (signed char)val;
    *(unsigned char*)(self + 0x2c) = 1;
}
