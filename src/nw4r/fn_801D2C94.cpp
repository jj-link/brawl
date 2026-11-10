#pragma force_active on

extern "C" void fn_801D1140(void*);
extern "C" void fn_801D0DA4(void*);
extern "C" void fn_8015C2BC(void*, void**);
extern "C" int OSDisableInterrupts();
extern "C" void OSRestoreInterrupts(int);

struct Self {
    unsigned char flag;
    char pad[3];
    int count1;
    int ptr1;
    char pad2[4];
    int count2;
    int node;
};

typedef void (*ObjFunc)(char*, int, int);

struct B {
    char pad[8];
};

struct Inner : B {
    virtual void f0(int);
};

extern "C" void fn_801D2C94(Self* self) {
    if (self->flag != 0) {
        int intState = OSDisableInterrupts();

        while (self->count1 != 0) {
            char* obj = (char*)self->ptr1 - 0x124;
            fn_801D1140(obj);
            ObjFunc fp = *(ObjFunc*)(obj + 0xa4);
            if (fp != 0) {
                fp(obj, 1, *(int*)(obj + 0xa8));
            }
            fn_801D0DA4(obj);
        }
        OSRestoreInterrupts(intState);

        while (self->count2 != 0) {
            char* node = (char*)self->node;
            void* out;
            out = (void*)node;
            fn_8015C2BC(&self->count2, &out);
            Inner* p = (Inner*)(node - 0x124);
            p->f0(-1);
        }
        self->flag = 0;
    }
}
