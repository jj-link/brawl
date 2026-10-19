#pragma force_active on
extern "C" {
void fn_93_10C84(void* obj, int id);
void fn_93_10D18(void* obj, int id);

void fn_93_10448(void* unused, void* obj, int id) {
    switch (id) {
    case 0x116:
    case 0x11a:
    case 0x11b:
        break;
    default:
        fn_93_10C84(obj, 0x20000001);
        fn_93_10C84(obj, 0x20000002);
        break;
    }
    fn_93_10D18(obj, id);
}
}
