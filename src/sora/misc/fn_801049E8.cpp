#pragma force_active on

class MenuObject {
    char padding[0x5C];

public:
    virtual void method(int);
};

extern "C" {
extern char lbl_8045D040[];
void fn_800B8A0C(void*, int);
void __dl__FPv(void*);

void* fn_801049E8(char* arg0, int arg1) {
    if (arg0 != 0) {
        int i = 0;
        MenuObject** cur = (MenuObject**)arg0;
        *(char**)(arg0 + 0x300) = lbl_8045D040;
        do {
            MenuObject* p = cur[1];
            if (p != 0) {
                if (p != 0) {
                    p->method(1);
                }
                cur[1] = 0;
            }
            i++;
            cur++;
        } while (i < 2);

        if (*(void**)(arg0 + 0xC) != 0) {
            fn_800B8A0C(*(void**)(arg0 + 0xC), 1);
            *(void**)(arg0 + 0xC) = 0;
        }

        if (arg1 > 0) {
            __dl__FPv(arg0);
        }
    }
    return arg0;
}
}
