#include <so/so_array.h>
#pragma force_active on
struct Fn47 : soArrayVectorCalcInterface {
 virtual void substitution(s32,s32); virtual void onFull(); virtual void offFull(); virtual void setTopIndex(s32); virtual void setLastIndex(s32);
 virtual void extra0(); virtual void extra1(); virtual void extra2(); virtual void extra3(); virtual void extra4(); virtual void extra5(); virtual void extra6(); virtual void extra7(); virtual void extra8(); virtual void extra9(); virtual void extra10(); virtual void extra11(); virtual void extra12(); virtual void extra13(); virtual void extra14(); virtual void extra15(); virtual void extra16(); virtual void extra17(); virtual void extra18(); virtual void extra19(); virtual void extra20(); virtual void extra21(); virtual void extra22(); virtual void extra23(s32);
};
extern "C" void fn_47_8D40(Fn47* self) {
 soArrayVectorCalculator::clear(*reinterpret_cast<soArrayVectorCalcInterface*>(reinterpret_cast<char*>(self)+4));
 self->extra23(0);
}