#include <types.h>
#include <so/so_value_accesser.h>
#include <so/so_array.h>
#pragma force_active on

struct ArgData { int type; int value; };

class Object_vptr_0 {
public:
    virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
    virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
    virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11();
    virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15();
    virtual void slot16(); virtual void slot17(); virtual void slot18(); virtual void slot19();
    virtual void slot20(); virtual int slot21();
};
extern "C" int fn_27_7B610(void*, int, soArrayFixed<ArgData>*, soModuleAccesser*);
extern "C" int fn_27_BEB3C(void*, int);

extern "C" int fn_27_153E94(void* self, int id, soArrayFixed<ArgData>* args, soModuleAccesser* acc) {
    switch (id) {
    case 1000:
    case 1001: {
        union { u8 workspace[24]; s32 words[6]; };
        const ArgData* data = &static_cast<const soArrayFixed<ArgData>*>(args)->at(0);
        *(const ArgData**)workspace = data;
        workspace[4] = 0;
        u32 copiedFlag = *(u32*)(workspace + 4);
        *(const ArgData**)(workspace + 8) = data;
        *(u32*)(workspace + 12) = copiedFlag;
        *(const ArgData**)(workspace + 16) = data;
        workspace[20] = workspace[12];
        if ((workspace[12] == 1 ? -1 : (*(const ArgData**)(workspace + 16))->type) != 0) return 0;
        int value;
        if (workspace[20] == 1) value = 0;
        else value = (*(const ArgData**)(workspace + 16))->value;
        if (value != ((Object_vptr_0*)acc->m_enumerationStart->m_motionModule)->slot21()) return 0;
        void* table;
        if (id == 1000) table = soValueAccesser::getConstantIndefinite(acc, 0xA801, 0);
        else if (id == 1001) table = soValueAccesser::getConstantIndefinite(acc, 0xA809, 0);
        else return 0;
        if (table) {
            int result = fn_27_BEB3C(table, value);
            return result == value ? -1 : result - value;
        }
    }
    }
    return fn_27_7B610(self, id, args, acc);
}