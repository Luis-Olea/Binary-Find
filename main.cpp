#include <iostream>
#include <random>
#include <chrono>
#include <functional>

using namespace std;

int arr[1000], sizeArr(0);

void swapData( int& a, int& b)
{
    int aux(a);
    a = b;
    b = aux;
}

void quickSort(const int& leftEdge, const int& rightEdge)
{
    if(leftEdge >= rightEdge)
    {
        return;
    }
    int i(leftEdge), j(rightEdge);
    while(i < j)
    {
        while(i < j and arr[i] <= arr[rightEdge])  /// Pivote
        {
            i++;
        }

        while(i < j and arr[j] >= arr[rightEdge])  /// Pivote
        {
            j--;
        }
        if(i != j)
        {
            swapData(arr[i], arr[j]);
        }
    }
    if(i != rightEdge)
    {
        swapData(arr[i], arr[rightEdge]);
    }

    quickSort(leftEdge, i - 1);
    quickSort(i + 1, rightEdge);
}

void generateArr()
{
    system("cls");
    cout << "\n\n\n\n\t\t\t\t|--<<--<<--<<--<<---< | GENERAR ARREGLO | >--->>-->>-->>-->>--|\n\n\n\t\t\t\tINGRESE EL TAMANIO --> ";
    fflush(stdin);
    cin >> sizeArr;

    if(sizeArr > 999)
    {
        sizeArr = 999;
        cout << "\n\n\n\n\t\t\t\tTAMANIO MAXIMO 999";
    }

    default_random_engine generador(chrono::system_clock::now().time_since_epoch().count());
    uniform_int_distribution <int> distribucion(1,999);
    auto randomNum = bind(distribucion, generador);

    for(int aux(0); aux < sizeArr; aux++)
    {
        arr[aux] = randomNum();
    }

    quickSort(0, sizeArr-1);

    cout << "\n\n\t\t\t\t|--<<--<<--<<--<<---< | ARREGLO GENERADO Y ORDENADO | >--->>-->>-->>-->>--|\n\n\n\t\t\t\t";
    system("pause");
    return;
}

void viewArr()
{
    system("cls");
    cout << "\n\n\n\n\t\t\t\t|--<<--<<--<<--<<---< | MOSTRAR | >--->>-->>-->>-->>--|\n\n";

    for(int aux(0); aux < sizeArr; aux++)
    {
        cout << "\n\t\t\t\t\tPOSICION [" << aux << "]: " << arr[aux];
    }
    cout << "\n\n\t\t\t\t|--<<--<<--<<--<<---<<>>--->>-->>-->>-->>--|\n\n\n\t\t\t\t";
    system("pause");
    return;
}


int binaryFindData(int l, int r, int x)
{
    if (r >= l)
    {
        int mid = l + (r - l) / 2;

        if (arr[mid] == x) {
            return mid;
        }

        if (arr[mid] > x) {
            return binaryFindData(l, mid - 1, x);
        }
        return binaryFindData(mid + 1, r, x);
    }
    return -1;
}

void findData()
{
    int aux(0);
    system("cls");
    cout << "\n\n\n\n\t\t\t\t|--<<--<<--<<--<<---< | BUSQUEDA BINARIA | >--->>-->>-->>-->>--|\n\n\n\t\t\t\tINGRESE EL NUMERO A BUSCAR --> ";
    fflush(stdin);
    cin >> aux;

    aux = binaryFindData(0, sizeArr-1, aux);

    if(aux == -1)
    {
        cout << "\n\n\t\t\t\t|--<<--<<--<<--<<---< | NO SE ENCONTRO EL NUMERO | >--->>-->>-->>-->>--|\n\n\n\t\t\t\t";
    }
    else
    {
        cout << "\n\n\t\t\t\tSE ENCONTRO EL REGISTO EN POSICION [" << aux << "]: " << arr[aux] << "\n\n\n\t\t\t\t|--<<--<<--<<--<<---<<>>--->>-->>-->>-->>--|\n\n\n\t\t\t\t";
    }
    system("pause");
    return;
}

void menu()
{

    char v1;
    system("cls");
    cout << "\n\n\n\n\t\t\t\t|--<<--<<--<<--<<---< | BUSQUEDA BINARIA | >--->>-->>-->>-->>--|\n\n\n\t\t\t\tGENERAR UN ARREGLO\t[1]\n\n\t\t\t\tMOSTRAR ARREGLO\t\t[2]\n\n\t\t\t\tBUSCAR\t\t\t[3]\n\n\t\t\t\tSALIR\t\t\t[4]\n\n\n\t\t\t\t|--<<--<<--<<--<<---< | <<-<>->> | >--->>-->>-->>-->>--|\n\n\t\t\t\tINGRESE LA OPCION DESEADA --> ";

    cin >> v1;

    switch (v1)
    {

    case '1':
        generateArr();
        break;

    case '2':
        viewArr();
        break;

    case '3':
        findData();
        break;

    case '4':
        exit(0);
        break;

    default:
        break;
    }
    menu();
}

int main()
{
    menu();
    return 0;
}
