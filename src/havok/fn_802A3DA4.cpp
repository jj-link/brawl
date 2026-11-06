#pragma force_active on

extern "C" void fn_802A3A4C(void* p, int arg1);

class SoHeapAllocator {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void* alloc(int size, int align);
};

extern SoHeapAllocator* lbl_805A0EB8;
extern char lbl_804867F8[];

struct Obj {
    void* vtable;
    unsigned short unk4;
};

struct InputValue {
    char pad[0xA0];
    float value;
};

struct Input {
    char pad[8];
    InputValue* value;
};

extern "C" void* fn_802A3DA4(const Input* arg0, const Input* arg1, int unused, int arg3) {
    const float left = arg0->value->value;
    const float right = arg1->value->value;
    if (left < right) {
        Obj* result = (Obj*)lbl_805A0EB8->alloc(0x40, 0x1D);
        result->unk4 = 0x40;
        if (result != 0) {
            fn_802A3A4C(result, arg3);
        }
        return result;
    } else {
        Obj* result = (Obj*)lbl_805A0EB8->alloc(0x40, 0x1D);
        result->unk4 = 0x40;
        if (result != 0) {
            fn_802A3A4C(result, arg3);
            result->vtable = &lbl_804867F8;
        }
        return result;
    }
}
