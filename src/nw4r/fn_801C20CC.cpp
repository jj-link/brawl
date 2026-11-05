#pragma force_active on

struct Obj {
    unsigned char pad[0xB8];
    unsigned int unkB8;
    unsigned int unkBC;
    unsigned int unkC0;
};

extern "C" {
unsigned int fn_801C0A0C(unsigned int* arg0);
Obj* fn_801C200C(Obj* arg0);

void fn_801C20CC(void* arg0, unsigned int arg1) {
    Obj* obj = (Obj*)fn_801C0A0C((unsigned int*)((char*)arg0 + 8));
    if (obj == 0) {
        obj = 0;
    } else if (obj != 0) {
        obj = fn_801C200C(obj);
    }
    if (obj != 0) {
        obj->unkB8 = arg1;
        obj->unkC0 = *(unsigned int*)((char*)arg0 + 4);
    }
}
}
