#pragma force_active on
extern "C" unsigned char lbl_80487CD0[];

struct FnObj {
    void* vtable;
    unsigned short memSizeAndFlags;
    unsigned short referenceCount;
    unsigned char pad[0xF8];
};

extern "C" void* fn_802E4758() {
    __declspec(align(16)) FnObj obj;
    if (&obj != 0) {
        obj.referenceCount = 1;
        obj.vtable = lbl_80487CD0;
    }
    return obj.vtable;
}
