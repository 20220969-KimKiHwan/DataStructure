int main() {
    char *str;
    char *stack;
    int top = -1;
    int i = 0;

    str = (char *)malloc(sizeof(char) * 101);
    if (str == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("문자열을 입력하세요: ");
    fgets(str, 101, stdin);

    stack = (char *)malloc(sizeof(char) * 101);
    if (stack == NULL) {
        printf("Memory allocation failed\n");
        free(str);
        return 1;
    }

    while (str[i] != '\0' && str[i] != '\n') {
        stack[++top] = str[i];
        i++;
    }

    printf("거꾸로 출력된 문자열: ");
    while (top != -1) {
        printf("%c", stack[top--]);
    }
    printf("\n");

    free(str);
    free(stack);

    return 0;
}