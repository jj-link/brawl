#include <types.h>
#pragma force_active on
void fn_8039D4E4(s8 *p) {
    int i;
    for (i = 0; i < 256; i++) p[i] = -1;
    for (i = 'A'; i <= 'Z'; i++) p[i] = i - 'A';
    for (i = 'a'; i <= 'z'; i++) p[i] = i - 'a' + 26;
    for (i = '0'; i <= '9'; i++) p[i] = i - '0' + 52;
    p['+'] = 62;
    p['/'] = 63;
}
