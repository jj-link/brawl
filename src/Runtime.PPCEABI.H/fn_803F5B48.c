// Signed integer formatting with the target's reversed-digit pass.
// Keep the integer-formatting entry used by itoa's tail call in the linked image.
typedef unsigned long u32;

extern int strlen(const char*);

#pragma force_active on
char* fn_803F5B48(int value, char* buffer, u32 radix)
{
    char* start;
    char* end;
    u32 number;
    int negative;
    u32 count;
    int digit;
    char first;
    char last;
    int left;
    int right;

    negative = 0;
    count = 0;
    number = (u32)value;
    if (value < 0) {
        number = (u32)(-value);
        negative = 1;
    }
    do {
        digit = number % radix;
        if (digit > 9) {
            digit = digit + 0x37;
            buffer[count] = (char)digit;
            count = count + 1;
        } else {
            digit = digit + 0x30;
            buffer[count] = (char)digit;
            count = count + 1;
        }
        number = number / radix;
    } while (number != 0);
    if (negative != 0) {
        buffer[count] = '-';
        count = count + 1;
    }
    buffer[count] = 0;
    left = 0;
    right = strlen(buffer) - 1;
    start = buffer;
    end = buffer + right;
    while (left < right) {
        first = *start;
        left = left + 1;
        last = *end;
        right = right - 1;
        *start = last;
        start = start + 1;
        *end = first;
        end = end - 1;
    }
    return buffer;
}
