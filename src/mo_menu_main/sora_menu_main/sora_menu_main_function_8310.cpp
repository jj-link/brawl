#pragma force_active on
struct Obj {
    char pad[0x40];
    char* list;
};

extern "C" {
void fn_801A12AC(unsigned int);
void fn_801ACDB0(void*);
}

extern "C" void fn_2_8310(Obj* p) {
    void* item;
    unsigned int off = 0;
    int i = 0;
    for (; i < 2; i++) {
        item = *(void**)(p->list + off);
        if (item != 0) {
            fn_801A12AC(0x7ff);
            fn_801ACDB0(item);
        }
        off += 8;
    }
}
