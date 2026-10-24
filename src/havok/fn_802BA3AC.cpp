#pragma force_active on

extern "C" void fn_802B9BA0(int, int, int, int, int);

extern "C" char lbl_80487178[];  // the vtable of Class_802A3938, under its name in the game
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

extern "C" void fn_802BA3AC(int arg0, int arg1, int arg2, int arg3) {
    Class_802A3938 local0(arg3);
    fn_802B9BA0(arg1, arg0, arg2, (int)&local0, (int)lbl_80487178);
}
