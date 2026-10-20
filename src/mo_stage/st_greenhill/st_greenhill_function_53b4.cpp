#pragma force_active on
struct Entry {
    unsigned int a;
    unsigned int b;
};

struct Container {
    unsigned int header;
    unsigned int pad[2];
    Entry entries[1];
};

extern "C" Entry* fn_72_53B4(Container* p, int i) {
    return &p->entries[i];
}
