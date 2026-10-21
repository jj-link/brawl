#pragma force_active on
typedef struct Entry {
    char pad[0xC];
    float value;
    char tail[0x20];
} Entry;

void fn_80288B20(void *arg0, Entry **arg1, int arg2, float farg0) {
    Entry *p = *arg1;
    float v = *(float *)((char *)arg0 + 8);
    p -= (short)arg2;
    p->value = farg0 * v;
}
