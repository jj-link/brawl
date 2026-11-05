#pragma force_active on
extern "C" void* fn_801C2C04();
extern "C" void* fn_801C2C9C(void* base, int index);
extern "C" void fn_801C22C8(void* arg0, void* arg1);
extern "C" void fn_801C238C(void* arg0, void* arg1);
extern "C" void fn_80036754(void);
extern "C" void fn_80036758(void);

extern "C" void fn_8003675C(int arg0, int arg1) {
    if (arg1 == 0) {
        fn_801C22C8(fn_801C2C9C(fn_801C2C04(), arg0), (void*)&fn_80036754);
    } else if (arg1 == -1) {
        fn_801C238C(fn_801C2C9C(fn_801C2C04(), arg0), (void*)&fn_80036758);
    }
}
