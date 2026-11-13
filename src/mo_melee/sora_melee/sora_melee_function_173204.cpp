#include <types.h>
#include <ft/ft_manager.h>
#include <so/so_value_accesser.h>
#pragma force_active on
class Object64 {
public:
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
 virtual int slot4(u32);
 virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual void slot8();
 virtual void slot9(); virtual void slot10(); virtual void slot11(); virtual void slot12();
 virtual void slot13(); virtual void slot14(); virtual void slot15(); virtual void slot16();
 virtual int slot17(u32);
};
struct Prefix8 { char pad[8]; };
class Object38 : public Prefix8 {
public:
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
 virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
 virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11();
 virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15();
 virtual void slot16(); virtual void slot17(); virtual void slot18(); virtual void slot19();
 virtual void slot20(); virtual void slot21(); virtual void slot22(); virtual void slot23();
 virtual void slot24(); virtual void slot25(); virtual void slot26(); virtual void slot27();
 virtual void slot28(); virtual void slot29(); virtual void slot30(); virtual void slot31();
 virtual void slot32(); virtual void slot33(); virtual void virtualAt90(int*);
};
struct Inner { char pad0[0x38]; Object38* at38; char pad3c[0x28]; Object64* at64; };
struct Context { char pad0[0xd8]; Inner* inner; };
extern "C" int fn_27_112D44(void*);
extern "C" int fn_27_10BEEC(ftManager*, int);
extern "C" void fn_27_10BFD8(ftManager*, int, int, int);
extern "C" void fn_27_10C06C(ftManager*, int, int);
extern "C" u32 isValidEntryId__9ftManagerFi(ftManager*, int);
extern "C" int getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(soValueAccesser*, u32, u32);
extern "C" int fn_27_173204(void* unused, Context* arg) {
    int entryId;
    void* owner;
    int params[9];
    int frames;
    if (*(u8*)((char*)g_ftManager + 0x6a) == 2) {
        entryId = arg->inner->at64->slot4(0x10000000);
        owner = g_ftManager->getOwner(entryId);
        if (arg->inner->at64->slot17(0x1200002e) == 0) {
            if (fn_27_112D44(owner) == 0) {
                frames = fn_27_10BEEC(g_ftManager, entryId);
                frames = frames / 2;
                {
                    int limit = getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl((soValueAccesser*)arg, 0x5a4b, 0);
                    if (frames > limit) frames = limit;
                }
                fn_27_10BFD8(g_ftManager, entryId, frames, 1);
                arg->inner->at38->virtualAt90(params);
                if (params[6] == 0 && isValidEntryId__9ftManagerFi(g_ftManager, params[8]) == 1U && entryId != params[8]) {
                    fn_27_10C06C(g_ftManager, params[8], frames);
                }
                return frames;
            }
        }
    }
    return 0;
}