#include <types.h>
#pragma force_active on
typedef struct { u8 pad[0x1F74]; u32 count; } Inner;
typedef struct { u32 words[13]; Inner *inner; } Object;
typedef struct { u32 prefix[2]; Object object; u8 pad[12]; u8 entry[0x2C]; } State;
extern void fn_803D634C(void *, int, u32);
extern char *fn_803D645C(char *, char *);
extern int fn_803DED54(State *, int);
extern int fn_803DEE48(State *);
extern int fn_803DEF54(State *, int);
extern int fn_803E6E64(char *, char *);
extern void fn_803E774C(char *, u8 *, int);
extern int fn_803E855C(char *, u32);
int fn_803DC9C4(Object *obj, u32 base, char *prefix, u32 *bits)
{
    State state;
    char name[16];
    char text[16];
    u32 result;
    Inner *inner;
    u32 i, end, digits;
    inner = obj->inner;
    fn_803D634C(bits, 0, inner->count << 2);
    state.object = *obj;
    result = fn_803DED54(&state, 0);
    while (!fn_803DEE48(&state)) {
        if (result != 0) return result;
        if (!state.entry[0]) break;
        if (state.entry[0] != 0xE5 && (state.entry[11] & 15) != 15 && !(state.entry[11] & 8)) {
            fn_803E774C(name, state.entry, 0);
            i = 1;
            while (name[i] != '~' && name[i] != 0 && i < 7) i++;
            if (i < 7 && name[i] == '~') {
                end = i + 1;
                while (name[end] >= '0' && name[end] <= '9') end++;
                if (name[end] == '.' || name[end] == 0) {
                    digits = end - i - 1;
                    result = 0;
                    while (digits != 0) {
                        result *= 10;
                        result += name[end - digits] - '0';
                        digits--;
                    }
                    fn_803D645C(text, prefix);
                    fn_803E855C(text, result);
                    if (fn_803E6E64(name, text) == 0 && result >= base &&
                        result < base + (inner->count << 5)) {
                        result -= base;
                        bits[result >> 5] |= 1 << result;
                    }
                }
            }
        }
        result = fn_803DEF54(&state, 0);
    }
    return 0;
}