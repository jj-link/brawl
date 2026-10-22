#pragma force_active on
extern "C" int fn_8014DD34(void*, int);
extern "C" int srGetAppInitialCode__Fv();
extern "C" int fn_8014E230(int, int);
extern "C" int fn_8014E0DC(void*, int);

struct Obj {
    virtual void call(int, int, int);
};

extern "C" int fn_8014DBDC(void* self) {
    if (fn_8014DD34(self, 1) == 0) {
        return 0;
    }
    int app = srGetAppInitialCode__Fv();
    int code = fn_8014E230(app, 0);
    if (code != 0) {
        if (fn_8014E0DC(self, code) != 0) {
            Obj* obj = *(Obj**)((char*)self + 8);
            if (obj != 0) {
                obj->call(3, code, 0x1ADAF);
            }
        }
        return 0;
    }
    return 1;
}
