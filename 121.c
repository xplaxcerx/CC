#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <string.h>
#include <stdio_ext.h>

int mygetch()
{
    struct termios oldt, newt;
    int c;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    c = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return c;
}

typedef struct Club
{
    char *name;
    char *adress;
    char *theme;
    int openingHour;
    int openingMinute;
    int closingHour;
    int closingMinute;
    int workingTime;
} data;

// int findAndPrintClub(data data[], int data_size)
// {

//     printf("%s\n", data[0].name);
// }

int addClub(data *element, int data_size)
{
    __fpurge(stdin);
    char *name = malloc(100);
    char *adress = malloc(100);
    char *theme = malloc(100);
    int workingTime = 0;

    int openingHour;
    int openingMinute;
    int closingHour;
    int closingMinute;

    printf("Название: ");
    fgets(name, 100, stdin);
    name[strlen(name) - 1] = '\0';

    printf("Адрес: ");
    fgets(adress, 100, stdin);
    adress[strlen(adress) - 1] = '\0';

    printf("Тематика: ");
    fgets(theme, 100, stdin);
    theme[strlen(theme) - 1] = '\0';

    printf("Время открытия: ");
    scanf("%d %d", &openingHour, &openingMinute);

    printf("Время закрытия: ");
    scanf("%d %d", &closingHour, &closingMinute);

    int tmpTime = closingHour * 60 + closingMinute - openingHour * 60 - openingMinute;

    (*element).name = name;
    (*element).adress = adress;
    (*element).theme = theme;
    (*element).openingHour = openingHour;
    (*element).openingMinute = openingMinute;
    (*element).closingHour = closingHour;
    (*element).closingMinute = closingMinute;
    (*element).workingTime = tmpTime;
    data_size++;
    return data_size;
}

void printClubData(data element)
{
    printf("| %-19s| %-14s| %-7s| %1d ",
           element.name, element.adress,
           element.theme, element.workingTime);
}

void printAllData(data data[], int data_size)
{
    printf("ID | Название\t| Адрес| Тема | Время работы\n");
    for (int i = 0; i < data_size; i++)
    {
        printf("%2i ", i);
        printClubData(data[i]);
        printf("\n");
    }
}

int removeClub(data *element, int data_size)
{
    free(element->name);
    free(element->adress);
    free(element->theme);
    element->workingTime = 0;
    return data_size - 1;
}

void changeClub(data *element)
{
    removeClub(element, 0);
    addClub(element, 0);
}

int loadData(data data[])
{
    FILE *file = fopen("clubs.txt", "r");
    int size;
    fscanf(file, "%d\n", &size);

    for (int i = 0; i < size; i++)
    {
        char *name = malloc(100);
        char *adress = malloc(100);
        char *theme = malloc(100);
        int workingTime = 0;

        int openingHour;
        int openingMinute;
        int closingHour;
        int closingMinute;

        fgets(name, 100, file);
        fgets(adress, 100, file);
        fgets(theme, 100, file);
        fscanf(file, "%d %d", &openingHour, &openingMinute);
        fscanf(file, "%d %d", &closingHour, &closingMinute);

        name[strlen(name) - 1] = '\0';
        adress[strlen(adress) - 1] = '\0';
        theme[strlen(theme) - 1] = '\0';
        int tmpTime = closingHour * 60 + closingMinute - openingHour * 60 - openingMinute;

        data[i].name = name;
        data[i].adress = adress;
        data[i].theme = theme;
        data[i].openingHour = openingHour;
        data[i].openingMinute = openingMinute;
        data[i].closingHour = closingHour;
        data[i].closingMinute = closingMinute;
        data[i].workingTime = tmpTime;
    }

    fclose(file);
    return size;
}

void save(data data[], int size)
{
    FILE *file = fopen("clubs.txt", "w");
    fprintf(file, "%d\n", size);
    for (int i = 0; i < size; i++)
    {
        fprintf(file, "%s\n%s\n%s\n %d %d %d %d",
                data[i].name, data[i].adress, data[i].theme,
                data[i].openingHour, data[i].openingMinute, data[i].closingHour, data[i].closingMinute);
    }
    fclose(file);
}

int main()
{
    data data[100];
    int data_size = loadData(data);
    int changed;
    int removed;

    while (1)
    {
        printf("[1] - добавить  клуб\n[2] - вывести все клубы\n"
               "[3] - вывести клуб с караоке и самой большой длительностью работы\n[4] - изменить данные клуба\n"
               "[5] - удалить клуб\n[q] - выход\n>");
        char key = mygetch();
        printf("\n");
        int a = 0;
        int flag = 0;
        switch (key)
        {
        case '1':
            data_size = addClub(&data[data_size], data_size);
            break;
        case '2':
            printAllData(data, data_size);
            break;
        case '3':
            while (a < data_size)
            {
                if (*(data[a].theme) == 'K' || *(data[a].theme) == 'k')
                {
                    for (int j = 0; j < data_size; j++)
                    {
                        if ((*(data[j].theme) == 'K' || *(data[j].theme) == 'k') && data[a].workingTime < data[j].workingTime)
                        {
                            a = j;
                        }
                        if (j == data_size - 1)
                        {
                            printf("ID | Название\t\t| Адрес| Тема | Время работы\n");
                            printf("%s %s %s %d \n", data[a].name, data[a].adress, data[a].theme, data[a].workingTime);
                            flag = 1;
                            break;
                        }
                    }
                }
                a++;
                if (flag == 1)
                    break;
                else if (a == data_size - 1)
                    printf("Нет клуба с караоке");
            }
            break;
        case '4':
            printAllData(data, data_size);
            printf("Номер изменяемого клуба: ");
            scanf("%d", &changed);
            if (changed < data_size && changed >= 0)
                changeClub(&data[changed]);
            break;
        case '5':
            printAllData(data, data_size);
            printf("Номер удаляемого клуба: ");
            scanf("%d", &removed);
            if (removed < data_size && removed >= 0)
            {
                data_size = removeClub(&data[removed], data_size);
                for (int i = removed; i < data_size; i++)
                    data[i] = data[i + 1];
            }
            break;
        case 'q':
            save(data, data_size);
            return 0;
            break;
        case '\n':
            break;
        default:
            printf("Неизвестная команда\n");
            break;
        }
    }
}