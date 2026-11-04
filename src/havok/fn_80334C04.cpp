#pragma force_active on
extern "C" void fn_8027EABC(void*, void*, unsigned int, int);
extern "C" unsigned char* fn_80334BF8();
extern void* lbl_805A0EC8;
struct Entry {
    void* pad[2];
    void (*call)(void*, void*, Entry*);
};
struct Array {
    Entry** data;
    int size;
    unsigned int capacity;
    bool isOwned() const { return (capacity & 0x80000000) == 0; }
    void dealloc() { fn_8027EABC(lbl_805A0EC8, data, capacity * 4, 0x15); }
};
extern "C" int fn_80334324(void*, void*, unsigned char*, Array*);
extern "C" int fn_80334C04(void* a, void* b, void* c, void* d, unsigned char* e) {
    e = e ? e : fn_80334BF8();
    Array array;
    array.data = 0;
    array.size = 0;
    array.capacity = 0x80000000;
    if (fn_80334324(c, d, e, &array) == 0) {
        for (int i = 0; i < array.size; ++i) {
            Entry* entry = array.data[i];
            entry->call(a, b, entry);
        }
        if (array.isOwned()) array.dealloc();
        return 0;
    }
    if (array.isOwned()) array.dealloc();
    return 1;
}