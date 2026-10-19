#pragma force_active on
typedef struct {
    int pad[2];
    int value;
} Sub;

extern "C" char* fn_50_6478(char* base, int index) {
    int n = (((Sub*)base)->value >> 28) + index;
    if (n >= 7) {
        n -= 7;
    }
    return base + (n << 3) + 12;
}
