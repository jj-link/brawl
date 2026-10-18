#pragma force_active on
struct Inner {
    void* value;
};

struct Slot {
    int pad;
    Inner* inner;
};

struct List {
    int pad[2];
    Slot* slots;
    int count;
};

struct Obj {
    int pad[3];
    void* f;
};

extern "C" {
void fn_802EC1C0(void*, void*, int);
}

extern "C" void fn_20_A70(Obj* a, List* b) {
    for (int i = 0; i < b->count; i++) {
        fn_802EC1C0(a->f, b->slots[i].inner->value, 1);
    }
}
