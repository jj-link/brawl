#include <types.h>
#pragma force_active on

class Class_8027D01C {
public:
    Class_8027D01C();
    ~Class_8027D01C();
    void* unk0;
    void* unk4;
};

class SoHeapAllocator {
public:
    virtual ~SoHeapAllocator();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void* alloc(u32 size, s32 align);
};

class Object_vptr_0 {
public:
    virtual ~Object_vptr_0();
    virtual void slot1();
    virtual void slot2();
    virtual Object_vptr_0* slot3();
    virtual void slot4(void* list);

    u16 size;
    s16 refs;
};

struct Entry {
    const char* key;
    void** list;
};

class Owner {
public:
    char pad0[0x14];
    char sub[4];
};

extern "C" {
extern char lbl_804156C0[];
extern char lbl_80488EB8[];
extern Entry lbl_805A5120[];
extern Object_vptr_0* lbl_805A0F38;
extern SoHeapAllocator* lbl_805A0EB8;

s32 fn_8027DFFC(void* obj, const char* name, void** out);
void fn_8027DDFC(void* obj, const char* key, void* value);
void fn_8027DC18(void* dst, const char* src);
s32 fn_80281AE8(const char* a, const char* b);
void fn_80333750(void** p);
void fn_80333D24(void** a, void* b, Class_8027D01C* c);
}

inline int findEntry(Owner* self, const char* name, void*& result, void*& value) {
    if (fn_8027DFFC(self->sub, name, &value) == 0) {
        result = value;
        return 0;
    }
    return 1;
}

extern "C" void* fn_8033499C(Owner* self, const char* name) {
    void** p;
    void* value;
    void* sp8;
    void* result;

    if (findEntry(self, name, result, value) == 0) {
        return result;
    }

    Entry* e = lbl_805A5120;
    result = 0;
    for (; e->key != 0; e++) {
        if (fn_80281AE8(name, e->key) == 0) {
            if (fn_80281AE8(name, lbl_804156C0) == 0) {
                result = lbl_805A0F38->slot3();
                if (((Object_vptr_0*)result)->size != 0) {
                    ((Object_vptr_0*)result)->refs++;
                }
            } else {
                Object_vptr_0* o =
                    (Object_vptr_0*)lbl_805A0EB8->alloc(0x14, 0x13);
                o->size = 0x14;
                result = o;
                if (o != 0) {
                    o->refs = 1;
                    *(void**)o = lbl_80488EB8;
                    fn_8027DC18((char*)o + 8, lbl_80488EB8);
                }

                p = e->list;
                fn_80333750(&sp8);
                {
                    Class_8027D01C sp10;
                    for (; *p != 0; p++) {
                        fn_80333D24(&sp8, *p, &sp10);
                    }
                }
                ((Object_vptr_0*)result)->slot4(e->list);
            }
            fn_8027DDFC(self->sub, e->key, result);
            break;
        }
    }
    return result;
}
