#pragma force_active on
struct Context { char pad[0xAE]; unsigned char enabled; };
struct Argument { char pad[0x24]; unsigned char* data; };
extern "C" {
void fn_80174AE8(Context*, void*);
void fn_80174B58(Context*, void*, void*);
void fn_80174E38(Context*, Argument*, void*, void*);
void fn_801F1330(int, int, int);
extern int lbl_8059E8A0;
void fn_801F0208(int, const void*, int);
void fn_801EFB10();
void fn_801EF280(int, int);
void fn_801EFB44(int, int, int, int, int);
void fn_801F52E4(int);
void fn_80178870(Context*, void*, Argument*);
void fn_80179C7C(Context*, void*, Argument*);
}
extern "C" void fn_80178734(Context* self, void* arg, Argument* input) {
    void* data = input->data + 0x9C;
    fn_80174AE8(self, data);
    fn_80174B58(self, data, arg);
    fn_80174E38(self, input, data, arg);
    fn_801F1330(0, 1, 1);
    fn_801F0208(13, &lbl_8059E8A0, 2);
    fn_801EFB10();
    fn_801EF280(9, 1);
    if (self->enabled != 0) fn_801EF280(13, 2);
    fn_801EFB44(0, 9, 1, 4, 0);
    fn_801EFB44(0, 13, 1, 0, 0);
    fn_801F52E4(0);
    if ((input->data[0x142] & 3) != 1)
        fn_80178870(self, arg, input);
    else
        fn_80179C7C(self, arg, input);
}