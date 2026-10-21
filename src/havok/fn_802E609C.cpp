#pragma force_active on
struct UnkObj;
struct Foo;

extern "C" void* fn_802E5B14();
extern "C" void fn_802E5AE0(UnkObj* arg0);
extern "C" void fn_802E5B00(Foo* p);
extern "C" char lbl_804131E8[];

struct Unk16 {
    void* unk0;
    void* unk4;
    void* unk8;
    void* unkC;
};

extern Unk16 lbl_80533170;

extern "C" void fn_802E609C(void) {
    void* temp_r3;

    temp_r3 = fn_802E5B14();
    lbl_80533170.unk0 = lbl_804131E8;
    lbl_80533170.unk4 = (void*)fn_802E5AE0;
    lbl_80533170.unk8 = (void*)fn_802E5B00;
    lbl_80533170.unkC = temp_r3;
}

__declspec(section ".ctors") extern void* const fn_802E609C_ctor = (void*)fn_802E609C;
