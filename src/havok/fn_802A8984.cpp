#pragma force_active on

extern "C" void fn_802A83F8(int, int, int, void*, void*);
extern "C" char lbl_80487178[];

struct Vtable_Class_802A3938 {
    void* vtable;
};
class Class_802A3938 : public Vtable_Class_802A3938 {
public:
    char flag;
    int m;
    Class_802A3938(int x) {
        m = x;
        flag = 0;
        vtable = lbl_80487178;
    }
    ~Class_802A3938() {}
};

extern "C" void fn_802A8984(int arg0, int arg1, int arg2, int arg3) {
    Class_802A3938 local0(arg3);
    fn_802A83F8(arg1, arg0, arg2, &local0, lbl_80487178);
}
