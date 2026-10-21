#pragma force_active on
extern "C" int fn_802E1E40(char* arg0) {
    int a = *(int*)(arg0 + 0x70);
    int b = *(int*)(arg0 + 0x7C);
    return a + b;
}
#pragma force_active reset
