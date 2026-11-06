#pragma force_active on
struct Entry { int type; int value; int extra; };
struct Partial { int type; int value; int extra; };
struct State { char pad[0x370]; int count; Entry entries[16]; };
extern "C" State* lbl_1_bss_1B78;
struct Table14 { int v[14]; };
struct Table11 { int v[11]; };
extern "C" Table14 lbl_1_rodata_2410;
extern "C" Table11 lbl_1_rodata_2448;
static inline bool push(State* s, const Partial& e) {
    if (s->count >= 16) return false;
    s->entries[s->count++] = *(const Entry*)&e;
    return true;
}
extern "C" int fn_1_3AEB8(int id) {
    int result;
    if (id >= 0 && id <= 13) {
        Table14 t = lbl_1_rodata_2410;
        Partial e;
        e.type = 3;
        e.value = t.v[id];
        result = push(lbl_1_bss_1B78, e);
    } else if (id >= 0x75 && id <= 0x7f) {
        Table11 t = lbl_1_rodata_2448;
        Partial e;
        e.type = 4;
        e.value = t.v[id - 0x75];
        result = push(lbl_1_bss_1B78, e);
    } else {
        Partial e;
        e.type = 4;
        e.value = id;
        result = push(lbl_1_bss_1B78, e);
    }
    return result;
}