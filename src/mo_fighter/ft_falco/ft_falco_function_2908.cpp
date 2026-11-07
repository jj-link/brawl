#pragma force_active on
void operator delete(void*);
extern "C" {
void* fn_108_2BA8(void*, short);
void* fn_108_2C04(void*, short);
void* fn_108_2C60(void*, short);
void* fn_108_2CBC(void*, short);
void* fn_108_2D18(void*, short);
void* fn_108_2D74(void*, short);
void* fn_108_2E50(void*, short);
void* fn_108_2EAC(void*, short);
void* fn_108_2F08(void*, short);
void* fn_108_2F7C(void*, short);
void* fn_108_3014(void*, short);
void* fn_108_3070(void*, short);
void* fn_108_31C0(void*, short);
void* fn_108_63A8(void*, short);
void* fn_108_6408(void*, short);
void* fn_108_6480(void*, short);
void* fn_108_6FF0(void*, short);
void* fn_108_3FCC(void*, short);
void* fn_108_70CC(void*, short);
void* fn_108_7140(void*, short);
void* fn_108_721C(void*, short);
void* fn_108_7278(void*, short);
void* fn_108_72E4(void*, short);
void* fn_108_7390(void*, short);
void* fn_108_7404(void*, short);
void* fn_108_7460(void*, short);
void* fn_108_74BC(void*, short);
void* fn_108_7518(void*, short);
void* fn_108_7574(void*, short);
void* fn_108_75E8(void*, short);
void* fn_108_7654(void*, short);
void* fn_108_76E4(void*, short);
void* fn_108_7774(void*, short);
void* fn_108_77F8(void*, short);
void* fn_108_787C(void*, short);
void* fn_108_42D8(void*, short);
void* fn_108_4F38(void*, short);
void* fn_108_4334(void*, short);
void* fn_108_79B0(void*, short);
void* fn_108_7BE4(void*, short);
void* fn_108_7CB8(void*, short);
void* fn_108_7D30(void*, short);
void* fn_108_45F0(void*, short);
void* __dt__16soModuleAccesserFv(void*, short);
void* fn_108_7D8C(void*, short);
}

extern "C" void* fn_108_2908(void* object, short deleting) {
    if (object != 0) {
        char* storage = static_cast<char*>(object);
        short destroy = -1;
        fn_108_2BA8(storage + 0x1B1F0, destroy);
        fn_108_2C04(storage + 0x1B1B4, destroy);
        fn_108_2C60(storage + 0x1B14C, destroy);
        fn_108_2CBC(storage + 0x1B100, destroy);
        fn_108_2D18(storage + 0x1AFAC, destroy);
        fn_108_2D74(storage + 0x1AE9C, destroy);
        fn_108_2E50(storage + 0x1AE54, destroy);
        fn_108_2EAC(storage + 0x1ADD4, destroy);
        fn_108_2F08(storage + 0x1AD10, destroy);
        fn_108_2F7C(storage + 0x1A99C, destroy);
        fn_108_3014(storage + 0x1A96C, destroy);
        fn_108_3070(storage + 0x1A7C8, destroy);
        fn_108_31C0(storage + 0x5788, destroy);
        fn_108_63A8(storage + 0x55A4, destroy);
        fn_108_6408(storage + 0x529C, destroy);
        fn_108_6480(storage + 0x4428, destroy);
        fn_108_6FF0(storage + 0x4334, destroy);
        fn_108_3FCC(storage + 0x4300, destroy);
        fn_108_70CC(storage + 0x428C, destroy);
        fn_108_7140(storage + 0x3B68, destroy);
        fn_108_721C(storage + 0x3B38, destroy);
        fn_108_7278(storage + 0x396C, destroy);
        fn_108_72E4(storage + 0x38FC, destroy);
        fn_108_7390(storage + 0x3864, destroy);
        fn_108_7404(storage + 0x382C, destroy);
        fn_108_7460(storage + 0x3808, destroy);
        fn_108_74BC(storage + 0x37D4, destroy);
        fn_108_7518(storage + 0x3770, destroy);
        fn_108_7574(storage + 0x35C0, destroy);
        fn_108_75E8(storage + 0x335C, destroy);
        fn_108_7654(storage + 0x29A0, destroy);
        fn_108_76E4(storage + 0x2788, destroy);
        fn_108_7774(storage + 0x2104, destroy);
        fn_108_77F8(storage + 0x1A48, destroy);
        fn_108_787C(storage + 0x19D4, destroy);
        fn_108_42D8(storage + 0x1998, destroy);
        fn_108_4F38(storage + 0x18F0, destroy);
        fn_108_4334(storage + 0x183C, destroy);
        fn_108_79B0(storage + 0x14A8, destroy);
        fn_108_7BE4(storage + 0x1180, destroy);
        fn_108_7CB8(storage + 0x115C, destroy);
        fn_108_7D30(storage + 0x0AC8, destroy);
        fn_108_45F0(storage + 0x0AB0, destroy);
        __dt__16soModuleAccesserFv(storage + 0x09D0, destroy);
        fn_108_7D8C(object, destroy);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
