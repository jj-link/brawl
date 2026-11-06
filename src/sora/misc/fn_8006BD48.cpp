#include <types.h>
#pragma force_active on
extern "C" char* fn_8006BD48(char* out, const char* in) {
    char* result = out;
    do {
        u8 c = *in++;
        if (c == 0xe2) {
            u8 a = in[0];
            u8 b = in[1];
            in += 2;
            switch ((int)(u16)(b + (a << 8))) {
            case 0x8098: c = 0x27; break;
            default: in -= 2; break;
            }
        } else if (c == 0xef) {
            u16 value = (u8)in[1] + ((u8)in[0] << 8);
            in += 2;
            switch ((int)value) {
            case 0xbc90: c = 0x30; break;
            case 0xbc91: c = 0x31; break;
            case 0xbc92: c = 0x32; break;
            case 0xbc93: c = 0x33; break;
            case 0xbc94: c = 0x34; break;
            case 0xbc95: c = 0x35; break;
            case 0xbc96: c = 0x36; break;
            case 0xbc97: c = 0x37; break;
            case 0xbc98: c = 0x38; break;
            case 0xbc99: c = 0x39; break;
            case 0xbca1: c = 0x41; break;
            case 0xbca2: c = 0x42; break;
            case 0xbca3: c = 0x43; break;
            case 0xbca4: c = 0x44; break;
            case 0xbca5: c = 0x45; break;
            case 0xbca6: c = 0x46; break;
            case 0xbca7: c = 0x47; break;
            case 0xbca8: c = 0x48; break;
            case 0xbca9: c = 0x49; break;
            case 0xbcaa: c = 0x4a; break;
            case 0xbcab: c = 0x4b; break;
            case 0xbcac: c = 0x4c; break;
            case 0xbcad: c = 0x4d; break;
            case 0xbcae: c = 0x4e; break;
            case 0xbcaf: c = 0x4f; break;
            case 0xbcb0: c = 0x50; break;
            case 0xbcb1: c = 0x51; break;
            case 0xbcb2: c = 0x52; break;
            case 0xbcb3: c = 0x53; break;
            case 0xbcb4: c = 0x54; break;
            case 0xbcb5: c = 0x55; break;
            case 0xbcb6: c = 0x56; break;
            case 0xbcb7: c = 0x57; break;
            case 0xbcb8: c = 0x58; break;
            case 0xbcb9: c = 0x59; break;
            case 0xbcba: c = 0x5a; break;
            case 0xbd81: c = 0x61; break;
            case 0xbd82: c = 0x62; break;
            case 0xbd83: c = 0x63; break;
            case 0xbd84: c = 0x64; break;
            case 0xbd85: c = 0x65; break;
            case 0xbd86: c = 0x66; break;
            case 0xbd87: c = 0x67; break;
            case 0xbd88: c = 0x68; break;
            case 0xbd89: c = 0x69; break;
            case 0xbd8a: c = 0x6a; break;
            case 0xbd8b: c = 0x6b; break;
            case 0xbd8c: c = 0x6c; break;
            case 0xbd8d: c = 0x6d; break;
            case 0xbd8e: c = 0x6e; break;
            case 0xbd8f: c = 0x6f; break;
            case 0xbd90: c = 0x70; break;
            case 0xbd91: c = 0x71; break;
            case 0xbd92: c = 0x72; break;
            case 0xbd93: c = 0x73; break;
            case 0xbd94: c = 0x74; break;
            case 0xbd95: c = 0x75; break;
            case 0xbd96: c = 0x76; break;
            case 0xbd97: c = 0x77; break;
            case 0xbd98: c = 0x78; break;
            case 0xbd99: c = 0x79; break;
            case 0xbd9a: c = 0x7a; break;
            default: in -= 2; break;
            }
        }
        *out++ = c;
    } while ((s8)*in != 0);
    *out = 0;
    return result;
}
