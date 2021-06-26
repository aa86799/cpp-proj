//
// Created by austin stone on 2021/6/26.
//

#include <iostream>

// 内部c语法
extern "C" {

void test() {
    char s1[] = {"abcd"};
    char s2[] = {"efgh"};
    char s3[20] = {0};

    sprintf(s3, "%s, %s", s1, s2); //输出到 s3
    printf("%s", s3);

    FILE *f = fopen("test-print.txt", "w+"); //文件输出在 build目录下  cmake-build-debug/ 。 或可指定一个绝对目录
    fprintf(f, "%s", s3);
}

}

int main() {
    test();
    return 0;
}
