#pragma force_active on
extern "C" {
void fn_802A6508(int, int, int);

void fn_802A98FC(int arg1, int arg2, int arg3) {
    fn_802A6508(arg1, arg3, arg2);
}
}
