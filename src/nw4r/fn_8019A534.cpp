#pragma force_active on
extern "C" void fn_8019DA5C(void* self, unsigned int mask, int flag);

class ObjBase {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19(int* a, int b, int c);

    unsigned char pad[0x10];
    unsigned short* flags;
};

struct Self {
    void* vtable;
    unsigned char pad[0xC];
    int count1;
    unsigned short* flags;
    int count2;
    ObjBase** objects;
};

extern "C" void fn_8019A534(void* self, int* arg1, int arg2, int arg3) {
    Self* s = (Self*)self;

    for (int i = 0; i < s->count2; i++) {
        ObjBase* obj = s->objects[i];
        if (obj != 0) {
            int val = *arg1;
            obj->v19(&val, arg2, arg3);
        }
    }

    int val = 0x8000;
    int i = 0;
    int off = 0;
    while (i < s->count1) {
        *(unsigned short*)((char*)s->flags + off) = (short)val;
        i++;
        off += 2;
    }

    fn_8019DA5C(self, 4, 0);

    for (int i = 0; i < s->count2; i++) {
        ObjBase* obj = s->objects[i];
        if (obj != 0) {
            for (unsigned int j = 0; j < (unsigned int)s->count1; j++) {
                if (!(obj->flags[j] & 0x8000)) {
                    s->flags[j] = 0;
                }
            }
        }
    }
}