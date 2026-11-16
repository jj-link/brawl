#include <wn/weapon.h>
#include <so/article/so_article.h>
#pragma force_active on
extern "C" { extern unsigned char lbl_27_bss_1CC[];
void fn_27_8D7C4(void*); void fn_27_8D7D0(void*,short); bool fn_27_8D810(void*,soArticle*);
void* fn_27_8D6EC(int,int,int); void* fn_27_8D78C();
unsigned int fn_122_DD10(Weapon*,void*); unsigned int fn_122_DDF8(Weapon*,void*); unsigned int fn_122_DEE0(Weapon*,void*);
unsigned int fn_122_DF54(Weapon*,void*); unsigned int fn_122_E074(Weapon*,void*); unsigned int fn_122_E140(Weapon*,void*);
unsigned int fn_122_E1E4(Weapon*,void*); unsigned int fn_122_E520(Weapon*,void*); unsigned int fn_122_E5A8(Weapon*,void*);
unsigned int fn_122_E660(Weapon*,void*); unsigned int fn_122_E718(Weapon*,void*); unsigned int fn_122_E7A0(Weapon*,void*);
unsigned int fn_122_E9BC(Weapon*,void*); }
namespace {
struct StateBank { char action[13]; char pad[8]; char status[26]; char gap; soArticle* selectors[13]; };
struct StageObject { char pad[0x28]; int id; int getId() const { return id; } };
struct StageRoot { char pad[8]; StageObject* stage; };
class Class_E104 { public:
virtual void fn_122_ABB4(); virtual void fn_122_176B0(); virtual void fn_122_18F4C(); virtual void fn_122_18F44();
virtual void fn_122_18F3C(); virtual void fn_122_18F34(); virtual void fn_122_18F2C(); virtual void fn_122_18F24();
virtual void fn_122_18F1C(); virtual void fn_122_18F14(); virtual void fn_122_18F0C(); virtual void fn_122_18F04();
virtual void fn_122_18EFC(); virtual void fn_122_18EF4(); virtual void fn_122_18EA4(); virtual void fn_122_18EEC();
virtual void fn_122_18EDC(); virtual void fn_122_18ECC(); virtual void fn_122_18EBC(); virtual int fn_122_18EAC(int);
}; }
extern "C" soArticle* fn_122_FC0C(char* p,unsigned kind,void* accesser) {
    StateBank state; Weapon* owner;
    switch(kind) {
    case 0: {
        state.status[24] = 0;
        state.status[25] = 0;
        fn_27_8D7C4(&state.selectors[12]);
        state.action[12] = 0;
        if (fn_27_8D810(&state.selectors[12], reinterpret_cast<soArticle*>(p + 0x22104)) == true)
            owner = reinterpret_cast<Weapon*>(p + 0x2207c);
        else owner = 0;
        if (owner == 0) {
            owner = reinterpret_cast<Weapon*>(state.selectors[12]);
            if (owner != 0) owner = reinterpret_cast<Weapon*>(reinterpret_cast<char*>(owner) - 0x88);
            if (owner == 0) {
                fn_27_8D7D0(&state.selectors[12], (short)-1);
                return reinterpret_cast<soArticle*>(lbl_27_bss_1CC);
            }
            owner->deactivateArticle();
        }
        if (fn_122_DD10(owner, accesser) == 1) {
            fn_27_8D7D0(&state.selectors[12], (short)-1);
            return reinterpret_cast<soArticle*>(reinterpret_cast<char*>(owner) + 0x88);
        }
        fn_27_8D7D0(&state.selectors[12], (short)-1);
        return reinterpret_cast<soArticle*>(lbl_27_bss_1CC);
    }
    case 1: {
        state.status[22] = 0;
        state.status[23] = 0;
        fn_27_8D7C4(&state.selectors[11]);
        state.action[11] = 0;
        if (fn_27_8D810(&state.selectors[11], reinterpret_cast<soArticle*>(p + 0x1a410)) == true)
            owner = reinterpret_cast<Weapon*>(p + 0x1a388);
        else owner = 0;
        if (owner == 0) {
            owner = reinterpret_cast<Weapon*>(state.selectors[11]);
            if (owner != 0) owner = reinterpret_cast<Weapon*>(reinterpret_cast<char*>(owner) - 0x88);
            if (owner == 0) {
                fn_27_8D7D0(&state.selectors[11], (short)-1);
                return reinterpret_cast<soArticle*>(lbl_27_bss_1CC);
            }
            owner->deactivateArticle();
        }
        if (fn_122_DDF8(owner, accesser) == 1) {
            fn_27_8D7D0(&state.selectors[11], (short)-1);
            return reinterpret_cast<soArticle*>(reinterpret_cast<char*>(owner) + 0x88);
        }
        fn_27_8D7D0(&state.selectors[11], (short)-1);
        return reinterpret_cast<soArticle*>(lbl_27_bss_1CC);
    }
    case 2: {
        state.status[20] = 0;
        state.status[21] = 0;
        fn_27_8D7C4(&state.selectors[10]);
        state.action[10] = 0;
        if (fn_27_8D810(&state.selectors[10], reinterpret_cast<soArticle*>(p + 0x18d54)) == true)
            owner = reinterpret_cast<Weapon*>(p + 0x18ccc);
        else owner = 0;
        if (owner == 0) {
            owner = reinterpret_cast<Weapon*>(state.selectors[10]);
            if (owner != 0) owner = reinterpret_cast<Weapon*>(reinterpret_cast<char*>(owner) - 0x88);
            if (owner == 0) {
                fn_27_8D7D0(&state.selectors[10], (short)-1);
                return reinterpret_cast<soArticle*>(lbl_27_bss_1CC);
            }
            owner->deactivateArticle();
        }
        if (fn_122_DEE0(owner, accesser) == 1) {
            fn_27_8D7D0(&state.selectors[10], (short)-1);
            return reinterpret_cast<soArticle*>(reinterpret_cast<char*>(owner) + 0x88);
        }
        fn_27_8D7D0(&state.selectors[10], (short)-1);
        return reinterpret_cast<soArticle*>(lbl_27_bss_1CC);
    }
    case 3: {
        state.status[18] = 0;
        state.status[19] = 0;
        fn_27_8D7C4(&state.selectors[9]);
        state.action[9] = 0;
        if (fn_27_8D810(&state.selectors[9], reinterpret_cast<soArticle*>(p + 0x16b28)) == true)
            owner = reinterpret_cast<Weapon*>(p + 0x16aa0);
        else owner = 0;
        if (owner == 0) {
            owner = reinterpret_cast<Weapon*>(state.selectors[9]);
            if (owner != 0) owner = reinterpret_cast<Weapon*>(reinterpret_cast<char*>(owner) - 0x88);
            if (owner == 0) {
                fn_27_8D7D0(&state.selectors[9], (short)-1);
                return reinterpret_cast<soArticle*>(lbl_27_bss_1CC);
            }
            owner->deactivateArticle();
        }
        if (fn_122_DF54(owner, accesser) == 1) {
            fn_27_8D7D0(&state.selectors[9], (short)-1);
            return reinterpret_cast<soArticle*>(reinterpret_cast<char*>(owner) + 0x88);
        }
        fn_27_8D7D0(&state.selectors[9], (short)-1);
        return reinterpret_cast<soArticle*>(lbl_27_bss_1CC);
    }
    case 4: {
        state.status[16] = 0;
        state.status[17] = 0;
        fn_27_8D7C4(&state.selectors[8]);
        state.action[8] = 0;
        if (fn_27_8D810(&state.selectors[8], reinterpret_cast<soArticle*>(p + 0x146ec)) == true)
            owner = reinterpret_cast<Weapon*>(p + 0x14664);
        else owner = 0;
        if (owner == 0) {
            owner = reinterpret_cast<Weapon*>(state.selectors[8]);
            if (owner != 0) owner = reinterpret_cast<Weapon*>(reinterpret_cast<char*>(owner) - 0x88);
            if (owner == 0) {
                fn_27_8D7D0(&state.selectors[8], (short)-1);
                return reinterpret_cast<soArticle*>(lbl_27_bss_1CC);
            }
            owner->deactivateArticle();
        }
        if (fn_122_E074(owner, accesser) == 1) {
            fn_27_8D7D0(&state.selectors[8], (short)-1);
            return reinterpret_cast<soArticle*>(reinterpret_cast<char*>(owner) + 0x88);
        }
        fn_27_8D7D0(&state.selectors[8], (short)-1);
        return reinterpret_cast<soArticle*>(lbl_27_bss_1CC);
    }
    case 5: {
        state.status[14] = 0;
        state.status[15] = 0;
        fn_27_8D7C4(&state.selectors[7]);
        state.action[7] = 0;
        if (fn_27_8D810(&state.selectors[7], reinterpret_cast<soArticle*>(p + 0x1337c)) == true)
            owner = reinterpret_cast<Weapon*>(p + 0x132f4);
        else owner = 0;
        if (owner == 0) {
            owner = reinterpret_cast<Weapon*>(state.selectors[7]);
            if (owner != 0) owner = reinterpret_cast<Weapon*>(reinterpret_cast<char*>(owner) - 0x88);
            if (owner == 0) {
                fn_27_8D7D0(&state.selectors[7], (short)-1);
                return reinterpret_cast<soArticle*>(lbl_27_bss_1CC);
            }
            owner->deactivateArticle();
        }
        if (fn_122_E140(owner, accesser) == 1) {
            fn_27_8D7D0(&state.selectors[7], (short)-1);
            return reinterpret_cast<soArticle*>(reinterpret_cast<char*>(owner) + 0x88);
        }
        fn_27_8D7D0(&state.selectors[7], (short)-1);
        return reinterpret_cast<soArticle*>(lbl_27_bss_1CC);
    }
    case 6: {
        state.status[12] = 0;
        state.status[13] = 0;
        fn_27_8D7C4(&state.selectors[6]);
        state.action[6] = 0;
        if (fn_27_8D810(&state.selectors[6], reinterpret_cast<soArticle*>(p + 0xcbac)) == true)
            owner = reinterpret_cast<Weapon*>(p + 0xcb24);
        else owner = 0;
        if (owner == 0) {
            owner = reinterpret_cast<Weapon*>(state.selectors[6]);
            if (owner != 0) owner = reinterpret_cast<Weapon*>(reinterpret_cast<char*>(owner) - 0x88);
            if (owner == 0) {
                fn_27_8D7D0(&state.selectors[6], (short)-1);
                return reinterpret_cast<soArticle*>(lbl_27_bss_1CC);
            }
            owner->deactivateArticle();
        }
        if (fn_122_E1E4(owner, accesser) == 1) {
            fn_27_8D7D0(&state.selectors[6], (short)-1);
            return reinterpret_cast<soArticle*>(reinterpret_cast<char*>(owner) + 0x88);
        }
        fn_27_8D7D0(&state.selectors[6], (short)-1);
        return reinterpret_cast<soArticle*>(lbl_27_bss_1CC);
    }
    case 7: {
        state.status[10] = 0;
        state.status[11] = 0;
        fn_27_8D7C4(&state.selectors[5]);
        state.action[5] = 0;
        if (fn_27_8D810(&state.selectors[5], reinterpret_cast<soArticle*>(p + 0xac78)) == true)
            owner = reinterpret_cast<Weapon*>(p + 0xabf0);
        else owner = 0;
        if (owner == 0) {
            owner = reinterpret_cast<Weapon*>(state.selectors[5]);
            if (owner != 0) owner = reinterpret_cast<Weapon*>(reinterpret_cast<char*>(owner) - 0x88);
            if (owner == 0) {
                fn_27_8D7D0(&state.selectors[5], (short)-1);
                return reinterpret_cast<soArticle*>(lbl_27_bss_1CC);
            }
            owner->deactivateArticle();
        }
        if (fn_122_E520(owner, accesser) == 1) {
            fn_27_8D7D0(&state.selectors[5], (short)-1);
            return reinterpret_cast<soArticle*>(reinterpret_cast<char*>(owner) + 0x88);
        }
        fn_27_8D7D0(&state.selectors[5], (short)-1);
        return reinterpret_cast<soArticle*>(lbl_27_bss_1CC);
    }
    case 8: {
        state.status[8] = 0;
        state.status[9] = 0;
        fn_27_8D7C4(&state.selectors[4]);
        state.action[4] = 0;
        if (fn_27_8D810(&state.selectors[4], reinterpret_cast<soArticle*>(p + 0x8d14)) == true)
            owner = reinterpret_cast<Weapon*>(p + 0x8c8c);
        else owner = 0;
        if (owner == 0) {
            owner = reinterpret_cast<Weapon*>(state.selectors[4]);
            if (owner != 0) owner = reinterpret_cast<Weapon*>(reinterpret_cast<char*>(owner) - 0x88);
            if (owner == 0) {
                fn_27_8D7D0(&state.selectors[4], (short)-1);
                return reinterpret_cast<soArticle*>(lbl_27_bss_1CC);
            }
            owner->deactivateArticle();
        }
        if (fn_122_E5A8(owner, accesser) == 1) {
            fn_27_8D7D0(&state.selectors[4], (short)-1);
            return reinterpret_cast<soArticle*>(reinterpret_cast<char*>(owner) + 0x88);
        }
        fn_27_8D7D0(&state.selectors[4], (short)-1);
        return reinterpret_cast<soArticle*>(lbl_27_bss_1CC);
    }
    case 9: {
        state.status[6] = 0;
        state.status[7] = 0;
        fn_27_8D7C4(&state.selectors[3]);
        state.action[3] = 0;
        if (fn_27_8D810(&state.selectors[3], reinterpret_cast<soArticle*>(p + 0x6d44)) == true)
            owner = reinterpret_cast<Weapon*>(p + 0x6cbc);
        else owner = 0;
        if (owner == 0) {
            owner = reinterpret_cast<Weapon*>(state.selectors[3]);
            if (owner != 0) owner = reinterpret_cast<Weapon*>(reinterpret_cast<char*>(owner) - 0x88);
            if (owner == 0) {
                fn_27_8D7D0(&state.selectors[3], (short)-1);
                return reinterpret_cast<soArticle*>(lbl_27_bss_1CC);
            }
            owner->deactivateArticle();
        }
        if (fn_122_E660(owner, accesser) == 1) {
            fn_27_8D7D0(&state.selectors[3], (short)-1);
            return reinterpret_cast<soArticle*>(reinterpret_cast<char*>(owner) + 0x88);
        }
        fn_27_8D7D0(&state.selectors[3], (short)-1);
        return reinterpret_cast<soArticle*>(lbl_27_bss_1CC);
    }
    case 10: {
        state.status[4] = 0;
        state.status[5] = 0;
        fn_27_8D7C4(&state.selectors[2]);
        state.action[2] = 0;
        if (fn_27_8D810(&state.selectors[2], reinterpret_cast<soArticle*>(p + 0x4df4)) == true)
            owner = reinterpret_cast<Weapon*>(p + 0x4d6c);
        else owner = 0;
        if (owner == 0) {
            owner = reinterpret_cast<Weapon*>(state.selectors[2]);
            if (owner != 0) owner = reinterpret_cast<Weapon*>(reinterpret_cast<char*>(owner) - 0x88);
            if (owner == 0) {
                fn_27_8D7D0(&state.selectors[2], (short)-1);
                return reinterpret_cast<soArticle*>(lbl_27_bss_1CC);
            }
            owner->deactivateArticle();
        }
        if (fn_122_E718(owner, accesser) == 1) {
            fn_27_8D7D0(&state.selectors[2], (short)-1);
            return reinterpret_cast<soArticle*>(reinterpret_cast<char*>(owner) + 0x88);
        }
        fn_27_8D7D0(&state.selectors[2], (short)-1);
        return reinterpret_cast<soArticle*>(lbl_27_bss_1CC);
    }
    case 11: {
        state.status[2] = 0;
        state.status[3] = 0;
        fn_27_8D7C4(&state.selectors[1]);
        state.action[1] = 0;
        if (fn_27_8D810(&state.selectors[1], reinterpret_cast<soArticle*>(p + 0x2e44)) == true)
            owner = reinterpret_cast<Weapon*>(p + 0x2dbc);
        else owner = 0;
        if (owner == 0) {
            owner = reinterpret_cast<Weapon*>(state.selectors[1]);
            if (owner != 0) owner = reinterpret_cast<Weapon*>(reinterpret_cast<char*>(owner) - 0x88);
            if (owner == 0) {
                fn_27_8D7D0(&state.selectors[1], (short)-1);
                return reinterpret_cast<soArticle*>(lbl_27_bss_1CC);
            }
            owner->deactivateArticle();
        }
        if (fn_122_E7A0(owner, accesser) == 1) {
            fn_27_8D7D0(&state.selectors[1], (short)-1);
            return reinterpret_cast<soArticle*>(reinterpret_cast<char*>(owner) + 0x88);
        }
        fn_27_8D7D0(&state.selectors[1], (short)-1);
        return reinterpret_cast<soArticle*>(lbl_27_bss_1CC);
    }
    case 12: {
        state.status[0] = 0;
        state.status[1] = 0;
        fn_27_8D7C4(&state.selectors[0]);
        state.action[0] = 0;
        if (fn_27_8D810(&state.selectors[0], reinterpret_cast<soArticle*>(p + 0x1770)) == true)
            owner = reinterpret_cast<Weapon*>(p + 0x16e8);
        else if (fn_27_8D810(&state.selectors[0], reinterpret_cast<soArticle*>(p + 0xa4)) == true)
            owner = reinterpret_cast<Weapon*>(p + 0x1c);
        else owner = 0;
        if (owner == 0) {
            owner = reinterpret_cast<Weapon*>(state.selectors[0]);
            if (owner != 0) owner = reinterpret_cast<Weapon*>(reinterpret_cast<char*>(owner) - 0x88);
            if (owner == 0) {
                fn_27_8D7D0(&state.selectors[0], (short)-1);
                return reinterpret_cast<soArticle*>(lbl_27_bss_1CC);
            }
            owner->deactivateArticle();
        }
        if (fn_122_E9BC(owner, accesser) == 1) {
            fn_27_8D7D0(&state.selectors[0], (short)-1);
            return reinterpret_cast<soArticle*>(reinterpret_cast<char*>(owner) + 0x88);
        }
        fn_27_8D7D0(&state.selectors[0], (short)-1);
        return reinterpret_cast<soArticle*>(lbl_27_bss_1CC);
    }
    case 13: {
        state.pad[6]=0; state.pad[7]=0;
        void* module=*reinterpret_cast<void**>(reinterpret_cast<char*>(accesser)+0xD8);
        Class_E104* object=*reinterpret_cast<Class_E104**>(reinterpret_cast<char*>(module)+0x84);
        if(object->fn_122_18EAC(0xD)>=2) return reinterpret_cast<soArticle*>(lbl_27_bss_1CC);
        int stage=reinterpret_cast<StageRoot*>(accesser)->stage->getId();
        if(fn_27_8D6EC(0x59,0xD,stage)==0) return reinterpret_cast<soArticle*>(lbl_27_bss_1CC);
        return reinterpret_cast<soArticle*>(fn_27_8D78C());
    }
    case 14: {
        state.pad[4]=0; state.pad[5]=0;
        void* module=*reinterpret_cast<void**>(reinterpret_cast<char*>(accesser)+0xD8);
        Class_E104* object=*reinterpret_cast<Class_E104**>(reinterpret_cast<char*>(module)+0x84);
        if(object->fn_122_18EAC(0xE)>=1) return reinterpret_cast<soArticle*>(lbl_27_bss_1CC);
        int stage=reinterpret_cast<StageRoot*>(accesser)->stage->getId();
        if(fn_27_8D6EC(0x53,0xE,stage)==0) return reinterpret_cast<soArticle*>(lbl_27_bss_1CC);
        return reinterpret_cast<soArticle*>(fn_27_8D78C());
    }
    case 15: { state.pad[2]=0; state.pad[3]=0; return reinterpret_cast<soArticle*>(lbl_27_bss_1CC); }
    case 16: { state.pad[0]=0; state.pad[1]=0; return reinterpret_cast<soArticle*>(lbl_27_bss_1CC); }
    default: return reinterpret_cast<soArticle*>(lbl_27_bss_1CC);
    }
}
