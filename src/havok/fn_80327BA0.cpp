#pragma force_active on
class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5(void*, void*, void*, void*);
};

struct Arg1 {
    char pad0[8];
    signed char index;
    char pad9[7];
    Object_vptr_0* object;
    void* arg0;
    void* arg1;
};

struct Entry {
    char pad0[16];
    unsigned char value;
};

struct Arg2 {
    char* base;
    char pad4[8];
    unsigned char value;
    char padD[27];
    Entry* entry;
};

struct Arg3 {
    char* current;
    char pad4[12];
    char data[0x3020];
    float value;
    char pad3034[28];
    int field;
};

struct GlobalState {
    int pad0;
    int state;
    int size;
    char padC[8];
    int field14;
    char pad18[16];
    int field28;

    int available() {
        int sum = field28 + field14;
        if (size <= sum) {
        } else {
            return size - sum;
        }
        return 0;
    }
};

extern GlobalState* lbl_805A0EB8;
extern const float lbl_805A4814;

extern "C" int __cntlzw(unsigned int);
extern "C" void fn_802FF784(Arg1*, Arg2*, Arg3*);
extern "C" void fn_80327CDC(void*, Arg3*, Arg1*);

extern "C" void fn_80327BA0(void* self, Arg1* a, Arg2* b, Arg3* c) {
    int remaining = 0;

    c->current = c->data;
    c->value = lbl_805A4814;
    c->field = 0;

    b->entry = (Entry*)(b->base + a->index * 0x3C + 0x1A28);
    b->value = b->entry->value;
    fn_802FF784(a, b, c);

    GlobalState* g = lbl_805A0EB8;
    remaining = g->available();
    if (remaining == 0) {
        g->state = 1;
    }

    if (lbl_805A0EB8->state != 1) {
        if ((signed char)((unsigned int)__cntlzw(
                (unsigned int)c->data - (unsigned int)c->current) >> 5) == 0) {
            a->object->slot5(a->arg0, a->arg1, b, c);
        }
        int changed = lbl_805A4814 != c->value;
        if ((signed char)changed != 0) {
            fn_80327CDC(self, c, a);
        }
    }
}
