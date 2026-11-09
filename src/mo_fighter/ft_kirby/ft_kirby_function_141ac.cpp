#pragma force_active on
#include <ft/ft_common_data_accesser.h>
extern "C" {
extern const char lbl_96_data_608[], lbl_96_data_68D8[];
extern double lbl_96_rodata_40;
extern float lbl_96_rodata_38, lbl_96_rodata_3C;
void* __dynamic_cast(void*, long, const void*, const void*, short);
void* fn_96_AF98(void*);
}
class First {
public:
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
 virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
 virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
 virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
 virtual void call(void*, int);
};
class Work {
public:
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
 virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
 virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
 virtual void v12();
 virtual void setFloat(float, int);
 virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
 virtual void onFlag(int);
};
struct FighterData { char pad[0x64]; Work* work; char pad2[0x1c]; First* first; };
struct Fighter { char pad[0xD8]; FighterData* data; };
struct Values { char pad[8]; int value; };
struct Info { char pad[4]; Values* values; };
extern "C" void fn_96_141AC(void*, Fighter* fighter) {
 ftData* data = g_ftCommonDataAccesser.getData((ftKind)5);
 First* first = fighter->data->first;
 first->call(*(void**)((char*)data + 0x120), 0);
 void* casted = __dynamic_cast(*(void**)((char*)fighter + 8), 0x3c, lbl_96_data_608, lbl_96_data_68D8, 1);
 Info* info = (Info*)fn_96_AF98(casted);
 FighterData* fd = fighter->data;
 Work* work = fd->work;
 float diff = (float)info->values->value;
 if (diff > lbl_96_rodata_38) {
  work->onFlag(0x12000003);
  work->setFloat(diff, 0x11000000);
  work->setFloat(lbl_96_rodata_3C, 0x11000001);
 }
}