#pragma force_active on
extern "C" void fn_121_10CD0(void* acc, unsigned int flag);
extern "C" void fn_121_10D64(void* acc, int id);

extern "C" void fn_121_10A80(void*, void* acc, int id) {
    switch (id) {
    case 0x116:
    case 0x11A:
    case 0x11B:
        break;
    default:
        fn_121_10CD0(acc, 0x20000001);
        fn_121_10CD0(acc, 0x20000002);
        break;
    }
    fn_121_10D64(acc, id);
}
