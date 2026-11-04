#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct {
    int length;
    u8 *data;
    u16 id;
    u8 type;
} Attribute;

u8 *fn_8025B1F0(u8 *out, Attribute *attr)
{
    u8 type;
    int i;
    u8 *p;
    u8 *q;
    out[0] = 9;
    out[1] = attr->id >> 8;
    out[2] = attr->id;
    type = attr->type;
    switch (type) {
    case 4:
    case 6:
    case 7:
    case 8:
        out[3] = (type << 3) | 5;
        out[4] = attr->length;
        p = out + 5;
        for (i = 0; i < attr->length; i++)
            *p++ = attr->data[i];
        return p;
    default:
        switch (attr->length) {
        case 1:
            out[3] = type << 3;
            q = out + 4;
            break;
        case 2:
            out[3] = (type << 3) | 1;
            q = out + 4;
            break;
        case 4:
            out[3] = (type << 3) | 2;
            q = out + 4;
            break;
        case 8:
            out[3] = (type << 3) | 3;
            q = out + 4;
            break;
        case 16:
            out[3] = (type << 3) | 4;
            q = out + 4;
            break;
        default:
            out[3] = (type << 3) | 5;
            out[4] = attr->length;
            q = out + 5;
            break;
        }
        for (i = 0; i < attr->length; i++)
            *q++ = attr->data[i];
        return q;
    }
}
