/* Match runtime exception type encodings and recover a base-class offset. */
int fn_803F07E0(const char* thrown, const char* caught, int* offset) {
    const char* source;
    const char* match = caught;

    *offset = 0;
    if (caught == 0) {
        return 1;
    }
    source = thrown;
    if (*caught == 'P') {
        match++;
        if (*match == 'C') {
            match++;
        }
        if (*match == 'V') {
            match++;
        }
        if (*match == 'v' && (*thrown == 'P' || *thrown == '*')) {
            return 1;
        }
        match = caught;
    }

    switch (*thrown) {
    case '*':
    case '!':
        if (*source++ != *match++) {
            return 0;
        }
        for (;;) {
            if (*source == *match++) {
                if (*source++ == '!') {
                    int displacement = 0;
                    while (*source != '!') {
                        displacement = displacement * 10 + *source++ - '0';
                    }
                    *offset = displacement;
                    return 1;
                }
            } else {
                while (*source++ != '!') {}
                while (*source++ != '!') {}
                if (*source == 0) {
                    return 0;
                }
                match = caught + 1;
            }
        }
    }

    while ((*source == 'P' || *source == 'R') && *source == *match) {
        source++;
        match++;
        if (*match == 'C') {
            if (*source == 'C') {
                source++;
            }
            match++;
        }
        if (*source == 'C') {
            return 0;
        }
        if (*match == 'V') {
            if (*source == 'V') {
                source++;
            }
            match++;
        }
        if (*source == 'V') {
            return 0;
        }
    }
    while (*source == *match) {
        if (*source == 0) {
            return 1;
        }
        source++;
        match++;
    }
    return 0;
}
