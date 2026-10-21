#pragma force_active on
extern "C" {

void fn_802B2A68(int arg);

void fn_802AF7BC(int arg) {
    if (*(signed char*)(arg + 0x78))
        fn_802B2A68(arg);
}

}
