#pragma force_active on
extern "C" {
void fn_802DE264(char*, int, int);

void fn_80325C20(char* arg0, int arg1) {
    char* end = arg0 + 0x13A;
    fn_802DE264(arg0 + 0x10, (int)end - (int)(arg0 + 0x10), arg1);
}
}
