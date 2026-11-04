#pragma force_active on
struct Entry {
    char padding[4];
    signed char kind;
    signed char offset;
};
struct Pair {
    Entry* first;
    Entry* second;
};
class Class_804885F0 {
public:
    virtual void fn_802E0FB4();
    virtual unsigned int fn_802F0570(void*, void*);
    virtual void fn_802F0568();
};
class Class_80487298 {
public:
    virtual void fn_802CAD00();
    virtual void fn_80080A64();
    virtual void fn_802CACF8(Pair*);
};
extern "C" void fn_802CAEE8(Class_80487298* (*table)[8], Pair* pair, int count, Class_804885F0* test) {
    while (--count >= 0) {
        Entry* first = pair->first;
        Entry* second = pair->second;
        if ((signed char)(test->fn_802F0570((char*)first + first->offset, (char*)second + second->offset) >> 24)) {
            table[pair->first->kind][pair->second->kind]->fn_802CACF8(pair);
        }
        ++pair;
    }
}
