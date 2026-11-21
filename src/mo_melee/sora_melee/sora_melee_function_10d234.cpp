#include <types.h>
#include <ft/ft_entry_manager.h>
#pragma force_active on

struct Entry { char pad[4]; u32 id; };
struct Class_90D8_base { char pad[0x8]; };
class Class_90D8 : public Class_90D8_base {
public:
    virtual void fn_27_7B274();
    virtual Entry** fn_27_7AC18(int);
    virtual void fn_27_7AC28();
    virtual int fn_27_7AB50();
};
struct Sub {
    virtual void fn_27_7B274();
    virtual Entry** fn_27_7AC18(int);
    virtual void fn_27_7AC28();
    virtual int fn_27_7AB50();
};
struct EM { char pad[8]; Sub sub; };
struct ftManager {
    char pad[0x6e];
    u8 f6e;
    char pad2[0xe5];
    ftEntryManager* em;
    void setSlow(int, bool, int, int);
};
extern "C" {
int fn_27_116F60(ftEntry*, int, int);
void fn_27_116B7C(Entry*, int, int, int, int);
}
void ftManager::setSlow(int a, bool b, int c, int d) {
    int n = ((EM*)em)->sub.fn_27_7AB50();
    int f;
    Entry* e;
    int i;
    for (i = 0; i < n; i++) {
        e = *((EM*)em)->sub.fn_27_7AC18(i);
        u8 v = f6e;
        u32 id = e->id;
        f = ((((unsigned)v >> 7) & 1u) == 1 && ((v >> 6) & 1u) == 1);
        ftEntry* r = em->getEntity(id);
        if (a != fn_27_116F60(r, f, 1))
            fn_27_116B7C(e, b, c, d, 0);
    }
}