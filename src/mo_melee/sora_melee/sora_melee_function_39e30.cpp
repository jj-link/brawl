#include <types.h>
#pragma force_active on

extern "C" void fn_27_36354(void*);
extern "C" void fn_27_366BC(void*, int);
extern "C" void fn_27_38988(int*);

class Arr {
public:
    virtual void v0() = 0;
    virtual int* at(int i) = 0;
    virtual void v2() = 0;
    virtual int size() = 0;
};

struct Flags {
    unsigned pad0 : 1;
    unsigned flag : 1;
    unsigned rest : 30;
};

struct MainObj {
    char pad[0x30];
    Arr* m_arr;
    char pad2[0x34];
    char m_68[0x34];
    Flags flags;
};

extern "C" void fn_27_39E30(MainObj* self, int arg1) {
    self->flags.flag = arg1;
    if (!self->flags.flag) {
        int i = 0;
        while (i < self->m_arr->size()) {
            int* elem = self->m_arr->at(i);
            if (*elem != 0) {
                fn_27_38988(self->m_arr->at(i));
            }
            i++;
        }
    } else {
        fn_27_36354((char*)self + 0x68);
        fn_27_366BC(self->m_68, 0);
    }
}
