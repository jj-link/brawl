#include <so/so_array.h>
#pragma force_active on

class Class_28BC { public: virtual void fn_95_727C(); virtual void fn_95_B678(); virtual void fn_95_B624(); virtual void fn_95_B614(); };
class Class_2908 { public: virtual void fn_95_8008(); virtual void fn_95_1F24(); virtual void fn_95_B6E4(); virtual void fn_95_B6DC(); };
class Class_2988 { public: virtual void fn_95_8008(); virtual void fn_95_1B44(); virtual void fn_95_B71C(); virtual void fn_95_B714(); };
class Class_30D0 { public: virtual void fn_95_B9B8(); virtual void fn_95_BA74(); virtual void fn_95_BBF4(); virtual void fn_95_B9C0(); };
class Class_7E00 { public: virtual void fn_95_F8A0(); virtual void fn_95_F36C(); virtual void fn_95_F798(); virtual void fn_95_F364(); };
class Class_7E78 { public: virtual void fn_95_FAC4(); virtual void fn_95_F36C(); virtual void fn_95_FA74(); virtual void fn_95_F938(); };
class Class_7EF0 { public: virtual void fn_95_FD40(); virtual void fn_95_FB5C(); virtual void fn_95_FCC0(); virtual void fn_95_F364(); };
class Class_811C { public: virtual void fn_95_10F84(); virtual void fn_95_109E0(); virtual void fn_95_10F64(); virtual void fn_95_10DA4(); };
class Class_81E8 { public: virtual void fn_95_11C0C(); virtual void fn_95_1101C(); virtual void fn_95_11B68(); virtual void fn_95_11198(); };
class Class_8268 { public: virtual void fn_95_12154(); virtual void fn_95_11CA4(); virtual void fn_95_12134(); virtual void fn_95_11F78(); };
class Class_82E0 { public: virtual void fn_95_12CE8(); virtual void fn_95_121EC(); virtual void fn_95_12CC8(); virtual void fn_95_12364(); };
class Class_8360 { public: virtual void fn_95_1353C(); virtual void fn_95_12D80(); virtual void fn_95_1351C(); virtual void fn_95_12F44(); };
class Class_83E0 { public: virtual void fn_95_13824(); virtual void fn_95_135D4(); virtual void fn_95_F368(); virtual void fn_95_F364(); };
class Class_8458 { public: virtual void fn_95_13944(); virtual void fn_95_138BC(); virtual void fn_95_F368(); virtual void fn_95_F364(); };
class Class_84D0 { public: virtual void fn_95_13AE0(); virtual void fn_95_F36C(); virtual void fn_95_F368(); virtual void fn_95_139DC(); };
class Class_8550 { public: virtual void fn_95_142E0(); virtual void fn_95_F36C(); virtual void fn_95_14228(); virtual void fn_95_13B78(); };
class Class_85C8 { public: virtual void fn_95_14420(); virtual void fn_95_14378(); virtual void fn_95_14228(); virtual void fn_95_13B78(); };
class Class_8BE4 { public: virtual void fn_95_8008(); virtual void fn_95_16CDC(); virtual void fn_95_17478(); virtual void fn_95_17474(); };
class Class_8D68 { public: virtual void fn_95_8008(); virtual void fn_95_16C24(); virtual void fn_95_175A4(); virtual void fn_95_1759C(); };
class Class_8DBC { public: virtual void fn_95_8008(); virtual void fn_95_16C80(); virtual void fn_95_17664(); virtual void fn_95_1765C(); };

struct YoshiArrayTriple {
    u32 c;
    u32 a;
    u32 b;
};

struct YoshiArrayAggregate {
    void* vtable;
    YoshiArrayTriple cache;
    soArrayFixed<u32>* a;
    soArrayFixed<u32>* b;
    soArrayFixed<u32>* c;
};

extern "C" YoshiArrayTriple fn_95_BAC8(YoshiArrayAggregate* arrays, s32 index) {
    if (index < 0) {
        YoshiArrayTriple result = { 0, 0, 0 };
        return result;
    }
    u32 c = 0;
    if (index < arrays->c->size()) {
        c = arrays->c->at(index);
    }
    u32 a = 0;
    if (index < arrays->a->size()) {
        a = arrays->a->at(index);
    }
    u32 b = 0;
    if (index < arrays->b->size()) {
        b = arrays->b->at(index);
    }
    YoshiArrayTriple result = { c, a, b };
    return result;
}
