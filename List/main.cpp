#include "List.h"
#include "List.cpp"

int main()
{
    List<int> lst;

    std::cout << "---------------------------" << std::endl;
    std::cout << "Insert Tests" << std::endl;
    std::cout << "---------------------------" << std::endl;
    for (int i = 1; i< 6; i++)
    {
        switch(i)
        {
            case 1:
                std::cout << "test:Insert in empty list:" << std::endl;
                lst.Insert(i,i);
                for (int j = 1; j< lst.list_size+1; j++) lst.Print(j);
                break;
            case 2:
                std::cout << "test:Insert head:" << std::endl;
                lst.Add_head(i);
                for (int j = 1; j< lst.list_size+1; j++) lst.Print(j);
                break;
            case 3:
                std::cout << "test:Insert tail:" << std::endl;
                lst.Add_tail(i);
                for (int j = 1; j< lst.list_size+1; j++) lst.Print(j);
                break;
            case 4:
                std::cout << "test:Insert in some pos:" << std::endl;
                lst.Insert(i,i);
                for (int j = 1; j< lst.list_size+1; j++) lst.Print(j);
                break;
            case 5:
                std::cout << "test:Insert in some incorrect pos: ";
                lst.Insert(-1,i);
                for (int j = 1; j< lst.list_size+1; j++) lst.Print(j);
                break;
            default:
                break;
        }
    }

    std::cout << "---------------------------" << std::endl;
    std::cout << "Swap Tests" << std::endl;
    std::cout << "---------------------------" << std::endl;
    for (int i = 1; i < 5; i++)
    {
        switch (i)
        {
            case 1:
                std::cout << "test:swap 2 and 1:" << std::endl;
                lst.swap(2, 1);
                for (int j = 1; j< lst.list_size+1; j++) lst.Print(j);
                break;
            case 2:
                std::cout << "test:swap 2 and 3:" << std::endl;
                lst.swap(2, 3);
                for (int j = 1; j< lst.list_size+1; j++) lst.Print(j);
                break;
            case 3:
                std::cout << "test:swap 1 and 1:" << std::endl;
                lst.swap(1,1);
                for (int j = 1; j< lst.list_size+1; j++) lst.Print(j);
                break;
            case 4:
                std::cout << "test:swap -1 and 1: ";
                lst.swap(-1,1);
                for (int j = 1; j< lst.list_size+1; j++) lst.Print(j);
                break;
            default:
                break;
        }
    }

    std::cout << "---------------------------" << std::endl;
    std::cout << "<Mergesort Test" << std::endl;
    std::cout << "---------------------------" << std::endl;
    lst.mergesort(&lst.head);
    for (int j = 1; j< lst.list_size+1; j++) lst.Print(j);

    std::cout << "---------------------------" << std::endl;
    std::cout << "Delete Tests" << std::endl;
    std::cout << "---------------------------" << std::endl;
    for (int i = 1; i < 6; i++)
    {
        switch(i)
        {
            case 1:
                std::cout << "test: delete first" << std::endl;
                lst.Del(1);
                for (int j = 1; j< lst.list_size+1; j++) lst.Print(j);
                break;
            case 2:
                std::cout << "test: delete new first" << std::endl;
                lst.Del(1);
                for (int j = 1; j< lst.list_size+1; j++) lst.Print(j);
                break;
            case 3:
                std::cout << "test: delete last" << std::endl;
                lst.Del(lst.list_size);
                for (int j = 1; j< lst.list_size+1; j++) lst.Print(j);
                break;
            case 4:
                std::cout << "test: delete new last" << std::endl;
                lst.Del(lst.list_size);
                for (int j = 1; j< lst.list_size+1; j++) lst.Print(j);
                break;
            case 5:
                std::cout << "test: delete deleted item: ";
                lst.Del(lst.list_size);
                for (int j = 1; j< lst.list_size+1; j++) lst.Print(j);
            default:
                break;
        }
    }

    return 0;
}
