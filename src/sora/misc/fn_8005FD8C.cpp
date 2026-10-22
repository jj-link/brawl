#pragma force_active on
typedef unsigned long u32;
typedef unsigned char u8;

struct Entry {
    char pad[0x44];
    void* model;
    char pad48[0x7C - 0x48];
    u32 key;
    u8 count;
};

extern Entry* lbl_805A0164;
extern "C" void fn_80062A98(Entry*, void*, const char*, bool);
extern "C" void fn_80063ECC(Entry*, int, int);

class ecMgr {
public:
    char pad[0x60];
    Entry* entries;
    char pad64[8];
    int active;
    u32 first;
    u32 last;

    Entry* find(u32 key) {
        if (key && active) {
            Entry* entry = lbl_805A0164;
            if (entry && entry->key == key)
                return entry;
            entry = &entries[first];
            for (u32 i = first; i <= last; ++i, ++entry) {
                if (entry->key == key) {
                    lbl_805A0164 = entry;
                    return entry;
                }
            }
        }
        return 0;
    }
    void setParent(u32 a, u32 b, const char* name, bool flag);
};

void ecMgr::setParent(u32 a, u32 b, const char* name, bool flag) {
    Entry* child = find(a);
    Entry* parent = find(b);
    Entry* p = find(b);
    void* model = !p ? 0 : p->model;
    if (!child || !parent || !model)
        return;
    fn_80062A98(child, model, name, flag);
    fn_80063ECC(parent, 0, 0);
    u8 c = parent->count;
    child->count = c;
    if (c < 0xFF)
        child->count++;
}
