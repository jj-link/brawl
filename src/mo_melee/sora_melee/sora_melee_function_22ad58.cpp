#pragma force_active on
#pragma scheduling off
struct SContainer {
    unsigned char m_pad[0x50];
    unsigned int m_count;
};
struct Entry {
    void* value;
    unsigned char pad[0x20];
};
extern "C" int fn_27_22AD58(SContainer* a, Entry* b, void* c, unsigned int* d)
{
    unsigned int n = a->m_count;
    Entry* p = b;
    unsigned int i = 0;
    for (; i < n; i++) {
        void* v = p->value;
        if (v != 0 && c == v) { *d = i; return 1; }
        ++p;
    }
    p = b;
    for (i = 0; i < n; i++) {
        if (p->value == 0) { *d = i; return 0; }
        ++p;
    }
    *d = n;
    return 0;
}