#pragma force_active on

class Class_8042EA48 {
public:
    virtual void fn_8005C534();
    virtual void fn_8005C2B0();
    virtual void fn_8005C20C();
    virtual void fn_8005C1BC();
    virtual void fn_8005C198();
    virtual void fn_8005C17C();
    virtual void fn_8005C160();
    virtual void fn_8005C0BC();
    virtual void fn_8005C06C();
    virtual void fn_8005C048();
    virtual void fn_8005C02C();
    virtual void fn_8005C010();
    virtual void fn_8005BF6C();
    virtual void fn_8005BF1C();
    virtual void fn_8005BEF8();
    virtual void fn_8005BEDC();
    virtual void fn_8005BEC0();
    virtual void fn_8005BE1C();
    virtual void fn_8005BDCC();
    virtual void fn_8005BDA8();
    virtual void fn_8005BD8C();
    virtual void fn_8005BD70();
    virtual void* fn_8005B2FC(unsigned long);
};

extern "C" {
void fn_8015BF9C(void*, int);
void fn_801648C0(void*);
void* __construct_new_array(void*, void (*)(void*), void*, unsigned long, int);

extern int lbl_805A04C0;
extern int lbl_805A04C4;
extern int lbl_805A04C8;

struct Part {
    void* data;
    unsigned int size;
    unsigned short count;

    void clear() {
        data = 0;
        count = 0;
        size = 0;
    }
};

struct Entry {
    Part a;
    Part b;
    unsigned short count;

    void init() {
        fn_8015BF9C(&a, 0x14);
        fn_8015BF9C(&b, 0x14);
        count = 0;
    }

    void clear() {
        a.clear();
        b.clear();
        count = 0;
    }
};

struct Object {
    Class_8042EA48* allocator;
    int* x;
    int* y;
    int* z;
    char pad[0x5004];
    unsigned long count;
    Entry* entries;
    int value;
};

int fn_801647C0(Object* self, unsigned int count) {
    unsigned long arrayCount = count;
    self->count = count;
    self->entries = (Entry*)__construct_new_array(
        self->allocator->fn_8005B2FC(arrayCount * sizeof(Entry) + 0x20),
        fn_801648C0,
        0,
        sizeof(Entry),
        arrayCount);

    for (unsigned long i = 0; i < self->count; ++i) {
        self->entries[i].init();
        self->entries[i].clear();
    }

    self->value = 0;
    self->x = &lbl_805A04C0;
    self->y = &lbl_805A04C4;
    self->z = &lbl_805A04C8;
    return 1;
}
}
