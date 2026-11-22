#pragma force_active on

extern "C" void fn_8027EABC(void*, void*, unsigned int, int);
class Allocator;
extern Allocator* lbl_805A0EC8;

struct Array {
    void* data;
    int size;
    unsigned int capacity;
    void* mark;
    unsigned int isUnowned() const { return capacity & 0x80000000; }
    void dealloc() { fn_8027EABC(lbl_805A0EC8, data, capacity << 3, 0x15); }
};

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2(void*, void*, Array*);
    virtual void* slot3(void*, void*, float);
    virtual void slot4();
};

class Allocator {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void* slot3(unsigned int);
    virtual void slot4();

    char pad[12];
    char* current;
    char* unused;
    char* start;
    char* end;
};

struct Scale {
    char pad[8];
    float value;
};

struct Parent {
    char pad0[0x54];
    Object_vptr_0* obj;
    void* table;
    char pad1[0xc];
    Scale* scale;
    char* test;
    char pad2[0x274];
    int count;
};

struct Input {
    char pad[0x1c];
    Object_vptr_0* obj;
    char pad1[4];
    void* value;
    char pad2[8];
    char data[1];
};

extern Allocator* lbl_805A0EC8;
extern float lbl_805A4540;

extern "C" void fn_802CAEE8(void*, void*, int, void*);
extern "C" void fn_8027EABC(void*, void*, unsigned int, int);

extern "C" void fn_802F80F8(Parent* self, Input* input) {
    if (input->obj) {
        int count = self->count;
        Array a;
        char buffer[0x20] __attribute__((aligned(16)));

        a.data = 0;
        a.size = 0;
        a.capacity = 0x80000000;

        unsigned int bytes = (count * 8 + 16) & ~15;
        char* p = lbl_805A0EC8->current;
        if (p + bytes <= lbl_805A0EC8->end)
            lbl_805A0EC8->current = p + bytes;
        else
            p = (char*)lbl_805A0EC8->slot3(bytes);

        a.data = p;
        a.capacity = count | 0x80000000;
        a.mark = p;

        float scale = self->scale->value;
        scale = lbl_805A4540 * scale;
        input->obj->slot3(input->value, buffer, scale);
        self->obj->slot2(input->data, buffer, &a);

        if (a.size > 0) {
            char* test = self->test;
            if (test)
                test += 8;
            int size = a.size;
            void* data = a.data;
            void* table = self->table;
            fn_802CAEE8(table, data, size, test);
        }

        char* mark = (char*)a.mark;
        Allocator* allocator = lbl_805A0EC8;
        allocator->current = mark;
        if (mark == allocator->start)
            allocator->slot4();

        if (!a.isUnowned()) {
            a.dealloc();
        }
    }
}
