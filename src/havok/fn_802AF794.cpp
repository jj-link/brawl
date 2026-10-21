#pragma force_active on
extern "C" {

void fn_802B29E4(void* arg);

void fn_802AF794(void* arg) {
    if (((char*)arg)[0x78] != 0)
        fn_802B29E4(arg);
}

}
