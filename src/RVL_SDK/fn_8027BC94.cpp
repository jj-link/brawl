#pragma force_active on
class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
};
extern "C" {
extern unsigned char lbl_80532448[0x18];
extern Object_vptr_0* lbl_805A0EC8;
void fn_8027FF7C(void*);
void fn_8027EC70(int);
void fn_8027ECBC(void);
int fn_8027BC94(void) {
    fn_8027FF7C(lbl_80532448);
    lbl_805A0EC8->slot1();
    fn_8027EC70(0);
    fn_8027ECBC();
    return 0;
}
}