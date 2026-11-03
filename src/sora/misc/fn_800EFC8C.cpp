#pragma force_active on

extern "C" {

void exit__6gfTaskFv(void*);
void fn_800B8EDC(void*, void*);
void fn_800B8A0C(void*, int);
void __dl__FPv(void*);
extern char lbl_8045B824[];

struct Part {
    char padding[0x5C];
    virtual void method(int);
};

void* fn_800EFC8C(void* arg0, int arg1) {
    if (arg0 != 0) {
        char* base = (char*)arg0;
        void* task = *(void**)(base + 0x5C);
        *(char**)(base + 0x74) = lbl_8045B824;
        if (task != 0) {
            exit__6gfTaskFv(task);
            *(void**)(base + 0x5C) = 0;
        }
        fn_800B8EDC(*(void**)(base + 0x30), *(void**)(base + 0x4));
        int i = 0;
        Part** cur = (Part**)arg0;
        do {
            Part* p = cur[1];
            if (p != 0) {
                if (p != 0) {
                    p->method(1);
                }
                cur[1] = 0;
            }
            i++;
            cur++;
        } while (i < 11);
        if (*(void**)(base + 0x30) != 0) {
            fn_800B8A0C(*(void**)(base + 0x30), 1);
            *(void**)(base + 0x30) = 0;
        }
        if (arg1 > 0) {
            __dl__FPv(arg0);
        }
    }
    return arg0;
}

}