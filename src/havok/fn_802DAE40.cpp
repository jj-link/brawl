#pragma force_active on
struct E { char x[8]; };

extern "C" void* fn_802DAE40(void* arg0, void* arg1) {
    E* arr = (E*)arg1;
    return (char*)&arr[*(int*)((char*)arg0 + 0x1c) * 6];
}
