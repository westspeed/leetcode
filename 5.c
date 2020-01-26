#define MAX_LEN 1000

char *longestPalindrome(char *s)
{
    int resPos = 0;
    int resLen = 0;
    int haveResult[MAX_LEN][MAX_LEN] = {0};

    if (!s) {
        return NULL;
    }

    int totalLen = strlen(s);
    //printf("totalLen=%d\n", totalLen);
    /* 以i为头长度为len的字符串 */
    for (int len = 1; len <= totalLen; len++) {
        for (int i = 0; i < totalLen - len + 1; i++) {
            //printf("s[%d]=%c\n", i, s[i]);
            if ((len == 1) || (len == 2 && s[i] == s[i+1]) ||
                (len > 2 && haveResult[i + 1][len - 3] == 1 && s[i] == s[i + len - 1])) {
                haveResult[i][len - 1] = 1;
                if (len > resLen) {
                    resLen = len;
                    resPos = i;
                }
            } 

            //printf("s[%d]=%c, re[%d][%d]=%d\n", i, s[i],i, len - 1, haveResult[i][len - 1]);
        }
    }

    //printf("respos=%d, resLen=%d\n", resPos, resLen);
    char *output = (char *)malloc((resLen + 1) * sizeof(char));
    if (output == NULL) {
        return NULL;
    }

    memcpy(output, &s[resPos], resLen);
    output[resLen] = '\0';
    return output;
}