#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

class Inst {
public:
    virtual void v0();
    virtual u32 v1(int key);
};

struct Entry {
    u8 flag;
    u8 pad[3];
    int key;
    u8 pad2[4];
    void* value;
};

struct Owner {
    u8 pad[0xC];
    u32 count;
};

extern "C" Inst* getInstance__6emInfoFv();
extern "C" Entry* fn_41_D5A0(Owner* self, u32 idx);

extern "C" void* fn_41_D828(Owner* self, int key) {
    if (getInstance__6emInfoFv()->v1(key) == 1) {
        return 0;
    }
    for (u32 i = 0; i < self->count; i++) {
        Entry* e = fn_41_D5A0(self, i);
        if (e != 0 && e->flag != 0 && e->key == key) {
            return e->value;
        }
    }
    return (void*)-5;
}
