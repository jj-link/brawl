#pragma force_active on

typedef unsigned char u8;

class Object48 {
    u8 padding[8];

public:
    virtual ~Object48();
};

class Object44 {
public:
    virtual ~Object44();
};

extern "C" {
extern u8 lbl_8045462C[];

int fn_803EF174(void*);
void fn_803EF044(void*, int);
int fn_801C8B20(void*);
void fn_801C8C14(void*);
void free__13gfHeapManagerFPv(void*);
void fn_801C0DBC(void*);
void __dt__6gfTaskFv(void*, int);
void __dl__FPv(void*);

void* fn_8007AF44(u8* object, int deleting) {
    if (object) {
        *reinterpret_cast<void**>(object + 0x3C) = lbl_8045462C;

        if (fn_803EF174(*reinterpret_cast<void**>(object + 0x54))) {
            fn_803EF044(*reinterpret_cast<void**>(object + 0x54), 1);
            *reinterpret_cast<void**>(object + 0x54) = 0;
        }

        if (fn_801C8B20(*reinterpret_cast<void**>(object + 0x48))) {
            fn_801C8C14(*reinterpret_cast<void**>(object + 0x48));
        }

        Object48* entry = *reinterpret_cast<Object48**>(object + 0x48);
        delete entry;

        free__13gfHeapManagerFPv(*reinterpret_cast<void**>(object + 0x4C));
        free__13gfHeapManagerFPv(*reinterpret_cast<void**>(object + 0x50));

        fn_801C0DBC(*reinterpret_cast<void**>(object + 0x44));

        Object44* other = *reinterpret_cast<Object44**>(object + 0x44);
        delete other;

        __dt__6gfTaskFv(object, 0);

        if (deleting > 0) {
            __dl__FPv(object);
        }
    }

    return object;
}
}
