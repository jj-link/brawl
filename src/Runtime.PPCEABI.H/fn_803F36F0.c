typedef unsigned char u8;
typedef signed short s16;

struct DecimalRecord {
    u8 sign;
    u8 unused;
    s16 exponent;
    u8 count;
    u8 digits[36];
};

void fn_803F36F0(struct DecimalRecord* record, unsigned long long value) {
    u8* right;
    u8* left;
    record->sign = 0;
    record->count = 0;
    while (value != 0) {
        record->digits[record->count++] = value % 10;
        value /= 10;
    }
    right = (u8*)record + record->count + 5;
    left = record->digits;
    while (left < --right) {
        u8 digit = *left;
        *left++ = *right;
        *right = digit;
    }
    record->exponent = record->count - 1;
}
