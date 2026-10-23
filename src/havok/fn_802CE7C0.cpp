#pragma force_active on
extern "C" {
extern char lbl_804873C0[];
extern char lbl_804873E8[];

inline void* operator new(unsigned long, void* p)
{
    return p;
}

struct Obj {
    void* vtable;
    char pad0[2];
    short flags;
    char pad1[8];
    void* vtable2;
    char tail[4];

    Obj()
    {
        flags = 1;
        vtable = lbl_804873C0;
        vtable2 = lbl_804873E8;
    }
};

extern "C" void* fn_802CE7C0()
{
    __declspec(align(16)) char buf[sizeof(Obj)];
    Obj* obj = new (buf) Obj;
    return obj->vtable;
}
}
