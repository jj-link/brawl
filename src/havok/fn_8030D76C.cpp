#pragma force_active on
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;

struct Entry {
    u16 key;
    u16 val;
};

extern "C" Entry *fn_8030D76C(void *unused, Entry *begin, Entry *end, u32 value) {
    Entry *mid;
    while ((s32)(end - begin) > 16) {
        u32 half = (u32)(end - begin) / 2;
        mid = begin + half;
        if (mid->key < value) {
            begin = mid;
        } else {
            end = mid;
        }
    }
    while (begin->key < value) {
        begin++;
    }
    return begin;
}
