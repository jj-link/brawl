#pragma force_active on

extern "C" {
void free__13gfHeapManagerFPv(void*);
void __dt__14gfFileIOHandleFv(void*, int);
}

void operator delete(void*);

struct Entry {
    char pad[0x9C];
    void* buffer;

    ~Entry() {
        free__13gfHeapManagerFPv(buffer);
        __dt__14gfFileIOHandleFv((char*)this + 0x14, -1);
    }
};

struct Manager {
    int a;
    int count;
    Entry* entries;
    int d;

    ~Manager() {
        for (int i = 0; i < count; ++i)
            (entries + i)->~Entry();

        if (entries != 0)
            free__13gfHeapManagerFPv(entries);
    }
};

extern Manager* lbl_805A0318;

extern "C" void fn_80106314() {
    Manager* mgr = lbl_805A0318;
    delete mgr;
    lbl_805A0318 = 0;
}
