#pragma force_active on
typedef struct HashTable { int pad[2]; int unk8; } HashTable;
extern unsigned int fn_8027D198(HashTable *, unsigned int);
extern void fn_8027D2C8(HashTable *, unsigned int);
int fn_8027D3D4(HashTable *t, unsigned int key) {
    unsigned int value = fn_8027D198(t, key);
    if (((signed char)(unsigned char)((int)value <= t->unk8) & 1) != 0) {
        fn_8027D2C8(t, value);
        return 0;
    }
    return 1;
}
