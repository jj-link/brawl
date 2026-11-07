#pragma force_active on
#define soArrayVectorAbstract HeaderArrayVectorAbstract
#include <ac/ac_cmd_interpreter.h>
#undef soArrayVectorAbstract

template<class T> class soArrayVectorAbstract {
public:
 virtual void slot0(); virtual void slot1(); virtual void slot2();
 virtual int size();
 virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11(); virtual void slot12();
 virtual int v3C(); virtual int v40();
 virtual void slot15(); virtual void slot16(); virtual void slot17(); virtual void slot18(); virtual void slot19(); virtual void slot20(); virtual void slot21(); virtual void slot22(); virtual void slot23(); virtual void slot24(); virtual void slot25();
 virtual T* get(int); virtual int v74(); virtual int v78(); virtual void v7C(int);
 int calc;
 void insert(long, const T&);
};
extern "C" int insert__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacelbllll(void*, long, int, int, int, int, int);
template<> void soArrayVectorAbstract<acCmdInterpreterStackData>::insert(long index, const acCmdInterpreterStackData& src) {
 int pos = insert__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacelbllll(&calc, index, v40(), size(), v3C(), v74(), v78());
 *get(pos) = src;
 v7C(size() + 1);
}
