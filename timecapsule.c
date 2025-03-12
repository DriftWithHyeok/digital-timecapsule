#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file = fopen("messages.csv", "a");
    if (file == NULL) {
        printf("파일을 열 수 없습니다.\n");
        return 1;
    }

    char name[50], message[200];

    printf("이름을 입력하세요: ");
    fgets(name, sizeof(name), stdin); // 전체 이름 입력 받기
    name[strcspn(name, "\n")] = 0; // 개행 문자 제거

    printf("미래의 나에게 메시지를 입력하세요: ");
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\n")] = 0; // 개행 문자 제거

    fprintf(file, "%s,%s\n", name, message);
    fclose(file);

    printf("메시지가 저장되었습니다!\n");

    return 0;
}
