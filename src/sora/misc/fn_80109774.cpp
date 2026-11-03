#pragma force_active on

extern "C" {

void Destroy__Q34nw4r3g3d6G3dObjFv(void*);
void exit__6gfTaskFv(void*);
void __dl__FPv(void*);

struct Part {
    char padding[0x5C];
    virtual void method(int);
};

void* fn_80109774(void* arg0, int arg1) {
    if (arg0 != 0) {
        char* base = (char*)arg0;
        for (int i = 0; i < 7; i++) {
            Part* p = (Part*)(*(void**)(base + 0xE8));
            if (p != 0) {
                if (p != 0) {
                    p->method(1);
                }
                *(void**)(base + 0xE8) = 0;
            }
            base += 4;
        }

        if (*(void**)((char*)arg0 + 0x110) != 0) {
            Destroy__Q34nw4r3g3d6G3dObjFv(*(void**)((char*)arg0 + 0x110));
            *(void**)((char*)arg0 + 0x110) = 0;
        }

        if (*(void**)((char*)arg0 + 0x12C) != 0) {
            exit__6gfTaskFv(*(void**)((char*)arg0 + 0x12C));
            *(void**)((char*)arg0 + 0x12C) = 0;
        }

        if (*(void**)((char*)arg0 + 0x138) != 0) {
            exit__6gfTaskFv(*(void**)((char*)arg0 + 0x138));
            *(void**)((char*)arg0 + 0x138) = 0;
        }

        if (arg1 > 0) {
            __dl__FPv(arg0);
        }
    }
    return arg0;
}

}