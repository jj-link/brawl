#pragma force_active on
extern "C" float fn_802D2714(void);
extern "C" char lbl_80487548[];
extern float lbl_8059EFB8;
extern const float lbl_805A40D8;
extern const float lbl_805A40E4;

class Class_80099F70 {
public:
    Class_80099F70() {}
    ~Class_80099F70() {}
};

struct Vtable_Class_802D279C {
    void* vtable;
    Vtable_Class_802D279C() : vtable(lbl_80487548) {}
};

class Class_802D279C : public Class_80099F70, public Vtable_Class_802D279C {
public:
    Class_802D279C();
    char pad4[2];
    short unk6;
};

Class_802D279C::Class_802D279C() {
    unk6 = 1;
    if (lbl_8059EFB8 < lbl_805A40D8) {
        lbl_8059EFB8 = lbl_805A40E4 - fn_802D2714();
    }
}