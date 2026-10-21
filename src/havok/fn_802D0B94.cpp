#pragma force_active on
extern "C" {
extern char lbl_80487488[];
extern char lbl_804873E8[];
}

inline void* operator new(unsigned long, void* p)
{
    return p;
}

struct Obj {
    void* vtable;
    short flags;
    short refs;
    char pad[8];
    void* vtable2;
    char tail[0x1c];

    Obj()
    {
        refs = 1;
        vtable = lbl_80487488;
        vtable2 = lbl_804873E8;
    }
};

extern "C" void* fn_802D0B94()
{
    __declspec(align(16)) char buf[sizeof(Obj)];
    Obj* obj = new (buf) Obj;
    return *(void**)buf;
}
