extern "C" {
void* fn_91_7378(void*, short);
void* fn_91_12A28(void*, short);
void* fn_91_12A98(void*, short);
void* fn_91_12B08(void*, short);
void* fn_91_12B78(void*, short);
void* fn_91_12BE8(void*, short);
void* fn_91_12C58(void*, short);
void* fn_91_12CC4(void*, short);
void* fn_91_12D30(void*, short);
void* fn_91_12D9C(void*, short);
void* fn_91_12E08(void*, short);

#pragma dont_inline on
void* fn_91_129B8(void* object, short deleting) {
    if (object != 0) {
        fn_91_7378(static_cast<unsigned char*>(object) + 0x12f78, static_cast<short>(-1));
        fn_91_12A28(static_cast<unsigned char*>(object) + 4, static_cast<short>(-1));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
void* fn_91_12A28(void* object, short deleting) {
    if (object != 0) {
        fn_91_7378(static_cast<unsigned char*>(object) + 0x11120, static_cast<short>(-1));
        fn_91_12A98(static_cast<unsigned char*>(object) + 4, static_cast<short>(-1));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
void* fn_91_12A98(void* object, short deleting) {
    if (object != 0) {
        fn_91_7378(static_cast<unsigned char*>(object) + 0xf2c8, static_cast<short>(-1));
        fn_91_12B08(static_cast<unsigned char*>(object) + 4, static_cast<short>(-1));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
void* fn_91_12B08(void* object, short deleting) {
    if (object != 0) {
        fn_91_7378(static_cast<unsigned char*>(object) + 0xd470, static_cast<short>(-1));
        fn_91_12B78(static_cast<unsigned char*>(object) + 4, static_cast<short>(-1));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
void* fn_91_12B78(void* object, short deleting) {
    if (object != 0) {
        fn_91_7378(static_cast<unsigned char*>(object) + 0xb618, static_cast<short>(-1));
        fn_91_12BE8(static_cast<unsigned char*>(object) + 4, static_cast<short>(-1));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
void* fn_91_12BE8(void* object, short deleting) {
    if (object != 0) {
        fn_91_7378(static_cast<unsigned char*>(object) + 0x97c0, static_cast<short>(-1));
        fn_91_12C58(static_cast<unsigned char*>(object) + 4, static_cast<short>(-1));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
void* fn_91_12C58(void* object, short deleting) {
    if (object != 0) {
        fn_91_7378(static_cast<unsigned char*>(object) + 0x7968, static_cast<short>(-1));
        fn_91_12CC4(static_cast<unsigned char*>(object) + 4, static_cast<short>(-1));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
void* fn_91_12CC4(void* object, short deleting) {
    if (object != 0) {
        fn_91_7378(static_cast<unsigned char*>(object) + 0x5b10, static_cast<short>(-1));
        fn_91_12D30(static_cast<unsigned char*>(object) + 4, static_cast<short>(-1));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
void* fn_91_12D30(void* object, short deleting) {
    if (object != 0) {
        fn_91_7378(static_cast<unsigned char*>(object) + 0x3cb8, static_cast<short>(-1));
        fn_91_12D9C(static_cast<unsigned char*>(object) + 4, static_cast<short>(-1));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
void* fn_91_12D9C(void* object, short deleting) {
    if (object != 0) {
        fn_91_7378(static_cast<unsigned char*>(object) + 0x1e60, static_cast<short>(-1));
        fn_91_12E08(static_cast<unsigned char*>(object) + 4, static_cast<short>(-1));
        if (deleting > 0) operator delete(object);
    }
    return object;
}
#pragma dont_inline reset
}
