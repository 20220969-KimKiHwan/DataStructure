int main() {
    char *str;
    char *stack;
    int top = -1;
    int i = 0;
    int valid = 1;

    str = (char *)malloc(sizeof(char) * 101);
    if (str == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    stack = (char *)malloc(sizeof(char) * 101);
    if (stack == NULL) {
        printf("Memory allocation failed\n");
        free(str);
        return 1;
    }

    printf("문자열을 입력하세요: ");
    fgets(str, 101, stdin);

    while (str[i] != '\0' && str[i] != '\n') {
        char ch = str[i];

        if (ch == '(' || ch == '{' || ch == '[') {
            stack[++top] = ch;
        }
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (top == -1) {
                valid = 0;
                break;
            }

            char open = stack[top--];

            if ((ch == ')' && open != '(') ||
                (ch == '}' && open != '{') ||
                (ch == ']' && open != '[')) {
                valid = 0;
                break;
            }
        }

        i++;
    }

    if (top != -1) {
        valid = 0;
    }

    if (valid)
        printf("유효한 괄호\n");
    else
        printf("유효하지 않은 괄호\n");

    free(str);
    free(stack);

    return 0;
}