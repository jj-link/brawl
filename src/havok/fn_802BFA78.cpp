#pragma force_active on

extern "C" void fn_802BED5C(int, int, int, void*, void*);
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

extern "C" void fn_802BFA78(int arg0, int arg1, int arg2, int arg3) {
    Class_802A3938 local0(arg3);
    fn_802BED5C(arg1, arg0, arg2, &local0, lbl_80487178);
}