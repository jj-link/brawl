#pragma force_active on

extern unsigned short SOHtoNs(unsigned short);
extern int fn_803A73D8(int, void *);
extern int fn_80392088(void *, void *, int *, int);

int fn_80391FC8(void *network, void *lock, int *context, int socket, int address, int port) {
    unsigned char sp8[8];
    int result;

    sp8[0] = 8;
    sp8[1] = 2;
    *(unsigned short *)(sp8 + 2) = SOHtoNs((unsigned short)port);
    *(int *)(sp8 + 4) = address;

    result = fn_803A73D8(socket, sp8);
    if (result < 0) {
        result = -0x3E9;
        if (context[0] != 0)
            result = -0x3EA;
        return result;
    }

    if (context[2] != 0 && context[3] == 0) {
        return fn_80392088(network, lock, context, socket);
    }

    return 0;
}