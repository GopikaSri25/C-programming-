#define R(name, rule) \
int match_##name(char *s, int ptr) { \
    rule; \
}

#define M(match, success, fail) \
    do { \
        int newptr = match_##match(s, ptr); \
        if (newptr >= 0) { \
            ptr = newptr; \
            success; \
        } \
        else { \
            fail; \
        } \
        return -1; \
    } while (0)

#define L(match, success, fail) \
    do { \
        if (s[ptr] == match) { \
            ++ptr; \
            success; \
        } \
        else { \
            fail; \
        } \
        return -1; \
    } while (0)

#define S return ptr
#define F return -1

R(digit,
  L('0', S,
  L('1', S,
  L('2', S,
  L('3', S,
  L('4', S,
  L('5', S,
  L('6', S,
  L('7', S,
  L('8', S,
  L('9', S, F
)))))))))))

R(digseq, M(digit, M(digseq, S, S), F))

R(integer,
  L('+', M(digseq, S, F),
  L('-', M(digseq, S, F),
         M(digseq, S, F))))

R(decimal_number_value,
  M(digseq, L('.', M(digseq, S, S), F),
  L('.', M(digseq, S, F), F)))

R(decimal_number,
  L('+', M(decimal_number_value, S, F),
  L('-', M(decimal_number_value, S, F),
         M(decimal_number_value, S, F))))

R(exppart,
  L('e', M(integer, S, F),
  L('E', M(integer, S, F),
  F)))

R(number,
  M(decimal_number, M(exppart, S, S),
  M(integer, M(exppart, S, S), F)
))

bool isNumber(char* s) {
    int ptr = match_number(s, 0);
    return ptr >= 0 && ptr[s] == '\0';
}
