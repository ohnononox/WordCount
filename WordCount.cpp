/*Fir:2021/5/3  END:--
要求：程序统计文本文件（纯英文）的字符数或者单词数。空格，水平制表符，
换行符均算字符。由空格或逗号分割开的都视为单词，且不做单词的有效性校验，
例如：thi#,that视为用逗号隔开的2个单词
-c字符数
-w单词数
*/
//作者：夏景陶 --2021/5/3
#include<stdio.h>
#include<string.h>

int main(int argc, char* argv[])
{
    int i = 0, flag = 0, iseof = 1;
    char temp[50];
    if (argc != 3)
    {
        printf("请按照规定格式");
        return 0;
    }

    FILE* fp;
    errno_t err = fopen_s(&fp, argv[2], "r+");
    iseof = fgetc(fp);//判空
    rewind(fp);//指回开头
    for (;i < 50;i++)
    {
        fscanf_s(fp, "%c", &temp[i]);
    }
    if (strcmp(argv[1], "-c") == 0 || strcmp(argv[1], "-C") == 0) //统计字符数
    {
        flag = 0;
        for (i = 0;i < 50;i++)
        {
            if (temp[i] == 32 || temp[i] == 9 || temp[i] == 10 || (temp[i] > 32 && temp[i] < 127))
            {
                flag++;
            }
        }
        printf("字符数：%d\n", flag);
    }
    else if (strcmp(argv[1], "-w") == 0 || strcmp(argv[1], "-W") == 0)//统计单词数
    {
        flag = 1;
        for (i = 0;i < 50;i++)
        {
            if (temp[i] == 32 || temp[i] == 44)
            {
                flag++;
            }
        }
        if (iseof == EOF)
        {
            flag = 0;
        }
        printf("单词数：%d", flag);
    }
    fclose(fp);
    getchar();
    return 0;
}