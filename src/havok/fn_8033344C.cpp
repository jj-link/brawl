#pragma force_active on
extern "C" void fn_8027EABC(void*, void*, unsigned int, int);
extern void* lbl_805A0EC8;
struct Entry { void** first; void* second; };
struct Array {
    Entry* data; int size; unsigned int capacity;
    bool isOwned() const { return (capacity & 0x80000000) == 0; }
    void dealloc() { fn_8027EABC(lbl_805A0EC8, data, capacity * 8, 0x15); }
};
class Class_8042B6D0 {
public:
    virtual void fn_8004805C();
    virtual int fn_8004781C(void*, void*, Array*);
};
extern "C" int fn_80332BD0(void*, void*, Array*);
extern "C" int fn_8033344C(void* a, void* b, Class_8042B6D0* c) {
    Array array;
    array.data = 0;
    array.size = 0;
    array.capacity = 0x80000000;
    if (fn_80332BD0(a, b, &array) == 0 && c->fn_8004781C(a, b, &array) == 0) {
        for (int i = 0; i < array.size; ++i) {
            if (*array.data[i].first && fn_8033344C(*array.data[i].first, array.data[i].second, c) == 1) {
                if (array.isOwned()) array.dealloc();
                return 1;
            }
        }
        if (array.isOwned()) array.dealloc();
        return 0;
    }
    if (array.isOwned()) array.dealloc();
    return 1;
}
