#pragma force_active on
#include <it/it_manager.h>
typedef unsigned char u8;
class emCreate;
extern "C" void fn_41_1F0(void*, unsigned long, void*, void*, void*, void*, void*, void*, void*, void*, void*, void*);
extern "C" void fn_27_CFF08(void*, int, int);
extern "C" void fn_27_CA3B8(void*, int, int);
extern "C" void fn_27_CB410(void*, int, int);
extern "C" void __construct_array(void*, void*, void*, unsigned long, unsigned long);
extern "C" void* __ct__18emTargetSearchUnitFv(void*);
extern "C" void* __dt__18emTargetSearchUnitFv(void*, short);
extern "C" void* fn_41_2A470(void*);
extern "C" void* fn_41_2A480(void*, short);
extern "C" char lbl_27_bss_1F0[];
extern "C" char lbl_27_bss_A5C[];
extern "C" char lbl_27_bss_69C[];
extern "C" char lbl_41_data_13100[];
class emPatapata {
public:
    emPatapata(unsigned long, emCreate*);
};
emPatapata::emPatapata(unsigned long arg0, emCreate* arg1) {
    u8* s = (u8*)this;
    fn_41_1F0(this, arg0, arg1, s + 0x5310, s + 0x597c, s + 0x5b14, s + 0x5c74, s + 0x5cbc,
              lbl_27_bss_1F0, lbl_27_bss_A5C, s + 0x5dc4, lbl_27_bss_69C);
    u8* base = (u8*)lbl_41_data_13100;
    *(u8**)(s + 0x3c) = base;
    *(u8**)(s + 0x40) = base + 0x64;
    *(u8**)(s + 0x48) = base + 0x70;
    *(u8**)(s + 0x54) = base + 0x84;
    *(u8**)(s + 0x64) = base + 0xdc;
    *(u8**)(s + 0x70) = base + 0xec;
    *(u8**)(s + 0x7c) = base + 0x100;
    *(u8**)(s + 0x88) = base + 0x114;
    *(u8**)(s + 0x94) = base + 0x124;
    *(u8**)(s + 0xa0) = base + 0x138;
    fn_27_CFF08(s + 0x5310, 0x22, 0);
    fn_27_CA3B8(s + 0x597c, 0xb, 0);
    __construct_array(s + 0x5c74, (void*)__ct__18emTargetSearchUnitFv, (void*)__dt__18emTargetSearchUnitFv, 0x18, 3);
    __construct_array(s + 0x5cbc, (void*)fn_41_2A470, (void*)fn_41_2A480, 8, 0x21);
    fn_27_CB410(s + 0x5dc4, 1, 0);
    if (!itManager::getInstance()->isCompItemKindArchive((itKind)0x52, 0, true))
        itManager::getInstance()->preloadItemKindArchive((itKind)0x52, 0, (itArchive::Type)0, true);
    if (!itManager::getInstance()->isCompItemKindArchive((itKind)0x51, 0, true))
        itManager::getInstance()->preloadItemKindArchive((itKind)0x51, 0, (itArchive::Type)0, true);
}