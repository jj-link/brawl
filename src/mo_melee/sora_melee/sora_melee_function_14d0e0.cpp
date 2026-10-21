#pragma force_active on
struct Entry {
    int key;
    int value;
};

class Work {
public:
    virtual void unused0();
    virtual void unused1();
    virtual void unused2();
    virtual void unused3();
    virtual void unused4();
    virtual void unused5();
    virtual unsigned int getType();

    unsigned char padding[0x20];
    int total;
    Entry entries[4];
    int count;
};

extern "C" void fn_27_14D0E0(Work* work, int key) {
    if (work->getType() == 1) {
        work->total = 0;
        for (int i = 0; i < work->count; ++i) {
            if (work->entries[i].key == key) {
                work->total += work->entries[i].value;
            }
        }
    }
}
