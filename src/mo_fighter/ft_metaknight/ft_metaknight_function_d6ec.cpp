#include <ft/ft_manager.h>

#pragma force_active on

class Class_6760 {
public:
    virtual void fn_111_5F38();
    virtual void fn_111_10718();
    virtual void fn_111_10FA4();
    virtual void fn_111_10F9C();
    virtual int fn_111_10F94(int);
    virtual void fn_111_10F8C(int, int);
    virtual void fn_111_10F84();
    virtual void fn_111_10F7C();
    virtual void fn_111_10F74();
    virtual void fn_111_10F6C();
    virtual void fn_111_10F64();
    virtual void fn_111_10F5C();
    virtual void fn_111_10F54();
    virtual void fn_111_10F4C();
    virtual void fn_111_10EFC();
    virtual void fn_111_10F44();
    virtual void fn_111_10F34();
    virtual void fn_111_10F24();
    virtual void fn_111_10F14(int);
};

extern "C" int fn_27_10B21C(ftManager*, int*);
extern "C" unsigned int fn_111_D8F0(int, void*);
extern "C" int fn_111_D870(void*);
extern "C" void fn_111_DAEC(void*);

extern "C" void fn_111_D6EC(void*, void* fighter) {
    for (int i = 0x20000003; i < 0x2000000a; ++i) {
        (*(Class_6760**)(*(char**)((char*)fighter + 0xd8) + 0x64))
            ->fn_111_10F8C(-1, i);
    }

    int entries[12];
    int count = fn_27_10B21C(g_ftManager, entries);
    long own = (*(Class_6760**)(*(char**)((char*)fighter + 0xd8) + 0x64))
                   ->fn_111_10F94(0x10000000);

    for (int i = 0; i < count; ++i) {
        if (own == entries[i]) {
            goto next;
        }
        if (fn_111_D8F0(*(const long*)&entries[i], fighter) != 1) {
            int slot = fn_111_D870(fighter);
            if (slot < 0) {
                break;
            }

            (*(Class_6760**)(*(char**)((char*)fighter + 0xd8) + 0x64))
                ->fn_111_10F8C(entries[i], slot);
            (*(Class_6760**)(*(char**)((char*)fighter + 0xd8) + 0x64))
                ->fn_111_10F14(0x22000010);
        }
    next:
        ;
    }

    fn_111_DAEC(fighter);
}
