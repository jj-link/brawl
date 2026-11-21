#pragma force_active on
#include <new>
extern "C" char lbl_6_data_0[];
extern "C" int strcmp(const char*, const char*);
extern "C" char* strcat(char*, const char*);
extern "C" void fn_800C2BB4(void*, int);
struct Base { char pad[0x50]; };
struct Object : Base { virtual ~Object(); };
struct Value {
    int a; int b; int c; Object* d; int e; char f;
    Value() : a(0), d(0) {
        Object* p = 0;
        if (d != p) { delete d; d = p; }
        fn_800C2BB4(this, 0);
        e = 0; f = 0;
    }
};
struct Iterator {
    char* end; char* current;
    Iterator(char* e, char* c) : end(e), current(c) {}
};
inline Iterator findEntry(char* base, char* name, unsigned hash, unsigned& output) {
    unsigned i = 0;
    unsigned h = hash % 61;
    output = h;
    for (; i < 62; ++i) {
        unsigned key;
        char* entry = base + ((h + i) % 62) * 0x68;
        key = *(unsigned*)(entry + 0x44);
        if (key == 61) {
            bool empty = !strcmp(entry, lbl_6_data_0);
            if (empty) break;
        }
        if (key == h) {
            bool same = !strcmp(entry, name);
            if (same) return Iterator(base + 0x1930, entry);
        }
    }
    return Iterator(base + 0x1930, base + 0x1930);
}
inline Iterator endEntry(char* base) { return Iterator(base + 0x1930, base + 0x1930); }
inline bool isEnd(Iterator& it, char* base) {
    Iterator end = endEntry(base);
    return it.current == end.current;
}
extern "C" void* fn_6_8180(void* arg0, char* arg1) {
    char* str = arg1;
    int hash = 0;
    while (*str) { hash = (signed char)*str + hash * 0x89; str++; }
    unsigned h;
    char* base = (char*)arg0;
    Iterator it = findEntry(base, arg1, (unsigned)hash, h);
    if (!isEnd(it, base))
        return (void*)(((unsigned)(it.current + 0x4F)) & 0xFFFFFFF8);
    unsigned slot = 0;
    for (unsigned i = 0; i < 0x3E; i++) {
        slot = (h + i) % 62;
        bool empty = !strcmp(base + slot * 0x68, lbl_6_data_0);
        if (empty) break;
    }
    *(int*)(base + 0x1930) += 1;
    char* entry = base + slot * 0x68;
    entry[0] = 0;
    strcat(entry, arg1);
    *(unsigned*)(entry + 0x44) = h;
    Value* data = (Value*)(((unsigned)(entry + 0x4F)) & 0xFFFFFFF8);
    return new (data) Value;
}