#include <iostream>

using namespace std;

struct Node
{
    int value;
    Node* p_next; // Нодовые указатели нна след и пред элемент
    Node* p_prev;
};

Node* init(int value);

void print_list(Node* p_first);
void addTo(Node*p_first);
void del_pos(Node* p_cur, int index);
int get_size(Node* p_first);
void del_end(Node* p_cur);
void del2(Node* p_first, int new_size);
int find(Node* p_first, int value);
int main()
{
    setlocale(LC_ALL, "rus");

    cout << " Двусвязный список - добавление нового элемента, удаление" << endl;
    cout << " элемента, удаление элемента и всей последующей части списка, поиск" << endl;
    cout << "Двусвязный список - добавление нового элемента, удаление" << endl;

    Node* list = init(0); //создание первой ноды
    print_list(list); //вывод всего списка
    
    cout << " Добавление однной ноды: ";

    addTo(list);// добавление нового элемента
    print_list(list);

    cout << " Добавление нескольких нод" << endl;
    cout << " Сколько нод вы хотите добавить? ";
    int colVo;
    cin >> colVo;
    for (int i = 0; i < colVo; i++)
    {
        cout << " Введите число: ";
        
        addTo(list);
    }
    cout << " Текущий список: ";
    print_list(list);
    cout << endl;

    //удаление элемента
    cout << " Введите индекс ноды, которую надо удалить: ";
    int index;
    cin >> index;
    del_pos(list, index);
    print_list(list);

    //удаление элемента и последующей части списка
    cout << " Введите индекс ноды: ";
    cin >> index;
    del2(list, index);
    print_list(list);
    // поиск элемента по его значению
    int value;
    cout << " Введите значение элемента, индекс которого надо найти: ";
    cin >> value;
    index = find(list, value);
    cout << " Индекс элемента со значением: " << value << " равен: " << index << endl;
	return 0;
}


int find(Node* p_first, int value)
{
    int size = get_size(p_first);
    int index = 0;
    while (true)
    {
        
        if ((p_first->value == value) )
        {
            break;
        }
        index++;
        p_first = p_first->p_next;
    }
    return index;
}

void del_end(Node* p_cur)
{
    while (true)
    {
        if (p_cur->p_next == 0)
        {
            break;
        }
        p_cur = p_cur->p_next;
    }
    (p_cur->p_prev)->p_next = 0;
    delete p_cur;
}

void del2(Node* p_first, int new_size)
{
    if (new_size <= 0)
    {
        cout << "Wrong new size!" << endl;
        return;
    }

    int cur_size = get_size(p_first);

    int diff = new_size - cur_size;

    if (diff < 0)
    {
        for (int i = 0; i < -diff; i++)
        {
            del_end(p_first);
        }
    }
}

int get_size(Node* p_first)
{
    int size = 1;

    while (true)
    {
        if (p_first->p_next == 0)
        {
            break;
        }
        p_first = p_first->p_next;
        size++;
    }

    return size;
}

void del_pos(Node* p_cur, int index)
{

    int size = get_size(p_cur);
    if ((index >= size) || (index < 0))
    {
        cout << "Out of range!" << endl;
        return;
    }
    if (index == 0)
    {
        Node* deletable = p_cur->p_next;
        p_cur->value = (p_cur->p_next)->value;
        if ((p_cur->p_next)->p_next != 0)
        {
            p_cur->p_next = (p_cur->p_next)->p_next;
            (p_cur->p_next)->p_prev = p_cur;
        }
        delete deletable;
        return;
    }
    if (index == (size - 1))
    {
        while (true)
        {
            if (p_cur->p_next == 0)
            {
                break;
            }
            p_cur = p_cur->p_next;
        }
        p_cur = p_cur->p_prev;
        delete p_cur->p_next;
        p_cur->p_next = 0;
        return;
    }
    int i = 1;
    p_cur = p_cur->p_next;
    while (true)
    {
        if (i == index)
        {
            (p_cur->p_next)->p_prev = p_cur->p_prev;
            (p_cur->p_prev)->p_next = p_cur->p_next;
            delete p_cur;
            return;
        }
        p_cur = p_cur->p_next;
        i++;
    }
}

void addTo(Node* p_cur)
{
    int value;
    

    cin >> value;
    while (true)
    {
        if (p_cur->p_next == 0)
        {
            break;
        }
        p_cur = p_cur->p_next;
    }

    Node* part = new Node;

    part->value = value;
    part->p_next = 0;
    part->p_prev = p_cur;
    p_cur->p_next = part;
}

Node* init(int value) // создание первой ноды возвращает указатель на первую ячейку этой структуры
{
    Node* part = new Node; // new - выделяет память и возвращает указатель на парт -> получить доступ к полю

    part->value = value; // указатели на след и пред равны 0
    part->p_next = 0;
    part->p_prev = 0;

    return part;
}

void print_list(Node* p_first)
{
    cout << '{';
    while (true)
    {
        cout << p_first->value;
        if (p_first->p_next == 0)
        {
            break;
        }
        else
        {
            cout << ", ";
        }
        p_first = p_first->p_next;
    }
    cout << "}\n";
}
