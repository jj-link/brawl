#include <so/so_module_accesser.h>
#pragma force_active on
void operator delete(void*);
extern "C" void* fn_123_12980(void*, short);
extern "C" void* fn_123_3AE4(void*, short);
extern "C" void* fn_123_3B40(void*, short);
extern "C" void* fn_123_129DC(void*, short);
extern "C" void* fn_123_12A60(void*, short);
extern "C" void* fn_123_3B9C(void*, short);
extern "C" void* fn_123_12AEC(void*, short);
extern "C" void* fn_123_3D38(void*, short);
extern "C" void* fn_123_3FA0(void*, short);
extern "C" void* fn_123_40D4(void*, short);
extern "C" void* fn_123_4130(void*, short);
extern "C" void* fn_123_418C(void*, short);
extern "C" void* fn_123_41F8(void*, short);
extern "C" void* fn_123_4258(void*, short);
extern "C" void* fn_123_42B8(void*, short);
extern "C" void* fn_123_4314(void*, short);
extern "C" void* fn_123_4398(void*, short);
extern "C" void* fn_123_4464(void*, short);
extern "C" void* fn_123_44C0(void*, short);
extern "C" void* fn_123_452C(void*, short);
extern "C" void* fn_123_12CD4(void*, short);
extern "C" void* fn_123_4628(void*, short);
extern "C" void* fn_123_4694(void*, short);
extern "C" void* fn_123_474C(void*, short);
extern "C" void* fn_123_478C(void*, short);
extern "C" void* fn_123_12E44(void*, short);
extern "C" void* fn_123_127E8(void* object, short deleting) {
 if (object != 0) {
 unsigned char* storage = static_cast<unsigned char*>(object);
 fn_123_12980(storage + 0x1A44, -1);
 fn_123_3AE4(storage + 0x1A04, -1);
 fn_123_3B40(storage + 0x19EC, -1);
 fn_123_129DC(storage + 0x18D8, -1);
 fn_123_12A60(storage + 0x1744, -1);
 fn_123_3B9C(storage + 0x16E4, -1);
 fn_123_12AEC(storage + 0x1630, -1);
 fn_123_3D38(storage + 0x1464, -1);
 fn_123_3FA0(storage + 0x13C0, -1);
 fn_123_40D4(storage + 0x138C, -1);
 fn_123_4130(storage + 0x1374, -1);
 fn_123_418C(storage + 0x1210, -1);
 fn_123_41F8(storage + 0x11A8, -1);
 fn_123_4258(storage + 0x119C, -1);
 fn_123_42B8(storage + 0x1174, -1);
 fn_123_4314(storage + 0xFA4, -1);
 fn_123_4398(storage + 0xF40, -1);
 fn_123_4464(storage + 0xF04, -1);
 fn_123_44C0(storage + 0xE5C, -1);
 fn_123_452C(storage + 0xDA8, -1);
 fn_123_12CD4(storage + 0xB9C, -1);
 fn_123_4628(storage + 0x9BC, -1);
 fn_123_4694(storage + 0x98C, -1);
 fn_123_474C(storage + 0x97C, -1);
 fn_123_478C(storage + 0x964, -1);
 reinterpret_cast<soModuleAccesser*>(storage + 0x884)->soModuleAccesser::~soModuleAccesser();
 fn_123_12E44(object, -1);
 if (deleting > 0) operator delete(object);
 }
 return object;
}