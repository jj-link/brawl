#pragma force_active on
typedef unsigned int u32;

extern "C" int strcmp(const char*, const char*);

struct Entry {
    u32 id;
    char name[1];
};

struct Ref {
    const Entry* p;
};

static inline bool equal(const Ref& a, const Ref& b) {
    if (a.p->id == b.p->id) {
        return strcmp(a.p->name, b.p->name) == 0;
    }
    return false;
}

extern "C" bool fn_8018CBF4(const Ref& arg0, const Ref& arg1) {
    return equal(arg0, arg1);
}
