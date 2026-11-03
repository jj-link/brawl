#pragma force_active on

extern "C" {

extern void* lbl_80465854[];
extern int lbl_805A0508;
void fn_80204E6C(int, void*);
void fn_8018C1B0(void*);
void fn_80182894(void*, int);
void __dl__FPv(void* p);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dt__Q34nw4r2ut5ColorFv(void* ptr, int destroyFlag);

class Elem {
public:
    virtual void v0(int);
};

struct Entry {
    int a;
    Elem* obj;
};

class Other {
public:
    virtual void v0(int);
    char pad[0x55];
    unsigned char flag;
};

void* fn_801858D0(void* arg0, int arg1) {
    if (arg0 != 0) {
        char* self = (char*)arg0;
        *(void***)self = lbl_80465854;
        if (*(Entry**)(self + 0xFC) != 0) {
            for (int i = 0; i < *(unsigned char*)(self + 0x100); i++) {
                (*(Entry**)(self + 0xFC))[i].obj->v0(-1);
                fn_80204E6C(lbl_805A0508, (*(Entry**)(self + 0xFC))[i].obj);
            }
            fn_80204E6C(lbl_805A0508, *(Entry**)(self + 0xFC));
        }
        Other* o = *(Other**)(self + 0x28);
        if (o != 0 && o->flag == 0) {
            o->v0(-1);
            fn_80204E6C(lbl_805A0508, *(Other**)(self + 0x28));
            *(Other**)(self + 0x28) = 0;
        }
        fn_8018C1B0(self + 0xF4);
        if (self + 0xE4) {
            __destroy_arr(self + 0xE4, __dt__Q34nw4r2ut5ColorFv, 4, 4);
        }
        fn_80182894(arg0, 0);
        if (arg1 > 0) {
            __dl__FPv(arg0);
        }
    }
    return arg0;
}

}
