#pragma force_active on

extern "C" {
void fn_802F4558(void*, void*);
void fn_802E423C(void*, void*);
}

struct Elem { char d[48]; };

struct List {
    Elem* end;
    char pad[12];
    Elem begin[1];
};

struct Context {
    void* a;
    void* b;
    void* unused;
    void* list;
    void* items[256];
    void* owner;
};

extern "C" void fn_802D7D34(void* arg0, void* arg1, void* arg2, void* unused, List* arg3) {
    Context sp;
    signed short* timer = (signed short*)((char*)arg0 + 0x14);
    signed short oldTimer = *timer;
    *timer = oldTimer - 1;

    if (oldTimer == 0) {
        char* p1 = (char*)arg1 + *(int*)((char*)arg1 + 0x10);
        char* p2 = (char*)arg2 + *(int*)((char*)arg2 + 0x10);
        unsigned short b = *(unsigned short*)(p2 + 0x92);
        unsigned short a = *(unsigned short*)(p1 + 0x92);
        if (a < b) b = a;
        *timer = b;

        sp.a = arg1;
        sp.b = arg2;
        sp.list = arg3;
        sp.owner = arg0;

        int n = arg3->end - arg3->begin;
        int i = n - 1;
        while (i >= 0) {
            sp.items[i] = 0;
            --i;
        }

        fn_802F4558(*(void**)((char*)arg0 + 8), &sp);
        if (*(int*)(p1 + 0x1B8) != 0) fn_802E423C(p1, &sp);
        if (*(int*)(p2 + 0x1B8) != 0) fn_802E423C(p2, &sp);
    }
}
