#pragma force_active on
typedef unsigned int u32;
typedef unsigned char u8;

struct Entry {
    int dummy;
};

struct Holder {
    u8 pad[0x1EC];
    u32 count;
    Entry* head;
};

extern "C" void fn_8015C2BC(void* self, void*& out);

extern "C" void fn_63_15394(Holder* self) {
    Entry* p;
    for (u32 i = 0, n = self->count; i != n; i++) {
        p = self->head;
        void* tmp = p;
        fn_8015C2BC(&self->count, tmp);
        if (p) delete p;
    }
}
