#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

extern "C" void* getNode__6utListFUl(void*, u32);

struct Object {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual int query(int);
};

extern "C" bool fn_27_6BF60(Object* self) {
    if (self->query(-1)) {
        u8* node = (u8*)getNode__6utListFUl((u8*)self + 0x20, 0);
        while (node) {
            u8* object = *(u8**)(node + 0xc);
            if ((*(u32*)(object + 0x30) >> 8) & 1)
                return true;
            node = *(u8**)node;
        }
    }
    return false;
}
