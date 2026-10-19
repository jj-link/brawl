#pragma force_active on
extern "C" void fn_117_66FC(void*, int);
extern "C" char lbl_117_data_91A0[];

extern "C" void* fn_117_13E3C(void* object, int arg) {
    fn_117_66FC(object, 0);
    *reinterpret_cast<void**>(object) = lbl_117_data_91A0;
    reinterpret_cast<int*>(object)[2] = arg;
    reinterpret_cast<int*>(object)[3] = -1;
    return object;
}
